#ifndef MENU_H
#define MENU_H
#include "Clientes.h"
#include "Producto.h"
#include "Televisor.h"
#include "Cocina.h"
#include "Refrigeradora.h"
#include <iostream>
#include <map>
#include <string>


using namespace std;

//Declaracion de funciones
void comprobar2Op(int &x);
void comprobar3Op(int &x);
void comprobar4Op(int &x);
void comprobar5Op(int &x);
void comprobar6Op(int &x);
void comprobar8Op(int &x);
void printMenu();
void printCategorias();
void printComponentes();

//Variables globales
int p0,p1,p2,p3;
int op,cat,lo;
int edad,cantidad;
float precio,capital;
string direccion,tipo,categoria;
char nombre[30],sexo;

//Clase normal
Clientes clientes;
//Clases Singleton
Cocina* cocina = Cocina::getInstance();
Televisor *televisor = Televisor::getInstance();
Refrigeradora *refrigeradora = Refrigeradora::getInstance();
client_<Clientes*> Cola;



// Command Interface
class Comando
{
public:
    virtual void execute()=0;
    virtual ~Comando() {}
};

// Receiver Class
class Opcion
{
public:
    void op1()
    {
        cout<<"Se ingreso a la opcion 1\n\n";
        ifstream readOut;
        readOut.open("CodCliente.txt", ios::out );
        ofstream Modify;
        Modify.open("CodCliente.txt", ios::in);
        if (readOut.is_open())
          {
            int a=0;
            string line;
            while ( getline (readOut,line) )
            {
                a+=line.size()+1;
                if(line=="codigos")
                {
                    getline(readOut,line);
                    a+=line.size();
                    p0=atoi(line.c_str());
                    p0++;
                    cout << p0 << '\n';
                    Modify.seekp(a);
                    Modify<< p0;
                    Modify.close();
                    readOut.close();
                    break;
                }
            }
          }
        else
        {
            //cout<<"error\n";
        }

        //datos del cliente
        cout<<"\nDatos del cliente "<<p0<<": \n\n";
        cout<<"Ingrese el nombre: "; cin>>nombre;
        cout<<"Ingrese la direccion: "; cin>>direccion;
        cout<<"Ingrese la edad: "; cin>>edad;
        cout<<"Ingrese el sexo: "; cin>>sexo;
        cout<<"Ingrese su capital: "; cin>>capital;
        cout<<endl<<endl;
        string nom=nombre;


        clientes.setData(nom,direccion,edad,sexo,capital,p0);
        Cola.push(clientes);
        cout<<Cola;
    }
    void op2()
    {
        printCategorias(); cin>>cat;
        comprobar5Op(cat);
        switch(cat)
        {
            case 1:
                {
                 //Cocinas

                    char *cocin_a= new char[3]; //codigo
                    int *r=new int;

                    string cod,nomb;
                    cocin_a[0]='C';

                    string componente;

                    cout<<"Ingrese el Nombre del Producto: ";
                    cin>>nombre;
                    nomb=nombre;

                    cout<<"Ingresar precio: ";
                    cin>>precio;

                    cout<<"Ingrese Cantidad: ";
                    cin>>cantidad;



                    cout<<"\n1. Componente"<<endl;
                    printComponentes();
                    cin>>*r;
                    comprobar8Op(*r);

                    switch(*r)
                    {
                    case 1:
                        componente="Quemadores"; break;
                    case 2:
                        componente="Grilla_del_quemador"; break;
                    case 3:
                        componente="Horno"; break;
                    case 4:
                        componente="Temporizador"; break;
                    case 5:
                        componente="electrica"; break;
                    case 6:
                        componente="gas"; break;

                    }
                    ifstream readOut;
                    readOut.open("codigos.txt", ios::out );

                    ofstream Modify;
                    Modify.open("codigos.txt", ios::in);

                    if (readOut.is_open() and Modify.is_open())
                      {
                        int a=0;
                        string line;
                        while ( getline (readOut,line) )
                        {
                            a+=line.size()+1;
                            if(line=="codigo2")
                            {
                                getline(readOut,line);
                                a+=line.size();
                                p1=atoi(line.c_str());
                                p1++;
                                cout << p1 << '\n';
                                Modify.seekp(a+2);
                                Modify <<p1;
                                Modify.close();
                                break;
                            }
                        }
                        readOut.close();
                      }
                    else
                    {
                        //cout<<"error\n";
                    }

                    cocin_a[1]='0'+p1;
                    cocin_a[2]='\0';
                    cod=cocin_a;
                    cocina->setData(nomb,precio,"cocina",cod,cantidad,componente);
                    delete r;
                    delete [] cocin_a;
                    break;
                }
            case 2:
                {
                    char *refrig=new char[3]; //codigo
                    int *r=new int;

                    string cod,nomb;
                    string caracteristica,tamanho,tipo;
                    refrig[0]='R';

                    cout<<"Ingrese el Nombre del Producto: ";
                    cin>>nombre;
                    nomb=nombre;

                    cout<<"Ingresar precio: ";
                    cin>>precio;

                    cout<<"Ingrese Cantidad: ";
                    cin>>cantidad;

                    cout<<"Ingrese el tamanho de la refrigeradora\n";
                    cin>>tamanho;

                    cout<<"\n\nCaracteristica: "<<endl
                        <<"1. No Frost" <<endl
                        <<"2. Frio Directo" <<endl;


                    cin>>*r;
                    comprobar2Op(*r);

                    (*r==1)? caracteristica="No Frost" :caracteristica="Frio Directo";

                    cout<<"\n1.Una puerta\n"
                        <<"2. Puertas deslizables"<<endl;
                        cin>>*r;
                    comprobar2Op(*r);

                    (*r==1)? tipo="Una puerta":tipo="Puertas deslizables";

                    ifstream readOut;
                    readOut.open("codigos.txt", ios::out );

                    ofstream Modify;
                    Modify.open("codigos.txt", ios::in);

                    if (readOut.is_open() and Modify.is_open())
                      {
                        int a=0;
                        string line;
                        while ( getline (readOut,line) )
                        {
                            a+=line.size()+1;
                            if(line=="codigo3")
                            {
                                getline(readOut,line);
                                a+=line.size()+1;
                                p2=atoi(line.c_str());
                                p2++;
                                cout << p2 << '\n';
                                Modify.seekp(a+2);
                                Modify <<p2;
                                Modify.close();
                                break;
                            }
                        }
                        readOut.close();
                      }
                    else
                    {
                        cout<<"error\n";
                    }

                    refrig[1]='0'+p2;
                    refrig[2]='\0';

                    cod=refrig;

                    refrigeradora->setData(nomb, precio, "Refrigeradora", cod, cantidad, tipo, caracteristica, tamanho);

                    delete r;
                    delete[] refrig;
                    break;
                }
            case 3:
                {
                    //television

                    char *tele=new char[3]; //codigo
                    int *r=new int;

                    string cod,nomb;
                    tele[0]='T';

                    cout<<"Ingrese el Nombre del Producto: ";
                    cin>>nombre;
                    nomb=nombre;

                    cout<<"Ingresar precio: ";
                    cin>>precio;

                    cout<<"Ingrese Cantidad: ";
                    cin>>cantidad;


                    string calidad, caracteristicas, pantallaTy; //Caracteristica pasar a array
                    float tam;

                    cout<<"Calidad"        <<endl
                        <<"1. HD"          <<endl
                        <<"2. Ultra HD"    <<endl
                        <<"3. Ultra HD 4K" <<endl;
                        cin>>*r;
                    comprobar3Op(*r);
                    (*r==1)? calidad="HD" : (*r==2)? calidad="Ultra_HD" : calidad="Ultra_HD_4K";

                    cout<<"Caracteristicas" <<endl
                        <<"1. Curvado"      <<endl
                        <<"2. Smart"        <<endl;
                        cin>>*r;
                        comprobar2Op(*r);
                        (*r==1)? caracteristicas="Curvado" : caracteristicas="Smart" ;

                    cout<<"Tipo de pantalla"<<endl
                        <<"1. LED"          <<endl
                        <<"2. LCD"          <<endl
                        <<"3. OLED"         <<endl;
                        cin>>*r;
                        comprobar3Op(*r);
                    (*r==1)? pantallaTy="LED" : (*r==2)? pantallaTy="LCD"  : pantallaTy="OLED" ;


                    cout<<"Ingrese el tamanho en pulgadas"<<endl;
                    cin>>tam;


                    ifstream readOut;
                    readOut.open("codigos.txt", ios::out );

                    ofstream Modify;
                    Modify.open("codigos.txt", ios::in);

                    if (readOut.is_open())
                      {
                        int a=0;
                        string line;
                        while ( getline (readOut,line) )
                        {
                            a+=line.size()+1;
                            if(line=="codigo5")
                            {
                                getline(readOut,line);
                                a+=line.size()+1;
                                p3=atoi(line.c_str());
                                p3++;
                                cout << p3 << '\n';
                                Modify.seekp(a+7);
                                Modify <<p3;
                                Modify.close();
                                break;
                            }
                        }
                      }
                    else
                    {
                        //cout<<"error\n";
                    }
                    readOut.close();

                    tele[1]='0'+p3;
                    tele[2]='\0';

                    cod=tele;

                    televisor->setData(nomb,precio,"television",cod,cantidad,calidad,caracteristicas,pantallaTy,tam);
                    delete r;
                    delete[] tele;
                    break;
                }
        }
    }
    void op3()
    {
        //Muestra todos los datos de todos los productos
        printCategorias();
        cin>>lo;
        comprobar5Op(lo);
        cout<<endl;
        switch(lo)
        {
             case 1:
                {
                    cocina->getData();
                    break;
                }
             case 2:
                {
                    refrigeradora->getData();
                    break;
                }
             case 3:
                {
                    televisor->getData();
                    break;
                }
        }
    }
    void op4()
    {
        cout<<endl;
        char* cod = new char[3];
        cout<<"Ingrese el codigo del producto a buscar: "; cin>>cod;
        cout<<endl;
        string codigo=cod;
        switch(cod[0])
        {
            case 'C': cocina->getProducto(codigo); break;
            case 'R': refrigeradora->getProducto(codigo); break;
            case 'T': televisor->getProducto(codigo); break;
            default: cout<<"No existe el codigo del producto"<<endl; break;
        }
    }
    void op5()
    {
        int compra;
        vector <int> precios;
        map <int,int> stocks;
        vector <int> compras;
        string codCliente;
        char codProducto[3];
        int num;

        cout<<"Ingrese el Codigo del Cliente: "; cin>>codCliente;
        if( clientes.verificar_Code(codCliente))
        {
            cout<<endl<<"Cuantos productos desea adquirir"<<endl; cin>>num;
            for(int i=0;i<num;i++)
            {
                cout<<endl<<"Ingrese el codigo del producto "<<i+1<<": ";
                cin>>codProducto;
                string cod=codProducto;
                switch(codProducto[0])
                {
                    case 'C':
                        {

                        stocks.insert ( pair<int,int>(i,cocina->getCantidad(codProducto)));
                        cout<<endl
                            <<"Nombre: "<<cocina->getNombre(cod)<<endl<<endl;
                        cout<<"Ingrese la cantidad a comprar: "; cin>>compra;
                        while(compra>stocks[i])
                        {
                            cout<<"No existe el stock suficiente, ingresa otra cantidad menor o igual a "<<stocks[i] <<":"<<endl;
                            cin>>compra;
                        }
                        precios.push_back( cocina->getPrecio(codProducto) );
                        compras.push_back(compra);
                        stocks[i]-=compras[i];
                        int stock=stocks[i];
                        cocina->modificar_Cantidad(cod,stock);

                        break;
                        }
                    case 'R':
                        {
                        precios.push_back( refrigeradora->getPrecio(codProducto) );
                        stocks.insert ( pair<int,int>(i,refrigeradora->getCantidad(codProducto)));
                        cout<<endl
                            <<"Nombre: "<<refrigeradora->getNombre(cod)<<endl<<endl;
                        cout<<"Ingrese la cantidad a comprar: "; cin>>compra;
                        while(compra>stocks[i])
                        {
                            cout<<"No existe el stock suficiente, ingresa otra cantidad menor o igual a "<<stocks[i] <<":"<<endl;
                            cin>>compra;
                        }
                        compras.push_back(compra);
                        stocks[i]-=compras[i];
                        int stock=stocks[i];
                        refrigeradora->modificar_Cantidad(cod,stock);

                        break;
                        }
                    case 'T':
                        {
                        precios.push_back( televisor->getPrecio(codProducto) );
                        stocks.insert ( pair<int,int>(i,televisor->getCantidad(codProducto)));
                        cout<<endl
                            <<"Nombre: "<<televisor->getNombre(cod)<<endl<<endl;
                        cout<<"Ingrese la cantidad a comprar: "; cin>>compra;
                        while(compra>stocks[i])
                        {
                            cout<<"No existe el stock suficiente, ingresa otra cantidad menor o igual a "<<stocks[i] <<":"<<endl;
                            cin>>compra;
                        }
                        compras.push_back(compra);
                        stocks[i]-=compras[i];
                        int stock=stocks[i];
                        televisor->modificar_Cantidad(cod,stock);
                        break;
                        }
                    default:
                        cout<<"No existe el codigo del producto"<<endl;
                        break;
                }
            }
            float boleta=0;
            for(int i=0;i<num;i++)
                boleta+= stocks[i]*precios[i];
            if( boleta<clientes.getCapital(codCliente) )
            {
                cout<<"El total a pagar es: $"<<boleta<<endl<<endl;
                cout<<"Gracias por comprar en nuestra tienda, vuelva pronto!"<<endl;
                Cola.pop(codCliente);
            }
            else
                cout<<"No cuenta con el dinero suficiente para la transaccion"<<endl;
        }
        else
        {
            cout<<"Codigo No Existente"<<endl;
        }
    }
};

