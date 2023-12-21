/**
  * @file almacenRutas.h
  * @brief Fichero cabecera que almacena las rutas
  *
  */
#ifndef _ALMACEN_RUTAS_H_
#define _ALMACEN_RUTAS_H_

#include "ruta.h"
#include <map>

/**
  @brief T.D.A. Almacen_Rutas

  Una instancia del tipo de dato abstracto Almacen_Rutas nos permite almacenar datos sobre un conjunto de rutas.
  Este tipo de dato abstracto está representado mediante un map de rutas, en el que la clave es el nombre de la ruta y el valor mapeado es la ruta en sí.

  El TDA Almacen_Rutas proporciona además distintas herramientas para la manipulación de dicho conjunto de rutas.

  Para poder usar el TDA Almacen_Rutas se debe incluir el fichero

  \#include <almacenRutas.h>

  @author Rodrigo Ibáñez Blanco
  @author Brandon Rene Morales Viracocha
  @date Diciembre 2023
**/
class Almacen_Rutas{
  private:
    /**
     * @brief Mapa que almacena las rutas. La clave es el nombre de la ruta, y el valor mapeado es la ruta en sí. 
    **/
    map<string, Ruta> almacen;

  public:
    /**
     * @brief Constructor por defecto.
     * @return Almacen de rutas, el objeto almacén de rutas creado.
     * @post Genera una instancia de la clase Almacen_rutas con un conjunto de rutas vacío.
     */
    Almacen_Rutas() {}

    /**
     * @brief Obtiene una ruta del almacén
     * @param s Nombre de la ruta a obtener
     * @return Ruta correspondiente al nombre proporcionado
     * @post El almacén de rutas no se modifica
     */
    Ruta GetRuta(const string &s) const
    {
        return almacen.at(s);
    }

    /**
     * @brief Inserta una ruta en el almacén.
     * @param R Ruta a insertar.
     */
    void Insertar(const Ruta &R)
    {
        almacen[R.getNombre()] = R;
    }

    /**
     * @brief Borra una ruta del almacén.
     * @param s Nombre de la ruta a borrar.
     */
    void Borrar(const string &s)
    {
        almacen.erase(s);
    }

    class const_iterator;

    class iterator {
    private:
        map<string, Ruta>::iterator p;

    public:
        /**
     * @brief Constructor por defecto del iterador
     */
        iterator() : p(0) {}

        /**
     * @brief Constructor de copia del iterador
     * @param otro Iterador a copiar
     */
        iterator(const iterator &otro) : p(otro.p) {}

        ~iterator() {}

        iterator &operator=(const iterator &otro) {
            p = otro.p;
            return *this;
        }

        const pair <string, Ruta> &operator*() const {
            return *p;
        }

        iterator &operator++() {
            ++p;
            return *this;
        }

        iterator &operator--() {
            --p;
            return *this;
        }

        /**
    * @brief Sobrecarga del operador de desigualdad !=
    * @param otro Iterador a comparar
    * @return true si los iteradores son diferentes, false en caso contrario
    */
        bool operator!=(const iterator &otro) const {
            return p != otro.p;
        }

        /**
         * @brief Sobrecarga del operador de igualdad ==
         * @param otro Iterador a comparar
         * @return true si los iteradores son iguales, false en caso contrario
         */
        bool operator==(const iterator &otro) const {
            return p == otro.p;
        }

        friend class Almacen_Rutas;

        friend class const_iterator;
    };

    class const_iterator {
    private:
        map<string, Ruta>::const_iterator p;

    public:


        /**
     * @brief Constructor por defecto del iterador constante
     */
        const_iterator() : p(0) {}

        /**
         * @brief Constructor de copia del iterador constante
         * @param otro Iterador constante a copiar
         */
        const_iterator(const iterator &otro) : p(otro.p) {}

        /**
     * @brief Destructor del iterador constante
     */
        ~const_iterator() {}

        /**
    * @brief Sobrecarga del operador de incremento ++
    * @return Referencia al iterador incrementado
    */
        const_iterator &operator++() {
            ++p;
            return *this;
        }

        /**
         * @brief Sobrecarga del operador de decremento --
         * @return Referencia al iterador decrementado
         */
        const_iterator &operator--() {
            --p;
            return *this;
        }

        /**
         * @brief Sobrecarga del operador de igualdad ==
         * @param it Otro iterador constante a comparar
         * @return true si los iteradores son iguales, false en caso contrario
         */
        bool operator==(const const_iterator &it) {
            return p == it.p;
        }

        /**
         * @brief Sobrecarga del operador de desigualdad !=
         * @param it Otro iterador constante a comparar
         * @return true si los iteradores son diferentes, false en caso contrario
         */
        bool operator!=(const const_iterator &it) {
            return p != it.p;
        }

        /**
         * @brief Sobrecarga del operador de desreferenciación *
         * @return Par de valores clave/valor asociado al iterador
         */
        const pair <string, Ruta> operator*() {
            return *p;
        }

        friend class Almacen_Rutas;
    };

    /**
 * @brief Devuelve un iterador al inicio del conjunto de rutas
 * @return Iterador al inicio del conjunto
 */
    iterator begin() {
        iterator it;
        it.p = almacen.begin();
        return it;
    }

    /**
 * @brief Devuelve un iterador constante al inicio del conjunto de rutas
 * @return Iterador constante al inicio del conjunto
 */
    const_iterator begin() const {
        const_iterator it;
        it.p = almacen.begin();
        return it;
    }

    /**
 * @brief Devuelve un iterador al final del conjunto de rutas
 * @return Iterador al final del conjunto
 */
    iterator end() {
        iterator it;
        it.p = almacen.end();
        return it;
    }

    /**
 * @brief Devuelve un iterador constante al final del conjunto de rutas
 * @return Iterador constante al final del conjunto
 */
    const_iterator end() const {
        const_iterator it;
        it.p = almacen.end();
        return it;
    }

    /**
         * @brief Busca una ruta por el nombre dentro del almacén de rutas.
         * @param s Referencia constante al nombre de la ruta que se quiere buscar.
         * @return Iterador que apunta a la ruta con el nombre pasado como parámetro.
        **/
    iterator find(const string &s)
    {
        iterator it;
        map<string, Ruta>::iterator i;
        for (i = almacen.begin(); i != almacen.end() && !((*i).first == s); ++i);
        it.p = i;
        return it;
    }

    /**
     * @brief Sobrecarga del operador de entrada >>.
     * @param is Stream de entrada.
     * @param AR Almacén de rutas a leer.
     * @return Referencia al stream de entrada.
     */
    friend istream &operator>>(istream &is, Almacen_Rutas &AR)
    {
        Almacen_Rutas arlocal;
        // leemos el comentario
        if (is.peek() == '#') {
            string a;
            getline(is, a);
        }

        Ruta R;

        while (is >> R) {
            arlocal.Insertar(R);
        }

        AR = arlocal;
        return is;
    }

    /**
     * @brief Sobrecarga del operador de salida <<.
     * @param os Stream de salida.
     * @param AR Almacén de rutas a escribir.
     * @return Referencia al stream de salida.
     */
    friend ostream &operator<<(ostream &os, const Almacen_Rutas &AR)
    {
        os << "#Rutas" << endl;
        Almacen_Rutas::const_iterator it;

        for (it = AR.begin(); it != AR.end(); ++it) {
            os << (*it).first << " " << (*it).second << "\t" << endl;
        }
        return os;
    }
};

#endif
