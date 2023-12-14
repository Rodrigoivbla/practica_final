
#ifndef _RUTA_H_
#define _RUTA_H_

#include "punto.h"
#include <string>
#include <list>

class Ruta{
  private:
    string nombre;
    list<Punto> ruta;

  public:
    string getNombre() const
    {
        return nombre;
    }

    list<Punto> getRuta() const
    {
        return ruta;
    }

    void Insertar(const Punto &p)
    {
        ruta.push_back(p);
    }

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

    iterator find(const Punto &p)
    {
        iterator it;
        list<Punto>::iterator i;
        for (i = ruta.begin(); i != ruta.end() && !(*i == p); ++i);
        it.p = i;
        return it;
    }

    bool operator!=(const Ruta &R)
    {
        if(nombre == R.nombre)
        {
            return true;
        }

        if(ruta.size() != R.ruta.size())
        {
            return true;
        }

        const_iterator r_it = R.begin();

        for(iterator it = begin(); it != end() && r_it != R.end(); ++it, ++r_it)
        {
            if(*it != *r_it)
                return true;
        }
    }

    friend istream &operator>>(istream &is, Ruta &R)
    {
        Ruta rlocal;

        int n_loc;
        Punto P;
        
        is >> rlocal.nombre;
        is >> n_loc;

        for(int i = 0; i < n_loc; ++i)
        {
            is >> P;
            rlocal.Insertar(P);
        }

        R = rlocal;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Ruta &R)
    {
        const_iterator it;

        os << R.ruta.size();

        for (it = R.begin(); it != R.end(); ++it)
        {
            os << " " << *it << "\t";
        }

        return os;
    }
};

#endif