// Command for entering op1
class Opcion1 : public Comando
{
private:
    Opcion* pOpcion;
public:
    Opcion1(Opcion *opcion) : pOpcion(opcion) {}
    void execute() { pOpcion->op1(); }
    ~Opcion1() {}
};

// Command for entering op2
class Opcion2 : public Comando
{
private:
    Opcion* pOpcion;
public:
    Opcion2(Opcion *opcion) : pOpcion(opcion) {}
    void execute() { pOpcion->op2(); }
    ~Opcion2() {}
};

class Opcion3 : public Comando
{
private:
    Opcion* pOpcion;
public:
    Opcion3(Opcion *opcion) : pOpcion(opcion) {}
    void execute() { pOpcion->op3(); }
    ~Opcion3() {}
};

class Opcion4 : public Comando
{
private:
    Opcion* pOpcion;
public:
    Opcion4(Opcion *opcion) : pOpcion(opcion) {}
    void execute() { pOpcion->op4(); }
    ~Opcion4() {}
};

class Opcion5 : public Comando
{
private:
    Opcion* pOpcion;
public:
    Opcion5(Opcion *opcion) : pOpcion(opcion) {}
    void execute() { pOpcion->op5(); }
    ~Opcion5() {}
};

// Invoker
// Stores the ConcreteCommand object
class Menu
{
private:
    Comando *pCmd;
public:
    void setComando(Comando *Cmd) { pCmd=Cmd; }
    void buttonPressed() { pCmd->execute(); }
    ~Menu() {}
};

