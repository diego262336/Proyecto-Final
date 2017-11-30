#include "Cocina.h"
#include <string>
#include<stdlib.h>
Cocina::Cocina()
{

}
//ingresa valores al txt

void Cocina::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad,string miTipo)
{
    string line;
    ofstream readIn;
    readIn.open("Cocina.txt", ios::app | ios::in );
    if( readIn.is_open() )
    {
        readIn<<miCodigo <<' '<<miNombre<<' '<<miCategoria<<' '<<miPrecio<<' '<<miCantidad<<' '<<miTipo<<endl;
        cout<<"Se ingresaron los datos correctamente:\n\n";
        readIn.close();
    }
    else
    {
        cout<<"Error al ingresar a la base de datos\n";
    }
    ifstream readOut;
    readOut.open("Cocina.txt", ios::out );
    if (readOut.is_open())
      {
        while ( getline (readOut,line) )
        {
          cout << line << '\n';
        }
      }
    else
    {
        cout<<"No se pudo ingresar a la base de datos\n";
    }
    readOut.close();
}

//muestra todos los productos
void Cocina::getData()
{
    ifstream readOut;
    readOut.open("Cocina.txt");
    string line;
    while( getline(readOut,line) )
    {
        cout << line << '\n';
    }
}


string Cocina::getCategoria()
{
    ifstream readOut;
    readOut.open("Cocina.txt", ios::out );
    readOut >> codigo >> nombre >> categoria >> precio >> cantidad >> tipo;
    return categoria;
}

string Cocina::getNombre(string miCodigo)
{
    ifstream readOut;
    readOut.open("Cocina.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo )
        {
            if(codigo==miCodigo)
            {
                    break;
            }
        }
        readOut.close();
    }
    return nombre;
}

string Cocina::getCodigo()
{
    return codigo;
}

float Cocina::getPrecio(string miCodigo)
{
    ifstream readOut;
    readOut.open("Cocina.txt", ios::out);
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo )
        {
            if(codigo==miCodigo)
            {
                break;
            }
        }
        readOut.close();
    }
    else
    {
        cout<<"No se pudo accesar a la base de datos"<<endl;
    }
    return precio;
}

int Cocina::getCantidad(string miCodigo)
{
    ifstream readOut;
    readOut.open("Cocina.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo )
        {
            if(codigo==miCodigo)
            {
                    break;
            }
        }
        readOut.close();
    }
    return cantidad;
}

//singleton
Cocina* Cocina::instance=0;

Cocina* Cocina::getInstance()
{
    if (instance == 0)
        instance = new Cocina();
    return instance;
}

//Muestra un producto segun el codigo ingresado
void Cocina::getProducto(string miCodigo)
{
    ifstream readOut;
    readOut.open("Cocina.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo )
        {
            if(codigo==miCodigo)
            {
                cout<< "Datos del Producto:"        <<endl
                    <<"Codigo: "<<codigo            <<endl
                    <<"Nombre: "<<nombre            <<endl
                    <<"Categoria: "<<categoria      <<endl
                    <<"Precio: $"<<precio           <<endl
                    <<"Stock: "<<cantidad           <<endl
                    <<"Tipo: "<<tipo          <<endl<<endl<<endl;
                    break;
            }
        }
        readOut.close();
    }
}


//Modifica la cantidad, usada en la opcion 5
void Cocina::modificar_Cantidad(string miCodigo, int stock)
{
        ifstream readOut;
        readOut.open("Cocina.txt");
        ofstream readIn;
        readIn.open("temp.txt");
        while ( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo )
        {
            if ( miCodigo != codigo)
            {
                readIn << codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << cantidad << ' ' << tipo <<endl;            }
            else
            {
                readIn << codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << stock << ' ' << tipo <<endl;            }
        }
    readIn.close();
    readOut.close();
    remove("Cocina.txt");
    rename("temp.txt","Cocina.txt");
    cout <<endl<<endl<<endl;
}
