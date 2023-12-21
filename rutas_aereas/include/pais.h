/**
 * @file pais.h
 * @brief Fichero cabecera que gestiona los países utilizados
 */

#ifndef _PAIS_H_
#define _PAIS_H_

#include "punto.h"
#include <string>
#include <iostream>

using namespace std;

/**
 * @class Pais
 * @brief Clase para gestionar un país con su ubicación y bandera
 */
class Pais {
private:
    Punto p; /**< Ubicación geográfica */
    string pais; /**< Nombre del país */
    string bandera; /**< Ruta de la bandera del país */

public:
    /**
     * @brief Constructor por defecto de la clase Pais
     */
    Pais() {
        pais = "";
        bandera = "";
    }

    /**
     * @brief Establece la ubicación geográfica del país
     * @param otro Objeto Punto con la ubicación geográfica
     */
    void setPunto(const Punto &otro) {
        p = otro;
    }

    /**
     * @brief Obtiene la ubicación geográfica del país
     * @return Objeto Punto con la ubicación
     */
    Punto GetPunto() const {
        return p;
    }

    /**
     * @brief Obtiene el nombre del país
     * @return Nombre del país
     */
    string GetPais() const {
        return pais;
    }

    /**
     * @brief Obtiene la ruta de la bandera del país
     * @return Ruta de la bandera
     */
    string GetBandera() const {
        return bandera;
    }

    /**
     * @brief Sobrecarga del operador menor que para comparar países
     */
    bool operator<(const Pais &P) const {
        return pais < P.pais;
    }

    /**
     * @brief Sobrecarga del operador de igualdad para comparar países
     */
    bool operator==(const Pais &P) const {
        return (p.latitud == P.p.latitud && p.longitud == P.p.longitud && pais == P.pais && bandera == P.bandera);
    }

    /**
     * @brief Sobrecarga del operador de desigualdad para comparar países
     */
    bool operator!=(const Pais &P) const {
        return !(*this == P);
    }

    /**
     * @brief Sobrecarga del operador de igualdad para comparar con un Punto
     */
    bool operator==(const Punto &P) const {
        return (p.latitud == P.latitud && p.longitud == P.longitud);
    }

    /**
     * @brief Sobrecarga del operador de desigualdad para comparar con un Punto
     */
    bool operator!=(const Punto &P) const {
        return !(*this == P);
    }

    /**
     * @brief Sobrecarga del operador de inserción para leer datos de un flujo de entrada
     */
    friend istream &operator>>(istream &is, Pais &P) {
        double lat, lng;

        is >> lat >> lng >> P.pais >> P.bandera;

        P.p = Punto(lat, lng, "");
        return is;
    }

    /**
     * @brief Sobrecarga del operador de extracción para escribir datos en un flujo de salida
     */
    friend ostream &operator<<(ostream &os, const Pais &P) {
        os << P.p << " " << P.pais << " " << P.bandera << endl;
        return os;
    }
};

#endif