void comprobar2Op(int &x){

    while(x!=1 && x!=2)
    {
        cout<<"Opcion Incorrecta\n";
        cin>>x;
    }

}

void comprobar3Op(int &x){

    while(x!=1 && x!=2 && x!=3)
    {
        cout<<"Opcion Incorrecta\n";
        cin>>x;
    }
}

void comprobar4Op(int &x){

    while(x!=1 && x!=2 && x!=3 && x!=4)
    {
        cout<<"Opcion Incorrecta\n";
        cin>>x;
    }

}

void comprobar5Op(int &x){

    while(x!=1 && x!=2 && x!=3 && x!=4 && x!=5)
    {
        cout<<"Opcion Incorrecta\n";
        cin>>x;
    }

}

void comprobar6Op(int &x){

    while(x!=1 && x!=2 && x!=3 && x!=4 && x!=5 && x!=6)
    {
    cout<<"Opcion Incorrecta\n";
    cin>>x;
    }
}


void comprobar8Op(int &x){

    while(x!=1 && x!=2 && x!=3 && x!=4 && x!=5 && x!=6 && x!=7 && x!=8)
    {
    cout<<"Opcion Incorrecta\n";
    cin>>x;
    }
}

void printMenu()
{
    system("pause");
    system("cls");
    cout<<"\t\t  ___  ___ ___  ___  __  ___  ___   __      "<<endl
        <<"\t\t  |__) |__ | _   |  (__   |   |__) |  |     "<<endl
        <<"\t\t  |  | |__ |__) _|_  __)  |   |  | |__|     "<<endl<<endl<<endl

        <<" 1.Ingresar cliente"  <<endl
        <<" 2.Ingresar producto" <<endl
        <<" 3.Lista de productos"<<endl
        <<" 4.Buscar producto"   <<endl
        <<" 5.Vender producto"   <<endl
        <<" 6.Salir\n"           <<endl
        <<"Ingrese una opcion: ";
}

void printCategorias()
{

    cout<<"\n 1. Cocinas "   <<endl
        <<" 2. Refrigeradoras "    <<endl
        <<" 3. Televisores \n"      <<endl
        <<"Ingrese una opcion: ";
}
void printComponentes(){
    cout<<"Componentes"    <<endl
        <<"1. Quemadores"   <<endl
        <<"2. Grilla_del_quemador"      <<endl
        <<"3. Horno" <<endl
        <<"4. Temporizador"         <<endl
        <<"5. electrica"         <<endl
        <<"6. gas" <<endl<<endl;
}



#endif // MENU_H
