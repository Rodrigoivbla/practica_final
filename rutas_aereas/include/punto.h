
#ifndef _PUNTO_H_
#define _PUNTO_H_

#include <string>
#include <iostream>

using namespace std;

struct Punto{
  double latitud;
  double longitud;

  Punto()
  {
    latitud = 0;
    longitud = 0;
  }

  Punto(double lat, double lng, string s)
  {
    latitud = lat;
    longitud = lng;
  }

  friend ostream &operator<<(ostream &os, const Punto &p)
  {
    os << p.latitud << "," << p.longitud ;
    return os;
  }
};

#endif