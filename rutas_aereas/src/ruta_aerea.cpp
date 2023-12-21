/**
  * @file ruta_aerea.cpp
  * @brief Fichero con el programa principal
  *
  */

#include "imagen.h"
#include "paises.h"
#include "almacenRutas.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include "vector"

using namespace std;

/** 
 * @brief Obtiene una nueva imagen que es la versión rotada de una imagen de entrada
 * @param Io: imagen de entrada
 * @param angulo: angulo a rotar la imagen de entrada. Debe estar en radianes.
 * @return Una nueva imagen que es la versión rotada de Io.
 * */

Imagen Rota(const Imagen &Io, double angulo) {
    double rads = angulo;
    double coseno = cos(angulo);
    double seno = sin(angulo);

    //Para obtener las dimensiones de la imagen
    int rcorners[4], ccorners[4];
    int newimgrows, newimgcols;
    double new_row_min, new_col_min, new_row_max, new_col_max;
    double inter, inter1;

    rcorners[0] = 0;
    rcorners[1] = 0;
    ccorners[0] = 0;
    ccorners[2] = 0;

    rcorners[2] = Io.num_filas() - 1;
    rcorners[3] = Io.num_filas() - 1;
    ccorners[1] = Io.num_cols() - 1;
    ccorners[3] = Io.num_cols() - 1;

    new_row_min = 0;
    new_col_min = 0;
    new_row_max = 0;
    new_col_max = 0;
    newimgrows = 0;
    newimgcols = 0;

    for (int count = 0; count < 4; count++) {
        inter = rcorners[count] * coseno + ccorners[count] * seno;

        if (inter < new_row_min)
            new_row_min = inter;

        if (inter > new_row_max)
            new_row_max = inter;

        inter1 = -rcorners[count] * seno + ccorners[count] * coseno;

        if (inter1 < new_col_min)
            new_col_min = inter1;

        if (inter1 > new_col_max)
            new_col_max = inter1;
    }

    newimgrows = (unsigned) ceil((double) new_row_max - new_row_min);
    newimgcols = (unsigned) ceil((double) new_col_max - new_col_min);

    Imagen Iout(newimgrows, newimgcols);

    for (int rows = 0; rows < newimgrows; rows++) {
        for (int cols = 0; cols < newimgcols; cols++) {
            float oldrowcos = ((float) rows + new_row_min) * cos(-rads);
            float oldrowsin = ((float) rows + new_row_min) * sin(-rads);
            float oldcolcos = ((float) cols + new_col_min) * cos(-rads);
            float oldcolsin = ((float) cols + new_col_min) * sin(-rads);

            float old_row = oldrowcos + oldcolsin;
            float old_col = -oldrowsin + oldcolcos;

            old_row = ceil((double) old_row);
            old_col = ceil((double) old_col);

            if ((old_row >= 0) && (old_row < Io.num_filas()) &&
                (old_col >= 0) && (old_col < Io.num_cols())) {
                Iout(rows, cols) = Io(old_row, old_col);

            } else {
                Iout(rows, cols).r = Iout(rows, cols).g = Iout(rows, cols).b = 255;
                Iout(rows, cols).transp = 0;
            }
        }
    }

    return Iout;
}



/**
 * @brief Dibuja la representación de un avión entre dos puntos dados en una imagen.
 * @param f1 Coordenada de fila del primer punto.
 * @param f2 Coordenada de fila del segundo punto.
 * @param c1 Coordenada de columna del primer punto.
 * @param c2 Coordenada de columna del segundo punto.
 * @param I Imagen donde se dibujará la representación del avión.
 * @param avion Imagen que representa al avión a dibujar.
 * @param mindisf Mínima distancia en filas para dibujar el avión.
 * @param mindisc Mínima distancia en columnas para dibujar el avión.
 */
