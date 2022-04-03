#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;


Action ComportamientoJugador::think(Sensores sensores){

	Action accion = actIDLE;

	cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC << " ";
	switch(sensores.sentido){
		case 0: cout << "Norte" << endl; break;
		case 1: cout << "Este" << endl; break;
		case 2: cout << "Sur " << endl; break;
		case 3: cout << "Oeste" << endl; break;
	}
	cout << "Terreno: ";
	for (int i=0; i<sensores.terreno.size(); i++)
		cout << sensores.terreno[i];
	cout << endl;

	cout << "Superficie: ";
	for (int i=0; i<sensores.superficie.size(); i++)
		cout << sensores.superficie[i];
	cout << endl;

	cout << "Colisión: " << sensores.colision << endl;
	cout << "Reset: " << sensores.reset << endl;
	cout << "Vida: " << sensores.vida << endl;
	cout << endl;

	// Determinar el efecto de la ultima accion enviada

	switch(ultimaAccion){
		case actFORWARD:
			switch(brujula){
				case 0: fil--; break;
				case 1: col++; break;
				case 2: fil++; break;
				case 3: col--; break;
			}
			break;

		case actTURN_L:
			brujula = (brujula + 3) % 4;
			girar_derecha = (rand() % 2 == 0);
			break;

		case actTURN_R:
			brujula = (brujula + 1) % 4;
			girar_derecha = (rand() % 2 == 0);
			break;	
	}

	if(!bien_situado)
		accion = encontrarCasillaPos(sensores);

	if(sensores.terreno[0] == 'G' and !bien_situado){

		fil = sensores.posF;
		col = sensores.posC;
		bien_situado = true;
	}

	if(bien_situado){

		pintarMapa(sensores);		
		accion = moverse(sensores);
	}

	
	ultimaAccion = accion;
	// if ((sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S') or
	// 	sensores.terreno[2] == 'G' and sensores.superficie[2] == '_') {
	// 		accion = actFORWARD;
	// }
	// else {
	// 		accion = girar(sensores);
	// }

 	// ultimaAccion = accion;	


 
	return accion;
}

