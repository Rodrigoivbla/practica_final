
#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <string>

enum Tipo_Pegado {OPACO, BLENDING};

using namespace std;

struct Pixel{
  unsigned char r,g,b;
  unsigned char transp; //0 no 255 si
};  

class Imagen{
  private:
    Pixel ** data;
    int nf,nc;
    void Allocate(int nrows, int ncols, Pixel * buffer);
    void Initialize(int nrows, int ncols, Pixel * buffer = 0);
    void Borrar();
    void Copiar(const Imagen &I);

  public:
    Imagen();
    
    Imagen(int f,int c);
    
    Imagen(const Imagen & I);
    
    Imagen & operator=(const Imagen & I);
    
    ~Imagen();
    
    void set_pixel(int i, int j, Pixel value);
    void set_pixel(int k, Pixel value);
    int get_rows() const;
    int get_cols() const;
    int size() const;
    Pixel get_pixel(int i, int j) const;
    Pixel get_pixel(int k) const;
    
    Pixel & operator ()(int i,int j);
    
    const Pixel & operator ()(int i,int j)const;
    
    void EscribirImagen(const char * nombre);
    
    void LeerImagen (const char *nombre,const string &nombremascara="");
    void LimpiarTransp();
    int num_filas()const{return nf;}
    int num_cols()const{return nc;}
    void PutImagen(int posi, int posj, const Imagen &I, Tipo_Pegado tippegado=OPACO);
    Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);

    /** 
     * @brief Obtiene una nueva imagen que es la versión rotada de una imagen de entrada
     * @param Io: imagen de entrada
     * @param angulo: angulo a rotar la imagen de entrada. Debe estar en radianes.
     * @return Una nueva imagen que es la versión rotada de Io.
    **/
    Imagen Rota(const Imagen & Io,double angulo);
}; 

#endif