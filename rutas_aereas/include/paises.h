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

    iterator begin() {
        iterator it;
        it.p = datos.begin();
        return it;
    }

    const_iterator begin() const {
        const_iterator it;
        it.p = datos.begin();
        return it;
    }

    iterator end() {
        iterator it;
        it.p = datos.end();
        return it;
    }

    const_iterator end() const {
        const_iterator it;
        it.p = datos.end();
        return it;
    }

    // Función para encontrar un país en el conjunto según el nombre
    iterator find(const Pais &p)
    {
        iterator it;
        set<Pais>::iterator i;
        for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i);
        it.p = i;
        return it;
    }

    // Función para encontrar un país en el conjunto según su ubicación
    iterator find(const Punto &p)
    {
        iterator it;
        set<Pais>::iterator i;
        for (i = datos.begin(); i != datos.end() && !(*i == p); ++i);
        it.p = i;
        return it;
    }

    // Sobrecarga del operador de inserción >>
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

    // Sobrecarga del operador de extracción <<
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
