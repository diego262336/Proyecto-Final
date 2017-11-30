#include "Televisor.h"
#include <string>
Televisor::Televisor()
{

}

void Televisor::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miCalidad, string miCaracteristicas,string mipantallaTy, float miTam)
{
    string line;
    ofstream readIn;
    readIn.open("Televisor.txt", ios::app | ios::in );
    if( readIn.is_open() )
    {
        readIn<< miCodigo << ' ' << miNombre << ' ' << miCategoria << ' ' << miPrecio << ' ' << miCantidad << ' ' << miCalidad << ' ' << miCaracteristicas << ' ' << mipantallaTy << ' ' << miTam <<endl;
        cout<<"Se ingresaron los datos correctamente:\n\n";
        readIn.close();
    }
    else
    {
        cout<<"Error al ingresar a la base de datos\n";
    }
    ifstream readOut;
    readOut.open("Televisor.txt", ios::out );
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

void Televisor::getData()
{
    ifstream readOut;
    string line;
    readOut.open("Televisor.txt");
    while( getline(readOut,line) )
    {
        cout << line << '\n';
    }
}

string Televisor::getCategoria()
{
    return categoria;
}

string Televisor::getNombre(string miCodigo)
{
    ifstream readOut;
    readOut.open("Televisor.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> calidad >> caracteristicas >> pantallaTy >> tam )
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

string Televisor::getCodigo()
{
    return codigo;
}

float Televisor::getPrecio(string miCodigo)
{
    ifstream readOut;
    readOut.open("Televisor.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> calidad >> caracteristicas >> pantallaTy >> tam )
        {
            if(codigo==miCodigo)
            {
                break;
            }
        }
        readOut.close();
    }
    return precio;
}

int Televisor::getCantidad(string miCodigo)
{
    ifstream readOut;
    readOut.open("Televisor.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> calidad >> caracteristicas >> pantallaTy >> tam )
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


Televisor* Televisor::instance=0;

Televisor* Televisor::getInstance()
{
    if (instance == 0)
        instance = new Televisor();
    return instance;
}

void Televisor::getProducto(string miCodigo)
{
    ifstream readOut;
    readOut.open("Televisor.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> calidad >> caracteristicas >> pantallaTy >> tam )
        {
            if(codigo==miCodigo)
            {

                cout<< "Datos del Producto:"<<endl
                    <<"Codigo: "<<codigo <<endl
                    <<"Nombre: "<<nombre<<endl
                    <<"Categoria: "<<categoria<<endl
                    <<"Precio: $"<<precio <<endl
                    <<"Stock: "<<cantidad <<endl
                    <<"Calidad: "<<calidad  <<endl
                    <<"Caracteristica: "<<caracteristicas <<endl
                    <<"Tipo de Pantalla: "<<pantallaTy <<endl
                    <<"Tamanho:  \""<<tam  <<endl<<endl<<endl;
                break;
            }
        }
        readOut.close();
    }
}

void Televisor::modificar_Cantidad(string miCodigo, int stock)
{
        ifstream readOut;
        readOut.open("Televisor.txt");
        ofstream readIn;
        readIn.open("temp.txt");
        while ( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> calidad >> caracteristicas >> pantallaTy >> tam )
        {
            if (miCodigo !=codigo)
            {
                readIn<<codigo<<' '<<nombre<<' '<<categoria<<' '<<precio<<' '<<cantidad<<' '<<calidad<<' '<<caracteristicas<<' '<<pantallaTy<<' '<<tam<<endl;
            }
            else
            {
                readIn<< codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << stock << ' ' << calidad << ' ' << caracteristicas << ' ' << pantallaTy << ' ' << tam <<endl;
            }
        }
    readIn.close();
    readOut.close();
    remove("Televisor.txt");
    rename("temp.txt","Televisor.txt");
    cout <<endl<<endl<<endl;
}
