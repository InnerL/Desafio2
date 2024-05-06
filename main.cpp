#include <iostream>
#include "menu.h";
using namespace std;
#include "linea.h"
#include "red.h"

int main()
{
    cout<<"Ingrese el nombre de la red"<<endl;

    int opcion;

    do{
        cout<<"Menu"<<endl;
        cout<<"1. Red"<<endl;
        cout<<"2. Lineas"<<endl;
        cout<<"3. Estacion"<<endl;
        cout<<"4. Visualizar metro"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese una opcion: "<<endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            opcionRed();
            break;
        case 2:
            opcionLinea();
            break;
        case 3:
            opcionEstacion();
            break;
        case 4:
            VisualizarMetro();
            break;
        default:
            cout<<"Opcion invalida. Por favor ingrese una opcion valida."<<endl;
            break;
        }
    }while(opcion !=0);
    return 0;
}
