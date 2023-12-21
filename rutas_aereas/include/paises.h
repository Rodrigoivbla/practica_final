/**
 * @file paises.h
 * @brief Fichero cabecera que gestiona el conjunto de países utilizados
 */

#ifndef _PAISES_H_
#define _PAISES_H_

#include "pais.h"
#include <set>
#include <cassert>

using namespace std;

/**
  @brief T.D.A. Paises

  Una instancia del tipo de dato abstracto Pais nos permite almacenar datos sobre un conjunto de paises.
  Este tipo de dato abstracto está implementado con un set de países.

  El TDA Paises proporciona además distintas herramientas para la manipulación de dicho set de  paises.

  Para poder usar el TDA Paises se debe incluir el fichero

  \#include <paises.h>

  @author Rodrigo Ibáñez Blanco
  @author Brandon Rene Morales Viracocha
  @date Diciembre 2023
**/
class Paises {
    private:
        /**
         * @brief Conjunto de paises.
        **/
        set<Pais> datos;

    public:
        /**
         * @brief Constructor por defecto de la clase Paises.
         * @post Genera una instancia de la clase Paises con un conjunto de paises vacío.
         * @return Paises, el objeto paises creado.  
         */
        Paises() {}

        /**
         * @brief Inserta un país en el conjunto de paises.
         * @param P Objeto de tipo Pais a insertar.
         */
        void Insertar(const Pais &P) 
        {
            datos.insert(P);
        }

        /**
         * @brief Borra un país del conjunto de paises.
         * @param P Objeto de tipo Pais a borrar.
         */
        void Borrar(const Pais &P) 
        {
            datos.erase(P);
        }

        class const_iterator;

        class iterator {
        private:
            set<Pais>::iterator p;

        public:
            iterator() : p(0) {}

            iterator(const iterator &otro) : p(otro.p) {}

            ~iterator() {}

            iterator &operator=(const iterator &otro) {
                p = otro.p;
                return *this;
            }

            const Pais &operator*() const {
                return *p;
            }

            iterator &operator++() {
                p++;
                return *this;
            }

            iterator &operator--() {
                p--;
                return *this;
            }

            bool operator!=(const iterator &otro) const {
                return p != otro.p;
            }

            bool operator==(const iterator &otro) const {
                return p == otro.p;
            }

            friend class Paises;

            friend class const_iterator;
        };

        class const_iterator {
        private:
            set<Pais>::const_iterator p;

        public:
            const_iterator() : p(0) {}

            const_iterator(const const_iterator &otro) : p(otro.p) {}

            ~const_iterator() {}

            const_iterator &operator=(const const_iterator &otro) {
                p = otro.p;
                return *this;
            }

            const Pais &operator*() const {
                return *p;
            }

            const_iterator &operator++() {
                p++;
                return *this;
            }

            const_iterator &operator--() {
                p--;
                return *this;
            }

            bool operator!=(const const_iterator &otro) const {
                return p != otro.p;
            }

            bool operator==(const const_iterator &otro) const {
                return p == otro.p;
            }

            friend class Paises;
        };

        iterator begin() 
        {
            iterator it;
            it.p = datos.begin();
            return it;
        }

        const_iterator begin() const 
        {
            const_iterator it;
            it.p = datos.begin();
            return it;
        }

        iterator end() 
        {
            iterator it;
            it.p = datos.end();
            return it;
        }

        const_iterator end() const 
        {
            const_iterator it;
            it.p = datos.end();
            return it;
        }

        /**
         * @brief Busca un país dentro del conjunto de paises.
         * @param p Referencia constante al país que se quiere buscar.
         * @return Iterador que apunta al país pasado como parámetro.
        **/
        iterator find(const Pais &p)
        {
            iterator it;
            set<Pais>::iterator i;
            for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i);
            it.p = i;
            return it;
        }

        /**
         * @brief Busca un país que contiene un punto dado dentro del conjunto de paises.
         * @param p Referencia constante al punto que se quiere buscar.
         * @return Iterador que apunta al país que contiene al punto pasado como parámetro.
        **/
        iterator find(const Punto &p)
        {
            iterator it;
            set<Pais>::iterator i;
            for (i = datos.begin(); i != datos.end() && !(*i == p); ++i);
            it.p = i;
            return it;
        }

        /**
         * @brief Operador de lectura de flujo de datos.
         * @param os Referencia al flujo de datos sobre el que se lee.
         * @param R Referencia al conjunto de paises que se va a crear con los datos leídos.
         * @return Flujo de datos sobre el que se ha invocado el operador >>.
        **/
        friend istream &operator>>(istream &is, Paises &R)
        {
            Paises rlocal;
            // leemos el comentario
            if (is.peek() == '#')
            {
                string a;
                getline(is, a);
            }

            Pais P;

            while (is >> P)
            {
                rlocal.Insertar(P);
            }

            R = rlocal;
            return is;
        }

        /**
             * @brief Operador de escritura de flujo de datos.
             * @param os Referencia al flujo de datos sobre el que se escribe.
             * @param p Referencia al conjunto de paises que se va a escribir en el flujo.
             * @return Flujo de datos sobre el que se ha invocado el operador <<.
            **/
        friend ostream &operator<<(ostream &os, const Paises &R)
        {
            Paises::const_iterator it;

            for (it = R.begin(); it != R.end(); ++it)
            {
                os << *it << "\t";
            }
            return os;
        }
};

#endif
