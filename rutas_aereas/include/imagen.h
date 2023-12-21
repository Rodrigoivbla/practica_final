/**
 * @file imagen.h
 * @brief Fichero cabecera que gestiona las imágenes utilizadas
 */

#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <string>

enum Tipo_Pegado {OPACO, BLENDING};

using namespace std;

/**
 * @struct Pixel
 * @brief Estructura para representar un píxel de una imagen
 */
struct Pixel{
    unsigned char r,g,b; /**< Componentes RGB del píxel */
    unsigned char transp; /**< Transparencia del píxel: 0 no transparente, 255 completamente transparente */
};

/**
 * @class Imagen
 * @brief Clase para gestionar imágenes
 */
class Imagen{
private:
    Pixel ** data; /**< Matriz de píxeles */
    int nf,nc; /**< Número de filas y columnas */

    void Borrar(); /**< Método privado para liberar memoria */
    void Copiar(const Imagen &I); /**< Método privado para copiar una imagen */

public:
    /**
     * @brief Constructor por defecto de la clase Imagen
     */
    Imagen();

    /**
     * @brief Constructor que crea una imagen con dimensiones específicas
     * @param f Número de filas
     * @param c Número de columnas
     */
    Imagen(int f,int c);

    /**
     * @brief Constructor de copia de la clase Imagen
     * @param I Imagen a copiar
     */
    Imagen(const Imagen & I);

    /**
     * @brief Sobrecarga del operador de asignación para la clase Imagen
     * @param I Imagen a asignar
     * @return Referencia a la imagen asignada
     */
    Imagen & operator=(const Imagen & I);

    /**
     * @brief Destructor de la clase Imagen
     */
    ~Imagen();

    /**
     * @brief Obtiene el número de filas de la imagen
     * @return Número de filas
     */
    int get_rows() const;

    /**
     * @brief Obtiene el número de columnas de la imagen
     * @return Número de columnas
     */
    int get_cols() const;

    /**
     * @brief Obtiene el tamaño total de la imagen (filas * columnas)
     * @return Tamaño total de la imagen
     */
    int size() const;

    /**
     * @brief Operador de acceso a un píxel de la imagen (lectura y escritura)
     * @param i Fila del píxel
     * @param j Columna del píxel
     * @return Referencia al píxel especificado
     */
    Pixel & operator ()(int i,int j);

    /**
     * @brief Operador de acceso a un píxel de la imagen (lectura)
     * @param i Fila del píxel
     * @param j Columna del píxel
     * @return Constante referencia al píxel especificado
     */
    const Pixel & operator ()(int i,int j)const;

    /**
     * @brief Guarda la imagen en un archivo con el nombre especificado
     * @param nombre Nombre del archivo de salida
     */
    void EscribirImagen(const char * nombre);

    /**
     * @brief Lee una imagen desde un archivo con el nombre especificado
     * @param nombre Nombre del archivo de entrada
     * @param nombremascara Nombre del archivo de máscara (opcional)
     */
    void LeerImagen(const char *nombre,const string &nombremascara="");

    /**
     * @brief Limpia la transparencia de la imagen (establece a 0 la transparencia de todos los píxeles)
     */
    void LimpiarTransp();

    /**
     * @brief Obtiene el número de filas de la imagen
     * @return Número de filas
     */
    int num_filas()const{return nf;}

    /**
     * @brief Obtiene el número de columnas de la imagen
     * @return Número de columnas
     */
    int num_cols()const{return nc;}

    /**
     * @brief Coloca una imagen sobre otra en la posición especificada
     * @param posi Posición en fila de la imagen grande
     * @param posj Posición en columna de la imagen grande
     * @param I Imagen a colocar
     * @param tippegado Tipo de pegado: OPACO o BLENDING
     */
    void PutImagen(int posi, int posj, const Imagen &I, Tipo_Pegado tippegado=OPACO);

    /**
     * @brief Extrae una porción de la imagen
     * @param posi Posición en fila de la imagen a extraer
     * @param posj Posición en columna de la imagen a extraer
     * @param dimi Número de filas de la porción a extraer
     * @param dimj Número de columnas de la porción a extraer
     * @return Imagen resultante de la extracción
     */
    Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);

    /**
     * @brief Obtiene una nueva imagen que es la versión rotada de una imagen de entrada
     * @param Io Imagen de entrada
     * @param angulo Ángulo para rotar la imagen de entrada (en radianes)
     * @return Nueva imagen que es la versión rotada de Io
    **/
    Imagen Rota(const Imagen & Io,double angulo);
};

#endif
