
#ifndef _RUTA_H_
#define _RUTA_H_

#include "punto.h"
#include <string>
#include <list>

class Ruta{
  private:
    string nombre;
    list<Punto> ruta;
};

#endif