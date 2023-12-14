
#ifndef _ALMACEN_RUTAS_H_
#define _ALMACEN_RUTAS_H_

#include "ruta.h"
#include <map>

class Almacen_Rutas{
  private:
    map<string, Ruta> almacen;

  public:
    Almacen_Rutas() {}

    Ruta GetRuta(const string &s)
    {
        return almacen[s];
    }

    void Insertar(const Ruta &R)
    {
        almacen[R.getNombre()] = R;
    }

    void Borrar(const string &s)
    {
        almacen.erase(s);
    }

    class const_iterator;
    class iterator
    {
    private:
        map<string, Ruta>::iterator p;

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

        const pair<string, Ruta>& operator*() const
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

        friend class Almacen_Rutas;
        friend class const_iterator;
    };

    class const_iterator
    {
    private:
        map<string, Ruta>::const_iterator p;

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

        const pair<string, Ruta>& operator*() const
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

        friend class Almacen_Rutas;
    };

    iterator begin()
    {
        iterator it;
        it.p = almacen.begin();
        return it;
    }

    const_iterator begin() const 
    {
        const_iterator it;
        it.p = almacen.begin();
        return it;
    } 
    
    iterator end()
    {
        iterator it;
        it.p = almacen.end();
        return it;
    }
    
    const_iterator end() const 
    {
        const_iterator it;
        it.p = almacen.end();
        return it;
    }

    iterator find(const string &s)
    {
        iterator it;
        map<string, Ruta>::iterator i;
        for (i = almacen.begin(); i != almacen.end() && !((*i).first == s); ++i);
        it.p = i;
        return it;
    }

    friend istream &operator>>(istream &is, Almacen_Rutas &AR)
    {
        Almacen_Rutas arlocal;
        // leemos el comentario
        if (is.peek() == '#')
        {
            string a;
            getline(is, a);
        }

        Ruta R;
        
        while (is >> R)
        {
            arlocal.Insertar(R);
        }
        
        AR = arlocal;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Almacen_Rutas &AR)
    {
        os << "#Rutas" << endl;
        map<string, Ruta>::const_iterator it;

        for (it = AR.almacen.begin(); it != AR.almacen.end(); ++it)
        {
            os << it->first << " " << it->second << "\t" << endl;
        }
        return os;
    }
};

#endif