void ComportamientoJugador::pintarMapa(Sensores sensores) {

		switch(brujula) {

			case 0:
				mapaResultado[fil][col] = sensores.terreno[0];
				mapaResultado[fil-1][col-1] = sensores.terreno[1];
				mapaResultado[fil-1][col] = sensores.terreno[2];
				mapaResultado[fil-1][col+1] = sensores.terreno[3];
				mapaResultado[fil-2][col-2] = sensores.terreno[4];
				mapaResultado[fil-2][col-1] = sensores.terreno[5];
				mapaResultado[fil-2][col] = sensores.terreno[6];
				mapaResultado[fil-2][col+1] = sensores.terreno[7];
				mapaResultado[fil-2][col+2] = sensores.terreno[8];
				mapaResultado[fil-3][col-3] = sensores.terreno[9];
				mapaResultado[fil-3][col-2] = sensores.terreno[10];
				mapaResultado[fil-3][col-1] = sensores.terreno[11];
				mapaResultado[fil-3][col] = sensores.terreno[12];
				mapaResultado[fil-3][col+1] = sensores.terreno[13];
				mapaResultado[fil-3][col+2] = sensores.terreno[14];
				mapaResultado[fil-3][col+3] = sensores.terreno[15];

			break;

			case 1:
				mapaResultado[fil][col] = sensores.terreno[0];
				mapaResultado[fil-1][col+1] = sensores.terreno[1];
				mapaResultado[fil][col+1] = sensores.terreno[2];
				mapaResultado[fil+1][col+1] = sensores.terreno[3];
				mapaResultado[fil-2][col+2] = sensores.terreno[4];
				mapaResultado[fil-1][col+2] = sensores.terreno[5];
				mapaResultado[fil][col+2] = sensores.terreno[6];
				mapaResultado[fil+1][col+2] = sensores.terreno[7];
				mapaResultado[fil+2][col+2] = sensores.terreno[8];
				mapaResultado[fil-3][col+3] = sensores.terreno[9];
				mapaResultado[fil-2][col+3] = sensores.terreno[10];
				mapaResultado[fil-1][col+3] = sensores.terreno[11];
				mapaResultado[fil][col+3] = sensores.terreno[12];
				mapaResultado[fil+1][col+3] = sensores.terreno[13];
				mapaResultado[fil+2][col+3] = sensores.terreno[14];
				mapaResultado[fil+3][col+3] = sensores.terreno[15];
			break;

			case 2:
				mapaResultado[fil][col] = sensores.terreno[0];
				mapaResultado[fil+1][col+1] = sensores.terreno[1];
				mapaResultado[fil+1][col] = sensores.terreno[2];
				mapaResultado[fil+1][col-1] = sensores.terreno[3];
				mapaResultado[fil+2][col+2] = sensores.terreno[4];
				mapaResultado[fil+2][col+1] = sensores.terreno[5];
				mapaResultado[fil+2][col] = sensores.terreno[6];
				mapaResultado[fil+2][col-1] = sensores.terreno[7];
				mapaResultado[fil+2][col-2] = sensores.terreno[8];
				mapaResultado[fil+3][col+3] = sensores.terreno[9];
				mapaResultado[fil+3][col+2] = sensores.terreno[10];
				mapaResultado[fil+3][col+1] = sensores.terreno[11];
				mapaResultado[fil+3][col] = sensores.terreno[12];
				mapaResultado[fil+3][col-1] = sensores.terreno[13];
				mapaResultado[fil+3][col-2] = sensores.terreno[14];
				mapaResultado[fil+3][col-3] = sensores.terreno[15];
			break;

			case 3:
				mapaResultado[fil][col] = sensores.terreno[0];
				mapaResultado[fil+1][col-1] = sensores.terreno[1];
				mapaResultado[fil][col-1] = sensores.terreno[2];
				mapaResultado[fil-1][col-1] = sensores.terreno[3];
				mapaResultado[fil+2][col-2] = sensores.terreno[4];
				mapaResultado[fil+1][col-2] = sensores.terreno[5];
				mapaResultado[fil][col-2] = sensores.terreno[6];
				mapaResultado[fil-1][col-2] = sensores.terreno[7];
				mapaResultado[fil-2][col-2] = sensores.terreno[8];
				mapaResultado[fil+3][col-3] = sensores.terreno[9];
				mapaResultado[fil+2][col-3] = sensores.terreno[10];
				mapaResultado[fil+1][col-3] = sensores.terreno[11];
				mapaResultado[fil][col-3] = sensores.terreno[12];
				mapaResultado[fil-1][col-3] = sensores.terreno[13];
				mapaResultado[fil-2][col-3] = sensores.terreno[14];
				mapaResultado[fil-3][col-3] = sensores.terreno[15];
			break;
		}
}

// Action ComportamientoJugador::moverse(Sensores sensores) {

//     Action accion;

//     if(sensores.terreno[0] == 'K') bikini = true;
//     if(sensores.terreno[0] == 'D') zapatillas = true;

//     switch(brujula){

//         case 0:

//             if(mapaResultado[fil][col-1] == '?' ){

//                 accion = actTURN_L;
//             }
//             else if(mapaResultado[fil][col+1] == '?' ){

//                 accion = actTURN_R;
//             }        
            
//         break;

//         case 1:

//             if(mapaResultado[fil-1][col] == '?' ){

//                 accion = actTURN_L;
//             }
//             else if(mapaResultado[fil+1][col] == '?' ){

//                 accion = actTURN_R;
//             }        
            
//         break;
        
//         case 2:

//             if(mapaResultado[fil][col-1] == '?' ){

//                 accion = actTURN_R;
//             }
//             else if(mapaResultado[fil][col+1] == '?' ){

//                 accion = actTURN_L;
//             }        

//         break;

//         case 3:

//             if(mapaResultado[fil-1][col] == '?' ){

//                 accion = actTURN_R;
//             }
//             else if(mapaResultado[fil+1][col] == '?' ){

//                 accion = actTURN_L;
//             }        

//         break;

//         default:

//             if(sensores.terreno[2] != 'P' && (sensores.terreno[2] != 'B' || zapatillas)
//                 && (sensores.terreno[2] != 'A' || bikini) && sensores.terreno[2] != 'M') {

