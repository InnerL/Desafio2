#include "menu.h"

red redObj(0); // Crear un objeto de la clase red
linea lineaObj; // Crear un objeto de la clase linea
estacion estacionObj; // Crear un objeto de la clase estacion



void mostrarMenuRed() {
    int opcion;
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
            redObj.eliminarLinea();
            break;
        case 3:
            cout << "La red tiene " << redObj.cantidadLineas() << " lineas." << endl;
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
    int opcion;
    int selecEsta=0;
    string nuevoNombre;
    do {
        cout << "Menu de Linea:" << endl;
        linea* selec = redObj.mostrarLineasYSeleccionar();
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
            redObj.agregarEstacionesALinea(selec);
            break;
        case 2:
            selecEsta = selec->mostrarEstacionesYSeleccionar();
            selec->eliminarEstacion(selecEsta);
            break;
        case 3:
            selecEsta = selec->mostrarEstacionesYSeleccionar();
            cout<<"Ingrese el nuevo nombre de la estacion: ";
            cin>>nuevoNombre;
            selec->editarNombreEstacion(selecEsta, nuevoNombre);
            lineaObj.editarNomLinea();
            break;
        case 4:
            selec->listaEstacion();
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
