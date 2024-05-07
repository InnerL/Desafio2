#include <iostream>
#include "menu.h"
#include "linea.h"
#include "red.h"

using namespace std;

int main() {
    red redObj; // Crear un objeto de la clase red
    linea lineaObj; // Crear un objeto de la clase linea
    estacion estacionObj; // Crear un objeto de la clase estacion

    int opcion;
    do {
        cout << "Menu Principal:" << endl;
        cout << "1. Gestion de Red." << endl;
        cout << "2. Gestion de Linea." << endl;
        cout << "3. Gestion de Estacion." << endl;
        cout << "4. Visualizar Metro." << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            mostrarMenuRed(redObj);
            break;
        case 2:
            mostrarMenuLinea(lineaObj);
            break;
        case 3:
            mostrarMenuEstacion(estacionObj);
            break;
        case 4:
            // Implementar la función VisualizarMetro()
            VisualizarMetro();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Por favor ingrese una opcion valida." << endl;
            break;
        }
    } while (opcion != 0);

    return 0;
}
