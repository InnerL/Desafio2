#include <iostream>
#include "menu.h"
#include "red.h"
#include <limits>
using namespace std;
red objRed(0);

int main() {
    string nomred;
    cout<<"Ingrese el nombre de la red: "<<endl;
    cin>>nomred;
    objRed.setNomRed(nomred);
    int opcion;
    do {
        cout << "Menu Principal:" << endl;
        cout << "1. Gestion de Red." << endl;
        cout << "2. Gestion de Linea." << endl;        
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            mostrarMenuRed();
            break;
        case 2:
            mostrarMenuLinea();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Por favor ingrese una opcion valida." << endl;
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (opcion != 0);
    return 0;
}
