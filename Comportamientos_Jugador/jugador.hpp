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
      casilla_vista.first = false;
      casilla_vista.second = -1;

    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    Action encontrarCasillaPos(Sensores sensores);
    Action girar();
    Action moverse(Sensores sensores);
    Action seguir_muro(Sensores sensores);
    void pintarMapa(Sensores sensores);
    bool veoCasilla(Sensores sensores, char buscar);

  private:
  
  // Declarar aquí las variables de estado
  int fil, 
      col,
      brujula,
      pasos_a_andar;

  Action ultimaAccion;
  bool girar_derecha,
       bien_situado,
       zapatillas,
       bikini;

  bool encontrada;
	bool recto ;
	bool arriba;
	bool abajo;     

  pair<bool, int> casilla_vista;

};

#endif
