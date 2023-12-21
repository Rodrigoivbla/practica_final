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
 * @brief Estructura para representar un píxel de una imagen a color.
 */
struct Pixel{
  /**
   * @brief Valor del color rojo del pixel.
  **/
  unsigned char r;
  
  /**
   * @brief Valor del color verde del pixel.
  **/
  unsigned char g;

  /**
   * @brief Valor del color azul del pixel.
  **/
  unsigned char b;

  /**
   * @brief Indica el nivel de transparencia del pixel. 0 indica opaco y 255 totalmente transparente.
  */
  unsigned char transp; //0 no 255 si
}; 

/**
  @brief T.D.A. Imagen

  Una instancia del tipo de dato abstracto Imagen nos permite almacenar imágenes a color.
  La imagen está representada por un array bidimensional de pixeles de tamaño filas x columnas, cada uno compuesto por tres colores (rojo, verde, azul), y con una transparencia.

  El TDA Imagen proporciona además distintas herramientas para la manipulación de dichas imágenes.

  Para poder usar el TDA Imagen se debe incluir el fichero

  \#include <imagen.h>

  @author Rodrigo Ibáñez Blanco
  @author Brandon Rene Morales Viracocha
  @date Diciembre 2023
**/
class Imagen{
  private:
    /**
      @brief Puntero a la imagen almacenada

      img apunta a un array-2D dinámico de Pixeles que contiene la imagen en sí. Almacena tantas celdas como pixeles tenga la imagen.

    **/
    Pixel ** data;

    /**
      @brief Número de filas de la imagen.
    **/
    int nf;

    /**
     * @brief Número de columnas de la imagen.
    **/
    int nc;

    /**
      * @brief Borra una imagen
      *
      * Libera la memoria reservada en la que se almacenaba la imagen que llama a la función.
      * Si la imagen estaba vacía no hace nada.
    **/
    void Borrar();

    /**
      @brief Copia una imagen.
      @param I Referencia a la imagen original que vamos a copiar.
      @pre Asume que no hay memoria reservada o se ha llamado antes a Destroy().
      @pre Asume this != &orig
    **/
    void Copiar(const Imagen &I);

  public:
    /**
     * @brief Constructor por defecto.
     * @post Genera una instancia de la clase Imagen con O filas y O colunmas.
     * @return Imagen, el objeto imagen creado.
    **/
    Imagen();

    /**
      * @brief Constructor con parámetros.
      * @param f Número de filas de la imagen.
      * @param c Número de columnas de la imagen.
      * @pre Asume que f > 0 y c > 0
      * @post La imagen creada es de f y c columnas. Estará inicializada al valor por defecto.
      * @return Imagen, el objeto imagen creado.
    **/
    Imagen(int f,int c);

    /**
     * @brief Constructor de copia de la clase Imagen.
     * @param I Imagen a copiar.
     * @return Imagen, el objeto imagen creado.
     */
    Imagen(const Imagen & I);

    /**
     * @brief Sobrecarga del operador de asignación para la clase Imagen.
     * @param I Referencia a la imagen a copiar.
     * @return Referencia a la imagen asignada.
     * @post Destruye cualquier información que contuviera previamente la imagen que llama al operador de asignación.
     */
    Imagen & operator=(const Imagen & I);

    /**
     * @brief Destructor de la clase Imagen.
     * @return void.
     * @post El objeto Imagen destruido no puede usarse salvo que se haga sobre él una operacion Imagen().
     */
    ~Imagen();

    /**
     * @brief Obtiene el tamaño total de la imagen (filas * columnas).
     * @return Tamaño total de la imagen.
     * @post La imagen no se modifica.
     */
    int size() const;

    /**
     * @brief Operador de acceso a un píxel de la imagen (lectura y escritura).
     * @param i Fila del píxel.
     * @param j Columna del píxel.
     * @pre i >= 0 y i < nf
     * @pre j >= 0 y j < nc
     * @return Referencia al píxel especificado.
     */
    Pixel & operator ()(int i,int j);

    /**
     * @brief Operador de acceso a un píxel de la imagen (lectura).
     * @param i Fila del píxel.
     * @param j Columna del píxel.
     * @pre i >= 0 y i < nf
     * @pre j >= 0 y j < nc
     * @return Referencia constante al píxel especificado.
     * @post La imagen no se modifica.
     */
    const Pixel & operator ()(int i,int j)const;

    /**
     * @brief Guarda la imagen en un archivo con el nombre especificado.
     * @param nombre Nombre del archivo de salida.
     */
    void EscribirImagen(const char * nombre);

    /**
     * @brief Lee una imagen desde un archivo con el nombre especificado.
     * @param nombre Nombre del archivo de entrada.
     * @param nombremascara Nombre del archivo de máscara (opcional).
     */
    void LeerImagen(const char *nombre,const string &nombremascara="");

    /**
     * @brief Limpia la transparencia de la imagen (establece a 0 la transparencia de todos los píxeles).
     */
    void LimpiarTransp();

    /**
     * @brief Obtiene el número de filas de la imagen.
     * @return Número de filas.
     * @post La imagen no se modifica.
     */
    int num_filas()const{return nf;}

    /**
     * @brief Obtiene el número de columnas de la imagen.
     * @return Número de columnas.
     * @post La imagen no se modifica.
     */
    int num_cols()const{return nc;}

    /**
     * @brief Coloca una imagen sobre otra en la posición especificada.
     * @param posi Fila correspondiente a la esquina superior izquierda sobre la que comienza el pegado.
     * @param posj Columna correspondiente a la esquina superior izquierda sobre la que comienza el pegado.
     * @param I Imagen a colocar.
     * @param tippegado Tipo de pegado: OPACO o BLENDING. El tipo por defecto es OPACO.
     * @pre nf >= posi + I.nf
     * @pre nc >= posj + I.nc
     */
    void PutImagen(int posi, int posj, const Imagen &I, Tipo_Pegado tippegado=OPACO);

    /**
     * @brief Extrae una porción de la imagen.
     * @param posi Fila correspondiente a la esquina superior izquierda sobre la que comienza la extracción.
     * @param posj Columna correspondiente a la esquina superior izquierda sobre la que comienza la extracción.
     * @param dimi Número de filas de la porción a extraer.
     * @param dimj Número de columnas de la porción a extraer.
     * @return Imagen resultante de la extracción.
     */
    Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);

    /**
     * @brief Obtiene una nueva imagen que es la versión rotada de una imagen de entrada.
     * @param Io Imagen de entrada.
     * @param angulo Ángulo para rotar la imagen de entrada (en radianes).
     * @return Nueva imagen que es la versión rotada de Io.
    **/
    Imagen Rota(const Imagen & Io,double angulo);
};

#endif