void Pintar(int f1, int f2, int c1, int c2, Imagen &I, const Imagen &avion, int mindisf, int mindisc) {
    int fila, col;

    if (abs(f2 - f1) >= mindisf || abs(c2 - c1) >= mindisc) {
        if (c1 != c2) {
            double a, b;
            a = double(f2 - f1) / double(c2 - c1);
            b = f1 - a * c1;
            col = (int) (c1 + c2) / 2;
            fila = (int) rint(a * col + b);
        } else {
            col = c1;
            fila = (f1 + f2) / 2;
        }

        double angulo = atan2((f2 - f1), (c2 - c1));
        Imagen Irota = Rota(avion, angulo);
        I.PutImagen(fila, col, Irota, OPACO);//pensar si debe ser opaco o blending

        angulo = atan2((f2 - fila), (c2 - col));
        Irota = Rota(avion, angulo);
        I.PutImagen(f2, c2, Irota, OPACO);//pensar si debe ser opaco o blending

        angulo = atan2((fila - f1), (col - c1));
        Irota = Rota(avion, angulo);
        I.PutImagen(f1, c1, Irota, OPACO);//pensar si debe ser opaco o blending
    }
}

int main(int argc, char *argv[]) {

    if (argc != 7) {
        cout << "Los parametros son:" << endl;
        cout << "1.-Fichero con la informacion de los paises" << endl;
        cout << "2.-Nombre de la imagen con el mapa del mundo" << endl;
        cout << "3.-Directorio con las banderas" << endl;
        cout << "4.-Fichero con el almacen de rutas" << endl;
        cout << "5.- Nombre de la imagen con el avion" << endl;
        cout << "6.- Nombre de la imagen de la mascara del avion" << endl;

        return 0;
    }

    Paises Pses;
    ifstream f(argv[1]);
    f >> Pses;
    // cout << Pses;

  Imagen I;
  I.LeerImagen(argv[2]);
  
  // Leemos los aviones 
  Imagen avion;
  avion.LeerImagen(argv[5], argv[6]);
  
  Almacen_Rutas Ar;
  f.close();
  f.open(argv[4]);
  f >> Ar;
  cout << "Las rutas: " << endl << Ar;
  cout << "Dime el codigo de una ruta" << endl;
  string a;
  cin >> a;
  Ruta R = Ar.GetRuta(a);

  
  Ruta::iterator it_r, it_r_anterior;
  Paises::iterator it_p = Pses.end(), it_p_anterior = Pses.end();
  Imagen bandera_ini;
  int i_ini, j_ini;

  for(it_r = R.begin(); it_r != R.end(); ++it_r) 
  {
    Punto pto = (*it_r);
      
    it_p_anterior = it_p;
    it_p = Pses.find(pto);

    cout << (*it_p).GetPais() << " ";
      
    string name = (*it_p).GetBandera();
    string n_com = argv[3] + name;
      
    Imagen bandera;
    bandera.LeerImagen(n_com.c_str(), "");
	
    int x = (int)((I.num_cols() / 360.0) * (180 + pto.getLongitud()));
	  int y = (int)((I.num_filas() / 180.0) * (90-pto.getLatitud()));
	
    if(it_p_anterior != Pses.end()) 
    {
	    int x_old = (int)((I.num_cols() / 360.0) * (180 + (*it_r_anterior).getLongitud()));
	    int y_old = (int)((I.num_filas() / 180.0) * (90 - (*it_r_anterior).getLatitud()));
	  
	    Pintar(y_old - avion.num_filas() / 2, y - avion.num_filas() / 2, 
             x_old - avion.num_cols() / 2, x - avion.num_cols() / 2, 
             I, avion, 50, 50);
	  }
	  
	  I.PutImagen(y - bandera.num_filas() / 2, x - bandera.num_cols() / 2, bandera, BLENDING);
	
    if(it_p != Pses.begin())
	    I.PutImagen(i_ini - bandera_ini.num_filas() / 2, j_ini - bandera_ini.num_cols() / 2, bandera_ini, BLENDING);

	  bandera_ini = bandera;
    it_r_anterior = it_r;
	  i_ini = y;
	  j_ini = x;
  }	
  
  cout << endl;
      
  string nuevo_mapa = "mapa_" + a + ".ppm";
  I.EscribirImagen(nuevo_mapa.c_str());
}