//                 if(pasos_a_andar < 10) {
//                     accion = actFORWARD;
//                     pasos_a_andar++;
//                 }
//                 else{

//                     accion = girar();
//                     pasos_a_andar = 0;            
//                 }

//             }
//             else {

//                 accion = girar();
//             }         
//     }

//     return accion;

// }

Action ComportamientoJugador::moverse(Sensores sensores) {

	Action accion;

	if(sensores.terreno[0] == 'K') bikini = true;
	if(sensores.terreno[0] == 'D') zapatillas = true;

	if(sensores.terreno[2] != 'P' && (sensores.terreno[2] != 'B' || zapatillas)
		&& (sensores.terreno[2] != 'A' || bikini) && sensores.terreno[2] != 'M') {

		if(pasos_a_andar < 10) {
			accion = actFORWARD;
			pasos_a_andar++;
		}
		else{

			accion = girar();
			pasos_a_andar = 0;			
		}

	}
	else {

		accion = girar();
	} 

	return accion;

}

Action ComportamientoJugador::seguir_muro(Sensores sensores) {

	Action accion;

	if(sensores.terreno[2] == 'M') {

			accion = girar();

	}

	return accion;
}

Action ComportamientoJugador::girar() {

	Action accion;

	if(!girar_derecha) {

		accion = actTURN_L;
		girar_derecha = (rand() % 2 == 0);
		
	}
	else {

		accion = actTURN_R;
		girar_derecha = (rand() % 2 == 0);
		
	}

	return accion;

}

// bool ComportamientoJugador::veoCasilla(Sensores sensores, char buscar) {

// 	Action accion;

// 	for(int i = 0; i < sensores.terreno.size() && !encontrada; i++) {

// 		if(sensores.terreno[i] == buscar){
				
// 			encontrada = true;
// 		}
// 	}

// 	return encontrada;

// }

bool ComportamientoJugador::veoCasilla(Sensores sensores, char buscar) {

	for(int i = 0; i < sensores.terreno.size() && !encontrada; i++) {

		if(sensores.terreno[i] == buscar){
				
			encontrada = true;
		}
	}

	return encontrada;
}

Action ComportamientoJugador::encontrarCasillaPos(Sensores sensores) {

	if(!bien_situado) {

		Action accion = actIDLE;
		int casilla;
		
		for(int i = 0; i < sensores.terreno.size() && !encontrada; i++) {

			if(sensores.terreno[i] == 'G'){
				
				casilla = i;
				encontrada = true;
			}
		}

		if(encontrada) {

			cout << "He visto la casilla pos" << endl;
			if(casilla == 2 || casilla == 6 || casilla == 12) {

				cout << "La he visto enfrente" << endl;
				recto = true;
			}
			else if(casilla == 1 || casilla == 5 || casilla == 11 || casilla == 4 || casilla == 10 || casilla == 9){

				cout << "La he visto encima mia" << endl;
				arriba = true;
			}
			else if(casilla == 3 || casilla == 7 || casilla == 13 || casilla == 8 || casilla == 14 || casilla == 15){

				cout << "La he visto debajo mia" << endl;
				abajo = true;
			}

			if(recto){

				accion = actFORWARD;
				encontrada = false;
				recto = false;
			}
			else if(arriba) {

				if(ultimaAccion == actTURN_L && gira_bien) {

					accion = actFORWARD;
				}
				else if(ultimaAccion == actFORWARD && gira_bien) {

					accion = actTURN_R;
				}
				else if(ultimaAccion == actTURN_R && gira_bien){

					encontrada = false;
					arriba = false;
					gira_bien = false;
				}
				else {

					accion = actTURN_L;
					gira_bien = true;
				}
				
			}
			else if(abajo){

				if(ultimaAccion == actTURN_R && gira_bien) {

					accion = actFORWARD;
				}
				else if(ultimaAccion == actFORWARD && gira_bien) {

					accion = actTURN_L;
				}
				else if(ultimaAccion == actTURN_L && gira_bien){

					encontrada = false;
					abajo = false;
					gira_bien = false;
				}
				else {

					accion = actTURN_R;
					gira_bien = true;
				}
			}
		}
		else {
			accion = moverse(sensores);
		}

		return accion;
	}
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}