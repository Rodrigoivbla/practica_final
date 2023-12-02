
#include string

struct Punto{
  double latitud;
  double longitud;

  Punto(double lat, double lng, string s)
  {
    latitud = lat;
    longitud = lng;
  }
};