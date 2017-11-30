#ifndef CLIENTES_H
#define CLIENTES_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Clientes
{
    private:
        char sexo;
        string nombre,direccion;
        int edad,codigo;
        float capital;
    public:
        Clientes();
        void setData(string miNombre, string miDireccion, int miEdad, char miSexo, float miCapital, int miCodigo);
        string getNombre() { return nombre; }
        string getDireccion() { return direccion; }
        char getSexo() { return sexo; }
        float getCapital() { return capital; }
        int getEdad() { return edad; }
        int getCodigo() { return codigo; }
        bool verificar_Code(string code);
        float getCapital(string miCodigo);
};

template<class T>
class client_ : public Clientes
{
public:
    // se elimina a un cliente de la cola
    void pop(string deleteCliente)
    {
        string line,nombre,codigo,direccion,edad,sexo,capital;
        string miCodigo;
        ifstream readOut;
        readOut.open("Clientes.txt");

        ofstream readIn;
        readIn.open("temp.txt");
        while ( readOut >> miCodigo >> nombre >> direccion >> edad >> sexo >> capital )
        {
            if ( miCodigo != deleteCliente)
            {
                readIn << miCodigo << ' ' << nombre << ' ' << direccion << ' ' << edad << ' ' << sexo << ' ' << capital << endl;
            }
        }
        readIn.close();
        readOut.close();
        remove("Clientes.txt");
        rename("temp.txt","Clientes.txt");
        cout <<endl;
    }

    // se ingresa al txt de clientes
    void push(Clientes &c)
    {
        ofstream readIn;
        readIn.open("Clientes.txt", ios::app | ios::in);
        readIn << c.getCodigo() << ' ' << c.getNombre() << ' ' << c.getDireccion() << ' ' << c.getEdad() << ' ' << c.getSexo() << ' ' << c.getCapital() <<endl;
        readIn.close();
    }

    // para mostrar a un cliente, toda su informacion
    friend ostream& operator<<(ostream &o, client_<T> &c)
    {
        string line,nombre,codigo,direccion,edad,sexo,capital;
        int i=1;
        ifstream readOut;
        readOut.open("Clientes.txt", ios::out );
        if(readOut.is_open())
        {
            while( readOut >> codigo >> nombre >> direccion >> edad >> sexo >> capital )
            {
                o   <<"Datos del cliente "<<i<<":" <<endl
                    <<"Codigo: "<<codigo            <<endl
                    <<"Nombre: "<<nombre            <<endl
                    <<"Direccion: "<<direccion      <<endl
                    <<"Edad: "<<edad                <<endl
                    <<"Sexo: "<<sexo                <<endl
                    <<"Capital: $"<<capital         <<endl<<endl<<endl;
                i++;
            }
        }
        else
        {
            o<<"No se pudo ingresar a la base de datos"<<endl;
        }
        readOut.close();
        return o;
    }
};

#endif // CLIENTES_H
