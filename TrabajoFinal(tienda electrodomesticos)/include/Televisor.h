#ifndef TELEVISOR_H
#define TELEVISOR_H
#include "Producto.h"
#include <fstream>
class Televisor : public Producto
{
    private:
        // codigo letra,calidad,caracteristicas,tipo del pantalla, tamaño
        float tam;
        string caracteristicas,pantallaTy,calidad;
        Televisor();
        static Televisor* instance;
    public:
        static Televisor* getInstance();
        void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miCalidad, string miCaracteristicas,string mipantallaTy, float miTam);
        void getData();
        string getCategoria();
        string getNombre(string miCodigo);
        string getCodigo();
        float getPrecio(string miCodigo);
        int getCantidad(string miCodigo);
        void getProducto(string codigo);
        void modificar_Cantidad(string miCodigo, int stock);
};
#endif // TELEVISOR_H
