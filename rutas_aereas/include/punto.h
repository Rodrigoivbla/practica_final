
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

  bool operator==(const Punto &P) const
  {
      if(latitud == P.latitud && longitud == P.longitud)
          return true;
      else
          return false;
  }

  bool operator!=(const Punto &P) const
  {
    return !(*this == P);
  }

  friend ostream &operator<<(ostream &os, const Punto &p)
  {
    os << p.latitud << "," << p.longitud ;
    return os;
  }

  friend istream &operator>>(istream &is, Punto &p)
  {
    double lat, lon;
    char c;

    is >> c >> lat >> c >> lon >> c;

    p = Punto(lat, lon, "");

    return is;
  }
};

#endif