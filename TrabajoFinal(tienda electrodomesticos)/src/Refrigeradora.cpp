#include "Refrigeradora.h"

#include <string>
Refrigeradora::Refrigeradora()
{

}


void Refrigeradora::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miTipo, string miCaracteristica,string miTamanho)
{
    string line;
    ofstream readIn;
    readIn.open("Refrigeradora.txt", ios::app | ios::in );
    if( readIn.is_open() )
    {
        readIn<< miCodigo << ' ' << miNombre << ' ' << miCategoria << ' ' << miPrecio << ' ' << miCantidad << ' ' << miTipo << ' ' << miCaracteristica << ' ' << miTamanho <<endl;
        cout<<"Se ingresaron los datos correctamente:\n\n";
        readIn.close();
    }
    else
    {
        cout<<"Error al ingresar a la base de datos\n";
    }
    ifstream readOut;
    readOut.open("Refrigeradora.txt", ios::out );
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

void Refrigeradora::getData()
{
    ifstream readOut;
    string line;
    readOut.open("Refrigeradora.txt");
    while( getline(readOut,line) )
    {
        cout << line << '\n';
    }
}

string Refrigeradora::getCategoria()
{
    return categoria;
}

string Refrigeradora::getNombre(string miCodigo)
{
    ifstream readOut;
    readOut.open("Refrigeradora.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo >> caracteristicas >> tamanho )
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

string Refrigeradora::getCodigo()
{
    return codigo;
}

float Refrigeradora::getPrecio(string miCodigo)
{
    ifstream readOut;
    readOut.open("Refrigeradora.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo >> caracteristicas >> tamanho )
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

int Refrigeradora::getCantidad(string miCodigo)
{
    ifstream readOut;
    readOut.open("Refrigeradora.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo >> caracteristicas >> tamanho )
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

Refrigeradora* Refrigeradora::instance=0;

Refrigeradora* Refrigeradora::getInstance()
{
    if (instance == 0)
        instance = new Refrigeradora();
    return instance;
}


void Refrigeradora::getProducto(string miCodigo)
{
    ifstream readOut;
    readOut.open("Refrigeradora.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo >> caracteristicas >> tamanho )
        {
            if(codigo==miCodigo)
            {
                cout<< "Datos del Producto:"                <<endl
                    <<"Codigo: "<<codigo                    <<endl
                    <<"Nombre: "<<nombre                    <<endl
                    <<"Categoria: "<<categoria              <<endl
                    <<"Precio: $"<<precio                   <<endl
                    <<"Stock: "<<cantidad                   <<endl
                    <<"Tipo: "<<tipo                        <<endl
                    <<"Caracteristica: "<<caracteristicas   <<endl
                    <<"Tamanho: "<<tamanho                  <<endl<<endl<<endl;
                break;
            }
        }
    readOut.close();
    }
}


void Refrigeradora::modificar_Cantidad(string miCodigo, int stock)
{
        ifstream readOut;
        readOut.open("Refrigeradora.txt");
        ofstream readIn;
        readIn.open("temp.txt");
        while ( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo >> caracteristicas >> tamanho )
        {
            if ( miCodigo != codigo)
            {
                readIn<<codigo<<' '<<nombre<<' '<<categoria<<' '<<precio<<' '<<cantidad<<' '<<tipo<<' '<<caracteristicas<<' '<<tamanho<<endl;            }
            else
            {
                readIn<<codigo<<' '<<nombre<<' '<<categoria<<' '<<precio<<' '<<stock<<' '<<tipo<<' '<<caracteristicas<<' '<<tamanho<<endl;            }
    }
    readIn.close();
    readOut.close();
    remove("Refrigeradora.txt");
    rename("temp.txt","Refrigeradora.txt");
    cout <<endl<<endl<<endl;
}
