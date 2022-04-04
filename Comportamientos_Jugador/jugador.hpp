#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){

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
      casilla_vista.first = false;
      casilla_vista.second = -1;
      fil_aux = col_aux = 99;

      for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
          matriz_aux[i][j] = '?';
        }
      }

    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    Action encontrarCasillaPos(Sensores sensores);
    Action encontrarBikini(Sensores sensores);
    Action encontrarZapatillas(Sensores sensores);
    Action encontrarRecarga(Sensores sensores);
    Action girar();
    Action moverse(Sensores sensores);
    Action seguir_muro(Sensores sensores);
    void pintarMapa(Sensores sensores);
    bool veoCasilla(Sensores sensores, char buscar);
    void trasponerMapaAuxiliar();

  private:
  
  // Declarar aquí las variables de estado

  int fil, 
      col,
      brujula,
      pasos_a_andar,
      fil_aux,
      col_aux;

  Action ultimaAccion;
  bool girar_derecha,
       bien_situado,
       zapatillas,
       bikini,
       recarga;

  bool encontrada;
  bool gira_bien;
	bool recto ;
	bool arriba;
	bool abajo;   
  bool bikini_visto,
       zapatillas_vistas,
       recarga_vista;  

  unsigned char matriz_aux[200][200];     

  pair<bool, int> casilla_vista;

};

#endif
