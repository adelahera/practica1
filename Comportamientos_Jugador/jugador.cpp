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

	if(sensores.reset){
			
		cout << "Acabo de morir" << endl;
		reseteaVariables();
	}	

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
			//girar_derecha = (rand() % 2 == 0);
			break;

		case actTURN_R:
			brujula = (brujula + 1) % 4;
			//girar_derecha = (rand() % 2 == 0);
			break;	
	}	

	

	if(sensores.terreno[0] == 'G' and !bien_situado){

		fil = sensores.posF;
		col = sensores.posC;
		bien_situado = true;
		trasponerMapaAuxiliar();
	}

	if(!bien_situado) {
		switch(brujula) {

			case 0:
				matriz_aux[fil_aux][col_aux] = sensores.terreno[0];
				matriz_aux[fil_aux-1][col_aux-1] = sensores.terreno[1];
				matriz_aux[fil_aux-1][col_aux] = sensores.terreno[2];
				matriz_aux[fil_aux-1][col_aux+1] = sensores.terreno[3];
				matriz_aux[fil_aux-2][col_aux-2] = sensores.terreno[4];
				matriz_aux[fil_aux-2][col_aux-1] = sensores.terreno[5];
				matriz_aux[fil_aux-2][col_aux] = sensores.terreno[6];
				matriz_aux[fil_aux-2][col_aux+1] = sensores.terreno[7];
				matriz_aux[fil_aux-2][col_aux+2] = sensores.terreno[8];
				matriz_aux[fil_aux-3][col_aux-3] = sensores.terreno[9];
				matriz_aux[fil_aux-3][col_aux-2] = sensores.terreno[10];
				matriz_aux[fil_aux-3][col_aux-1] = sensores.terreno[11];
				matriz_aux[fil_aux-3][col_aux] = sensores.terreno[12];
				matriz_aux[fil_aux-3][col_aux+1] = sensores.terreno[13];
				matriz_aux[fil_aux-3][col_aux+2] = sensores.terreno[14];
				matriz_aux[fil_aux-3][col_aux+3] = sensores.terreno[15];

			break;

			case 1:
				matriz_aux[fil_aux][col_aux] = sensores.terreno[0];
				matriz_aux[fil_aux-1][col_aux+1] = sensores.terreno[1];
				matriz_aux[fil_aux][col_aux+1] = sensores.terreno[2];
				matriz_aux[fil_aux+1][col_aux+1] = sensores.terreno[3];
				matriz_aux[fil_aux-2][col_aux+2] = sensores.terreno[4];
				matriz_aux[fil_aux-1][col_aux+2] = sensores.terreno[5];
				matriz_aux[fil_aux][col_aux+2] = sensores.terreno[6];
				matriz_aux[fil_aux+1][col_aux+2] = sensores.terreno[7];
				matriz_aux[fil_aux+2][col_aux+2] = sensores.terreno[8];
				matriz_aux[fil_aux-3][col_aux+3] = sensores.terreno[9];
				matriz_aux[fil_aux-2][col_aux+3] = sensores.terreno[10];
				matriz_aux[fil_aux-1][col_aux+3] = sensores.terreno[11];
				matriz_aux[fil_aux][col_aux+3] = sensores.terreno[12];
				matriz_aux[fil_aux+1][col_aux+3] = sensores.terreno[13];
				matriz_aux[fil_aux+2][col_aux+3] = sensores.terreno[14];
				matriz_aux[fil_aux+3][col_aux+3] = sensores.terreno[15];
			break;

			case 2:
				matriz_aux[fil_aux][col_aux] = sensores.terreno[0];
				matriz_aux[fil_aux+1][col_aux+1] = sensores.terreno[1];
				matriz_aux[fil_aux+1][col_aux] = sensores.terreno[2];
				matriz_aux[fil_aux+1][col_aux-1] = sensores.terreno[3];
				matriz_aux[fil_aux+2][col_aux+2] = sensores.terreno[4];
				matriz_aux[fil_aux+2][col_aux+1] = sensores.terreno[5];
				matriz_aux[fil_aux+2][col_aux] = sensores.terreno[6];
				matriz_aux[fil_aux+2][col_aux-1] = sensores.terreno[7];
				matriz_aux[fil_aux+2][col_aux-2] = sensores.terreno[8];
				matriz_aux[fil_aux+3][col_aux+3] = sensores.terreno[9];
				matriz_aux[fil_aux+3][col_aux+2] = sensores.terreno[10];
				matriz_aux[fil_aux+3][col_aux+1] = sensores.terreno[11];
				matriz_aux[fil_aux+3][col_aux] = sensores.terreno[12];
				matriz_aux[fil_aux+3][col_aux-1] = sensores.terreno[13];
				matriz_aux[fil_aux+3][col_aux-2] = sensores.terreno[14];
				matriz_aux[fil_aux+3][col_aux-3] = sensores.terreno[15];
			break;

			case 3:
				matriz_aux[fil_aux][col_aux] = sensores.terreno[0];
				matriz_aux[fil_aux+1][col_aux-1] = sensores.terreno[1];
				matriz_aux[fil_aux][col_aux-1] = sensores.terreno[2];
				matriz_aux[fil_aux-1][col_aux-1] = sensores.terreno[3];
				matriz_aux[fil_aux+2][col_aux-2] = sensores.terreno[4];
				matriz_aux[fil_aux+1][col_aux-2] = sensores.terreno[5];
				matriz_aux[fil_aux][col_aux-2] = sensores.terreno[6];
				matriz_aux[fil_aux-1][col_aux-2] = sensores.terreno[7];
				matriz_aux[fil_aux-2][col_aux-2] = sensores.terreno[8];
				matriz_aux[fil_aux+3][col_aux-3] = sensores.terreno[9];
				matriz_aux[fil_aux+2][col_aux-3] = sensores.terreno[10];
				matriz_aux[fil_aux+1][col_aux-3] = sensores.terreno[11];
				matriz_aux[fil_aux][col_aux-3] = sensores.terreno[12];
				matriz_aux[fil_aux-1][col_aux-3] = sensores.terreno[13];
				matriz_aux[fil_aux-2][col_aux-3] = sensores.terreno[14];
				matriz_aux[fil_aux-3][col_aux-3] = sensores.terreno[15];
			break;
		}

		if(ultimaAccion == actFORWARD) {

			switch(brujula){
				case 0: fil_aux--; break;
				case 1: col_aux++; break;
				case 2: fil_aux++; break;
				case 3: col_aux--; break;
			}			
		}

		if(sensores.reset && (sensores.terreno[0] == 'B' || sensores.terreno[0] == 'A') && (sensores.terreno[2] == 'B' || sensores.terreno[2] == 'A')){
				
				cout << "He nacido en bosque o agua" << endl;
				accion = actFORWARD;
		}	
		else{

			accion = encontrarCasillaPos(sensores);
		}
	}
	if(bien_situado) {

		pintarMapa(sensores);	
		if(!bikini) {
	
			accion = encontrarBikini(sensores);
			
		}	
		else if(!zapatillas){

			accion = encontrarZapatillas(sensores);
		}
		else if(cargando || (sensores.bateria < 2500 && (sensores.vida > 900) || (sensores.bateria < 1250 && sensores.vida > 350))){

			accion = encontrarRecarga(sensores);
		}
		else {

			accion = moverse(sensores);
		}
	}
	ultimaAccion = accion;

	return accion;
}

