#include "red.h"
#include "linea.h"
#include "estacion.h"
#include <iostream>

using namespace std;

void mostrarMenuRed(red& redObj) {
    int opcion, indice;
    linea* nuevaLinea;
    do {
        cout << "Menu de Red: Que deseas?" << endl;
        cout << "1. Agregar Linea." << endl;
        cout << "2. Eliminar Linea." << endl;
        cout << "3. Cantidad de lineas." << endl;
        cout << "4. Cantidad de estaciones." << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Implementar la función agregarLinea() en la clase red
            redObj.agregarLinea(nuevaLinea, indice);
            break;
        case 2:
            // Implementar la función eliminarLinea() en la clase red
            redObj.eliminarLinea(indice);
            break;
        case 3:
            cout << "La red tiene " << redObj.cantLineas() << " lineas." << endl;
            break;
        case 4:
            cout << "La red tiene " << redObj.cantEstacionRed() << " estaciones." << endl;
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Por favor ingrese una opcion valida." << endl;
            break;
        }
    } while (opcion != 0);
}

void mostrarMenuLinea(linea& lineaObj) {
    int opcion, indice;
    estacion *nuevaEstacion;
    do {
        cout << "Menu de Linea: Que deseas?" << endl;
        cout << "1. Agregar Estacion." << endl;
        cout << "2. Eliminar Estacion." << endl;
        cout << "3. Editar nombre de linea." << endl;
        cout << "4. Cantidad de estaciones." << endl;
        cout << "5. Calcular tiempo entre estaciones." << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Implementar la función agregarEstacion() en la clase linea
            lineaObj.agregarEstacion(nuevaEstacion, indice);
            break;
        case 2:
            // Implementar la función eliminarEstacion() en la clase linea
            lineaObj.eliminarEstacion(indice);
            break;
        case 3:
            // Implementar la función editarNomLinea() en la clase linea
            lineaObj.editarNomLinea();
            break;
        case 4:
            cout << "La linea tiene " << lineaObj.cantidadEstacionesLinea() << " estaciones." << endl;
            break;
        case 5:
            // Implementar la función calcularTiempo() en la clase linea
            lineaObj.calcularTiempo();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Por favor ingrese una opcion valida." << endl;
            break;
        }
    } while (opcion != 0);
}

void mostrarMenuEstacion(estacion& estacionObj) {
    int opcion;
    do {
        cout << "Menu de Estacion:" << endl;
        cout << "1. Editar Nombre de la estacion." << endl;
        cout << "2. Editar tiempo entre las estaciones." << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Implementar la función editarNomEstacion() en la clase estacion
            estacionObj.editarNomEstacion();
            break;
        case 2:
            // Implementar la función editarTiempoEstacion() en la clase estacion
            estacionObj.editarTiempoEstacion();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Por favor ingrese una opcion valida." << endl;
            break;
        }
    } while (opcion != 0);
}
