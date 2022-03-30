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

    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    Action encontrarCasillaPos(Sensores sensores);

  private:
  
  // Declarar aquí las variables de estado
  int fil, 
      col,
      brujula;

  Action ultimaAccion;
  bool girar_derecha,
       bien_situado;

};

#endif
