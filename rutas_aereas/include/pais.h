
#ifndef _PAIS_H_
#define _PAIS_H_

#include "punto.h"
#include <string>
#include <iostream>

using namespace std;

class Pais
{
private:
    Punto p;
    string pais;
    string bandera;

public:
    Pais() 
    {
        pais = "";
        bandera = "";
    }

    void setPunto(const Punto &otro)
    {
        p = otro;
    }

    Punto GetPunto() const
    {
        return p;
    }

    string GetPais() const
    {
        return pais;
    }

    string GetBandera() const
    {
        return bandera;
    }

    bool operator<(const Pais &P) const
    {
        if(pais < P.pais)
            return true;
        else
            return false;
    }

    bool operator==(const Pais &P) const
    {
        if(p.latitud == P.p.latitud && p.longitud == P.p.longitud && pais == P.pais && bandera == P.bandera)
            return true;
        else
            return false;
    }

    bool operator!=(const Pais &P) const
    {
        return !(*this == P);
    }

    bool operator==(const Punto &P) const
    {
        if(p.latitud == P.latitud && p.longitud == P.longitud)
            return true;
        else
            return false;
    }

    bool operator!=(const Punto &P) const
    {
        return !(*this == P);
    }

    friend istream &operator>>(istream &is, Pais &P)
    {
        double lat, lng;

        is >> lat >> lng >> P.pais >> P.bandera;

        P.p = Punto(lat, lng, "");
        return is;
    }
    
    friend ostream &operator<<(ostream &os, const Pais &P)
    {
        os << P.p << " " << P.pais << " " << P.bandera << endl;
        return os;
    }
};

#endif