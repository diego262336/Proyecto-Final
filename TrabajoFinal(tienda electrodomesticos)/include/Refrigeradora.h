#ifndef REFRIGERADORA_H
#define REFRIGERADORA_H
#include "Producto.h"
#include <fstream>
class Refrigeradora : public Producto
{
    private:
        string tipo,caracteristicas,tamanho;
        Refrigeradora();
        static Refrigeradora* instance;
    public:
        static Refrigeradora* getInstance();
        void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miTipo, string miCaracteristica, string miTamanho);
        void getData();
        string getCategoria();
        string getNombre(string miCodigo);
        string getCodigo();
        float getPrecio(string miCodigo);
        int getCantidad(string miCodigo);
        void getProducto(string codigo);
        void modificar_Cantidad(string miCodigo, int stock);
};

#endif // REFRIGERADORA_H