void ComportamientoJugador::reseteaVariables() {

	fil = col = 99;
    brujula = 0;
	ultimaAccion = actIDLE;
    girar_derecha = false;
    bien_situado = false;
    pasos_a_andar = 0;
    zapatillas = false;
    bikini = false;
    encontrada = false;
    recto = false;
    arriba = false;
    abajo = false;
    gira_bien = false;
    gira_precipicio_derecha = false;
    gira_precipicio_izquierda = false;
    casilla_vista.first = false;
    cargando = false;
    saliendo_agua_bosque = false;
    conocido = false;
	recien_nacido = true;
    casilla_vista.second = -1;
    fil_aux = col_aux = 99;
    ciclos = 0;
	ciclos_recien_nacido = 0;
    pasos_muro = 0;

    for (int i = 0; i < 200; i++) {
      for (int j = 0; j < 200; j++) {
        matriz_aux[i][j] = '?';
      }
    }
}

void ComportamientoJugador::trasponerMapaAuxiliar() {

	int desplazamiento_fils = abs(fil_aux-fil);
	int desplazamiento_cols = abs(col_aux-col);

	for(int i = 0; i < mapaResultado.size(); i++) {
		for(int j = 0; j < mapaResultado.size(); j++) {

			if(matriz_aux[i+desplazamiento_fils][j+desplazamiento_cols] != '?') {

				mapaResultado[i][j] = matriz_aux[i+desplazamiento_fils][j+desplazamiento_cols];

			}
		}
	}
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

Action ComportamientoJugador::moverse(Sensores sensores) {

    Action accion;

    if(sensores.terreno[0] == 'K') bikini = true;
    if(sensores.terreno[0] == 'D') zapatillas = true;

    if(sensores.terreno[2] != 'P' && (sensores.terreno[2] != 'B' || zapatillas)
        && (sensores.terreno[2] != 'A' || bikini) && sensores.terreno[2] != 'M' && sensores.superficie[2] == '_') {

        if(pasos_a_andar < 20) {
            accion = actFORWARD;
            pasos_a_andar++;
        }
        else {

            accion = girar();
            pasos_a_andar = 0;            
        }
    }
	else {

		accion = girar();
	}	

	if(ultimaAccion == actFORWARD && bien_situado && sensores.terreno[2] != 'P' && (sensores.terreno[2] != 'B' || zapatillas)
        && (sensores.terreno[2] != 'A' || bikini) && sensores.terreno[2] != 'M' && sensores.superficie[2] == '_') {

		switch(brujula){

			case 0:

				for (int i = 0; i < 5 && col+i < mapaResultado.size() && col-i >= 0; i++) {

					if(mapaResultado[fil-i][col] == '?'){

						accion = actFORWARD;
					}
					else if(mapaResultado[fil][col-i] == '?'){

						cout << "sitio desconocido a la izquierda mirando al norte" << endl;
						accion = actTURN_L;
					}
					else if(mapaResultado[fil][col+i] == '?' ){

						cout << "sitio desconocido a la derecha mirando al norte" << endl;
						accion = actTURN_R;
					}        

				}
				
			break;

			case 1:

				for (int i = 0; i < 5 && fil+i < mapaResultado.size() && fil-i >= 0; i++) {
					
					if(mapaResultado[fil][col+i] == '?') {

						accion = actFORWARD;
					}	
					else if(mapaResultado[fil-i][col] == '?' ){

						cout << "sitio desconocido a la izquierda mirando al este" << endl;
						accion = actTURN_L;
					}
					else if(mapaResultado[fil+i][col] == '?' ){

						cout << "sitio desconocido a la derecha mirando al este" << endl;
						accion = actTURN_R;
					}        
				}
			break;
			
			case 2:

				for (int i = 0; i < 5 && col+i < mapaResultado.size() && col-i >= 0; i++) {
					
					if(mapaResultado[fil+i][col] == '?') {

						accion = actFORWARD;
					}
					else if(mapaResultado[fil][col-i] == '?' ){

						cout << "sitio desconocido a la izquierda mirando al sur" << endl;
						accion = actTURN_R;
					}
					else if(mapaResultado[fil][col+i] == '?' ){

						cout << "sitio desconocido a la derecha mirando al sur" << endl;
						accion = actTURN_L;
					}  
				}      

			break;

			case 3:

				for (int i = 0; i < 5 && fil+i < mapaResultado.size() && fil-i >= 0; i++) {
					
					if(mapaResultado[fil][col-i] == '?') {

						accion = actFORWARD;
					}
					else if(mapaResultado[fil-i][col] == '?' ){

						cout << "sitio desconocido a la izquierda mirando al oeste" << endl;
						accion = actTURN_R;
					}
					else if(mapaResultado[fil+i][col] == '?' ){

						cout << "sitio desconocido a la derecha mirando al oeste" << endl;
						accion = actTURN_L;
					}        
				}
			break;
		}  
	}

	if((sensores.terreno[3] == 'M' or sensores.terreno[7] == 'M' or sensores.terreno[13] == 'M'
        or sensores.terreno[1] == 'M' or sensores.terreno[5] == 'M' or sensores.terreno[11] == 'M')
        and sensores.superficie[2] == '_' ) {

			accion = seguir_muro(sensores);
	}

	if(recien_nacido && sensores.superficie[2] == '_' && ciclos_recien_nacido < 10){

        if(pasos_a_andar < 20) {
            accion = actFORWARD;
			ciclos_recien_nacido++;
            pasos_a_andar++;
        }
        else {

            accion = girar();
			ciclos_recien_nacido++;
            pasos_a_andar = 0;            
        }		

	}
	else if(ciclos_recien_nacido >= 10) recien_nacido = false;

    return accion;

}

Action ComportamientoJugador::seguir_muro(Sensores sensores) {

    Action accion;

    if((sensores.terreno[3] == 'M' or sensores.terreno[7] == 'M' or sensores.terreno[13] == 'M'
        or sensores.terreno[1] == 'M' or sensores.terreno[5] == 'M' or sensores.terreno[11] == 'M')
        and sensores.superficie[2] == '_') {

            if(sensores.terreno[2]== 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' 
                or sensores.terreno[2] == 'X' or sensores.terreno[2] == 'D' or sensores.terreno[2] == 'K'
                and sensores.superficie[2] == '_'){
                    
                    accion = actFORWARD;
					pasos_muro++;
                    cout << "--> Avanzo al frente" << endl;

            }
            else if((sensores.terreno[2] == 'B' and zapatillas) and sensores.superficie[2] == '_'){

                accion = actFORWARD;
				pasos_muro++;
                cout << "--> Avanzo al frente" << endl;
                    
            }
            else if((sensores.terreno[2] == 'A' and bikini) and sensores.superficie[2] == '_'){
                            
                accion = actFORWARD;
				pasos_muro++;
                cout << "--> Avanzo al frente" << endl;
            }
            else{

				accion = girar();
            }
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

Action ComportamientoJugador::encontrarBikini(Sensores sensores) {


	Action accion = actIDLE;
	int casilla;

	for(int i = 0; i < sensores.terreno.size() && !encontrada; i++) {

		if(sensores.terreno[i] == 'K'){
					
			casilla = i;
			encontrada = true;
		}
	}

	if(encontrada) {

		cout << "He visto la casilla bikini " << endl;
		if(casilla == 2 || casilla == 6 || casilla == 12) {

			cout << "La he visto enfrente" << endl;
			recto = true;
		}
		else if(casilla == 1 || casilla == 5 || casilla == 11 || casilla == 4 || casilla == 10 || casilla == 9 ){

			cout << "La he visto encima mia" << endl;
			arriba = true;
		}
		else if(casilla == 3 || casilla == 7 || casilla == 13 || casilla == 8 || casilla == 14 || casilla == 15 ){

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

	if(sensores.terreno[0] == 'K') {
		
		bikini = true;
		encontrada = false;
	}

	return accion;
	
}

Action ComportamientoJugador::encontrarZapatillas(Sensores sensores) {

	Action accion = actIDLE;
	int casilla;
		
	for(int i = 0; i < sensores.terreno.size() && !encontrada; i++) {

		if(sensores.terreno[i] == 'D'){
				
			casilla = i;
			encontrada = true;
		}
	}

	if(encontrada) {

		cout << "He visto la casilla zapatillas " << endl;
		if(casilla == 2 || casilla == 6 || casilla == 12) {

			cout << "La he visto enfrente" << endl;
			recto = true;
		}
		else if(casilla == 1 || casilla == 5 || casilla == 11 || casilla == 4 || casilla == 10 || casilla == 9){

			cout << "La he visto encima mia" << endl;
			arriba = true;
		}
		else if(casilla == 3 || casilla == 7 || casilla == 13 || casilla == 8 || casilla == 14 || casilla == 15 ){

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

	if(sensores.terreno[0] == 'D') {
		
		zapatillas = true;
		encontrada = false;
		
	}

	return accion;
	
}

Action ComportamientoJugador::encontrarRecarga(Sensores sensores) {

	Action accion = actIDLE;
	int casilla;
		
	for(int i = 0; i < sensores.terreno.size() && !encontrada; i++) {

		if(sensores.terreno[i] == 'X'){
				
			casilla = i;
			encontrada = true;
		}
	}

	if(encontrada) {

		cout << "He visto la casilla recarga " << endl;
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

	if(sensores.terreno[0] == 'X' && ciclos < 197) {

		accion = actIDLE;
		ciclos++;
		cargando = true;
	}
	else {
		
		cargando = false;
		encontrada = false;
		ciclos = 0;
	}

	return accion;
	
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}