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
 * @class Paises
 * @brief Clase que gestiona un conjunto de países
 */
class Paises {
private:
    set <Pais> datos; /**< Conjunto de países */

public:
    /**
     * @brief Constructor por defecto de la clase Paises
     */
    Paises() {}

    /**
     * @brief Inserta un país en el conjunto de países
     * @param P Objeto Pais a insertar
     */
    void Insertar(const Pais &P) {
        datos.insert(P);
    }

    /**
     * @brief Borra un país del conjunto de países
     * @param P Objeto Pais a borrar
     */
    void Borrar(const Pais &P) {
        datos.erase(P);
    }

    class const_iterator;

    /**
    * @class iterator
    * @brief Iterador para recorrer y manipular el conjunto de países
    */
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

    /**
     * @class const_iterator
     * @brief Iterador constante para recorrer el conjunto de países
     */
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

    /**
    * @brief Obtiene un iterador al principio del conjunto de países
    * @return Iterador al principio del conjunto
    */
    iterator begin() {
        iterator it;
        it.p = datos.begin();
        return it;
    }

    /**
     * @brief Obtiene un iterador constante al principio del conjunto de países
     * @return Iterador constante al principio del conjunto
     */
    const_iterator begin() const {
        const_iterator it;
        it.p = datos.begin();
        return it;
    }

    /**
 * @brief Obtiene un iterador al final del conjunto de países
 * @return Iterador al final del conjunto
 */
    iterator end() {
        iterator it;
        it.p = datos.end();
        return it;
    }

    /**
 * @brief Obtiene un iterador constante al final del conjunto de países
 * @return Iterador constante al final del conjunto
 */
    const_iterator end() const {
        const_iterator it;
        it.p = datos.end();
        return it;
    }

    /**
 * @brief Encuentra un país en el conjunto según el objeto Pais proporcionado
 * @param p Objeto Pais a buscar
 * @return Iterador apuntando al país encontrado o al final si no se encuentra
 */
    iterator find(const Pais &p) {
        iterator it;
        set<Pais>::iterator i;
        for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i);
        it.p = i;
        return it;
    }

    /**
 * @brief Encuentra un país en el conjunto según el objeto Punto proporcionado
 * @param p Objeto Punto a buscar
 * @return Iterador apuntando al país encontrado o al final si no se encuentra
 */
    iterator find(const Punto &p) {
        iterator it;
        set<Pais>::iterator i;
        for (i = datos.begin(); i != datos.end() && !(*i == p); ++i);
        it.p = i;
        return it;
    }

    /**
 * @brief Sobrecarga del operador de inserción >>
 * @param is Flujo de entrada
 * @param R Objeto Paises en el que se insertarán los países leídos
 * @return Referencia al flujo de entrada
 */
    friend istream &operator>>(istream &is, Paises &R) {
        Paises rlocal;
        // leemos el comentario
        if (is.peek() == '#') {
            string a;
            getline(is, a);
        }

        Pais P;

        while (is >> P) {
            rlocal.Insertar(P);
        }
        R = rlocal;
        return is;
    }

    /**
 * @brief Sobrecarga del operador de extracción <<
 * @param os Flujo de salida
 * @param R Objeto Paises que se imprimirá en el flujo de salida
 * @return Referencia al flujo de salida
 */
    friend ostream &operator<<(ostream &os, const Paises &R) {
        Paises::const_iterator it;

        for (it = R.begin(); it != R.end(); ++it) {
            os << *it << "\t";
        }
        return os;
    }
};

#endif
