#ifndef COCINA_H
#define COCINA_H
#include "Producto.h"
#include "fstream"
class Cocina : public Producto
{
    private:
        string tipo;
        Cocina();
        static Cocina * instance;
    public:
        static Cocina* getInstance();
        void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad,string miTipo);
        void getData();
        string getCategoria();
        string getNombre(string miCodigo);
        string getCodigo();
        float getPrecio(string miCodigo);
        int getCantidad(string miCodigo);
        void getProducto(string codigo);
        void modificar_Cantidad(string miCodigo, int stock);
};

#endif // COCINA_H
