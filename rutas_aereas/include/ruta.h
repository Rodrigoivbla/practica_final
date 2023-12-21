/**
 * @file ruta.h
 * @brief Archivo de cabecera para la gestión de rutas
 */

#ifndef _RUTA_H_
#define _RUTA_H_

#include "punto.h"
#include <string>
#include <list>

/**
  @brief T.D.A. Ruta

  Una instancia del tipo de dato abstracto Ruta nos permite almacenar datos sobre una ruta aérea.
  Una ruta está representada por su nombre y una lista de puntos bidimensionales que indica los paises por los que pasa.

  El TDA Ruta proporciona además distintas herramientas para la manipulación de dicha lista de puntos.

  Para poder usar el TDA Ruta se debe incluir el fichero

  \#include <ruta.h>

  @author Rodrigo Ibáñez Blanco
  @author Brandon Rene Morales Viracocha
  @date Diciembre 2023
**/
class Ruta {
    private:
        /**
         * @brief Nombre de la ruta.
        **/
        string nombre;

        /**
         * @brief Lista de puntos en 2D que conforman la ruta.
        **/
        list<Punto> ruta;

    public:
        /**
         * @brief Obtiene el nombre de la ruta
         * @return El nombre de la ruta
         */
        string getNombre() const {
            return nombre;
        }

        /**
         * @brief Obtiene la lista de puntos que componen la ruta.
         * @return La lista de puntos de la ruta.
         */
        list<Punto> getRuta() const {
            return ruta;
        }

        /**
         * @brief Inserta un punto al final de la lista de puntos.
         * @param p Referencia constante al punto que se va a insertar.
        **/
        void Insertar(const Punto &p)
        {
            ruta.push_back(p);
        }

        /**
         * @brief Elimina un punto de la lista de puntos.
         * @param p Referencia constante al punto que se va a eliminar.
        **/
        void Borrar(const Punto &p)
        {
            iterator it = find(p);

            if(it != end())
                ruta.erase(it.p);
        }

        class const_iterator;
        class iterator
        {
        private:
            list<Punto>::iterator p;

        public:
            iterator(): p(0)
            {}

            iterator(const iterator &otro): p(otro.p)
            {}

            ~iterator()
            {}

            iterator& operator=(const iterator &otro)
            {
                p = otro.p;
                return *this;
            }

            Punto& operator*() const
            {
                return *p;
            }

            iterator& operator++()
            {
                p++;
                return *this;
            }

            iterator& operator--()
            {
                p--;
                return *this;
            }

            bool operator!=(const iterator &otro) const
            {
                return p != otro.p;
            }

            bool operator==(const iterator &otro) const
            {
                return p == otro.p;
            }

            friend class Ruta;
            friend class const_iterator;
        };

        class const_iterator
        {
        private:
            list<Punto>::const_iterator p;

        public:
            const_iterator(): p(0)
            {}

            const_iterator(const const_iterator &otro): p(otro.p)
            {}

            ~const_iterator()
            {}

            const_iterator& operator=(const const_iterator &otro)
            {
                p = otro.p;
                return *this;
            }

            const Punto& operator*() const
            {
                return *p;
            }

            const_iterator& operator++()
            {
                p++;
                return *this;
            }

            const_iterator& operator--()
            {
                p--;
                return *this;
            }

            bool operator!=(const const_iterator &otro) const
            {
                return p != otro.p;
            }

            bool operator==(const const_iterator &otro) const
            {
                return p == otro.p;
            }

            friend class Ruta;
        };

        iterator begin()
        {
            iterator it;
            it.p = ruta.begin();
            return it;
        }

        const_iterator begin() const 
        {
            const_iterator it;
            it.p = ruta.begin();
            return it;
        } 
        
        iterator end()
        {
            iterator it;
            it.p = ruta.end();
            return it;
        }
        
        const_iterator end() const 
        {
            const_iterator it;
            it.p = ruta.end();
            return it;
        }

        /**
         * @brief Busca un punto dentro de la ruta.
         * @param p Referencia constante al punto que se quiere buscar.
         * @return Iterador que apunta al punto pasado como parámetro.
        **/
        iterator find(const Punto &p)
        {
            iterator it;
            list<Punto>::iterator i;
            for (i = ruta.begin(); i != ruta.end() && !(*i == p); ++i);
            it.p = i;
            return it;
        }

        /**
         * @brief Sobrecarga del operador de desigualdad !=.
         * @param R Referencia constate a la ruta con la que se compara.
         * @return Devuelve true si las rutas son diferentes, false en caso contrario.
         * @post La ruta no se modifica.
         */
        bool operator!=(const Ruta &R) const
        {
            if (nombre == R.nombre) 
            {
                return true;
            }

            if (ruta.size() != R.ruta.size()) 
            {
                return true;
            }

            // Comparación de la lista de puntos en ambas rutas
            const_iterator r_it = R.begin();

            for (const_iterator it = begin(); it != end() && r_it != R.end(); ++it, ++r_it) 
            {
                if (!(*it == *r_it))
                    return true;
            }
        }

        /**
         * @brief Sobrecarga del operador de inserción en flujo de entrada.
         * @param is Flujo de entrada.
         * @param R Ruta a leer.
         * @return El flujo de entrada con la ruta leída.
         */
        friend istream &operator>>(istream &is, Ruta &R) 
        {
            Ruta rlocal;

            int n_loc;
            Punto P;

            is >> rlocal.nombre;
            is >> n_loc;

            for (int i = 0; i < n_loc; ++i) 
            {
                is >> P;
                rlocal.Insertar(P);
            }

            R = rlocal;
            return is;
        }

        /**
         * @brief Sobrecarga del operador de inserción en flujo de salida.
         * @param os Flujo de salida.
         * @param R Ruta a mostrar.
         * @return El flujo de salida con la ruta insertada.
         */
        friend ostream &operator<<(ostream &os, const Ruta &R) 
        {
            const_iterator it;

            os << R.ruta.size(); // Muestra el tamaño de la lista de puntos

            for (it = R.begin(); it != R.end(); ++it) 
            {
                os << " " << *it << "\t"; // Muestra cada punto de la ruta
            }

            return os;
        }
};

#endif
