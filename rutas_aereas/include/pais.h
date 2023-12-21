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
  @brief T.D.A. Pais

  Una instancia del tipo de dato abstracto Pais nos permite almacenar datos sobre un país.
  Un  país está representado por un punto bidimensional que indica su posición sobre el mapa, un nombre y una bandera.

  El TDA Pais proporciona además distintas herramientas para la manipulación de dichos paises.

  Para poder usar el TDA Pais se debe incluir el fichero

  \#include <pais.h>

  @author Rodrigo Ibáñez Blanco
  @author Brandon Rene Morales Viracocha
  @date Diciembre 2023
**/
class Pais {
    private:
        /**
         * @brief Punto que indica la situación del país sobre el mapa.
        **/
        Punto p;

        /**
         * Nombre del país.
        **/
        string pais;

        /**
         * Nombre de la bandera del país.
        **/
        string bandera;

    public:
        /**
         * @brief Constructor por defecto.
         * @post Genera una instancia de la clase Pais sin nombre y sin bandera. El constructor por defecto de la clase Punto inicializa el atributo p.
         * @return Pais, el objeto pais creado.
        **/
        Pais() {
            pais = "";
            bandera = "";
        }

        /**
         * @brief Establece la ubicación geográfica del país.
         * @param otro Objeto Punto con la ubicación geográfica.
         */
        void setPunto(const Punto &otro) {
            p = otro;
        }

        /**
         * @brief Obtiene la ubicación geográfica del país.
         * @return Objeto Punto con la ubicación.
         * @post El país no se modifica.
         */
        Punto GetPunto() const {
            return p;
        }

        /**
         * @brief Obtiene el nombre del país.
         * @return Nombre del país.
         * @post El país no se modifica.
         */
        string GetPais() const {
            return pais;
        }

        /**
         * @brief Obtiene la ruta de la bandera del país.
         * @return Ruta de la bandera.
         * @post El país no se modifica.
         */
        string GetBandera() const {
            return bandera;
        }

        /**
         * @brief Operador de comparación menor que. Se emplea el código ASCII correspondiente a la primera letra de los nombre. 
         * En caso de igualdad, se pasa a la siguiente letra.
         * @param P País con el que se quiere realizar la comparación.
         * @return True si el nombre de P es mayor que el de la instancia que invoca al operador. False en caso contrario.
         * @post El país no se modifica.
        **/
        bool operator<(const Pais &P) const {
            return pais < P.pais;
        }

        /**
         * @brief Sobrecarga del operador de igualdad para comparar paises.
         * @param P País con el que se quiere realizar la comparación.
         * @return True si tanto el punto, el nombre y la bandera de ambos paises son iguales. False en caso contrario.
         * @post El país no se modifica.
         */
        bool operator==(const Pais &P) const {
            return (p == P.p && pais == P.pais && bandera == P.bandera);
        }

        /**
         * @brief Sobrecarga del operador de igualdad para comparar con un Punto.
         * @param Punto con el que se quiere realizar la comparación.
         * @return True si ambos puntos son iguales. False en caso contrario.
         * @post El país no se modifica.
         */
        bool operator==(const Punto &P) const {
            return (p == P);
        }

        /**
         * @brief Operador de lectura de flujo de datos.
         * @param os Referencia al flujo de datos sobre el que se lee.
         * @param p Referencia al país que se va a crear con los datos leídos.
         * @return Flujo de datos sobre el que se ha invocado el operador >>.
        **/
        friend istream &operator>>(istream &is, Pais &P) {
            double lat, lng;

            is >> lat >> lng >> P.pais >> P.bandera;

            P.p = Punto(lat, lng, "");
            return is;
        }

        /**
         * @brief Operador de escritura de flujo de datos.
         * @param os Referencia al flujo de datos sobre el que se escribe.
         * @param p Referencia al país que se va a escribir en el flujo.
         * @return Flujo de datos sobre el que se ha invocado el operador <<.
        **/
        friend ostream &operator<<(ostream &os, const Pais &P) {
            os << P.p << " " << P.pais << " " << P.bandera << endl;
            return os;
        }
};

#endif
