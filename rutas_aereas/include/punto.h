/**
 * @file punto.h
 * @brief Fichero cabecera que gestiona un punto geográfico
 */

#ifndef _PUNTO_H_
#define _PUNTO_H_

#include <string>
#include <iostream>

using namespace std;

/**
 * @struct Punto
 * @brief Estructura que representa un punto geográfico
 */
struct Punto{
    double latitud; /**< Latitud del punto */
    double longitud; /**< Longitud del punto */
    string name; /**< Nombre del punto */

    /**
     * @brief Constructor por defecto de la estructura Punto
     */
    Punto()
    {
        latitud = 0;
        longitud = 0;
        name = "";
    }

    /**
     * @brief Constructor de la estructura Punto
     * @param lat Latitud del punto
     * @param lng Longitud del punto
     * @param s Nombre del punto
     */
    Punto(double lat, double lng, string s)
    {
        latitud = lat;
        longitud = lng;
        name = s;
    }

    /**
     * @brief Obtiene la latitud del punto
     * @return La latitud del punto
     */
    double getLatitud()
    {
        return latitud;
    }

    /**
     * @brief Obtiene la longitud del punto
     * @return La longitud del punto
     */
    double getLongitud()
    {
        return longitud;
    }

    /**
     * @brief Sobrecarga del operador de igualdad ==
     * @param P Punto con el que se compara
     * @return Devuelve true si ambos puntos son iguales, false en caso contrario
     */
    bool operator==(const Punto &P) const
    {
        if(latitud == P.latitud && longitud == P.longitud)
            return true;
        else
            return false;
    }

    /**
     * @brief Sobrecarga del operador de desigualdad !=
     * @param P Punto con el que se compara
     * @return Devuelve true si ambos puntos son diferentes, false en caso contrario
     */
    bool operator!=(const Punto &P) const
    {
        return !(*this == P);
    }

    /**
     * @brief Sobrecarga del operador de inserción en flujo de salida
     * @param os Flujo de salida
     * @param p Punto a mostrar
     * @return El flujo de salida con el punto insertado
     */
    friend ostream &operator<<(ostream &os, const Punto &p)
    {
        os << "(" << p.latitud << "," << p.longitud << ")";
        return os;
    }

    /**
     * @brief Sobrecarga del operador de extracción de flujo de entrada
     * @param is Flujo de entrada
     * @param p Punto a leer
     * @return El flujo de entrada con el punto leído
     */
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
