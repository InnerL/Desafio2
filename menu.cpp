#include "menu.h"

red redObj; // Crear un objeto de la clase red
linea lineaObj; // Crear un objeto de la clase linea
estacion estacionObj; // Crear un objeto de la clase estacion


void mostrarMenuRed() {
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
            redObj.agregarLinea();
            break;
        case 2:
            // Implementar la función eliminarLinea() en la clase red
            redObj.eliminarLinea(indice);
            break;
        case 3:
           // cout << "La red tiene " << redObj.cantLineas() << " lineas." << endl;
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

void mostrarMenuLinea() {
    linea linea1(1, "Linea 1", "Metro", 3);
    std::cout << "Nombre de la linea: " << linea1.getNomLinea() << std::endl;
    std::cout << "Tipo de transporte: " << linea1.getTipoTransporte() << std::endl;
    std::cout << "Numero de estaciones: " << linea1.getNumestacions() << std::endl;
    int opcion, indice;    
    do {
        cout << "Menu de Linea: Que deseas?" << endl;
        cout <<"lista de todas las lineas"<<endl;
        cout <<"A que linea desea ingresar"<<endl;
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
           // lineaObj.agregarEstacion((&estacionA);
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
            cout << "La linea tiene " << lineaObj.getNumestacions() << " estaciones." << endl;
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

void mostrarMenuEstacion() {
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
            estacionObj.editarnomEstacion();
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
