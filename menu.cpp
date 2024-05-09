#include "menu.h"
#include <limits>
#include <sstream>


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
        cout << "5. Visualizar Red." << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin>>opcion;
        switch (opcion) {
        case 1:
            //agregarLinea() en la clase red
            redObj.agregarLinea();
            break;
        case 2:
            //función eliminarLinea() en la clase red
            redObj.eliminarLinea();
            break;
        case 3:
            //Lista de lineas
            cout <<redObj.cantidadLineas() <<" Son las estaciones que contiene la red"<<endl;
            break;
        case 4:
            //Cantidad de estaciones en toda la red
            cout << "La red tiene " << redObj.cantEstacionRed() << " estaciones." << endl;
            break;
        case 5:
            redObj.imprimirListaLineas();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Por favor ingrese una opcion valida." << endl;
            break;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (opcion != 0);
}

void mostrarMenuLinea() {    
    int opcion;
    int selecEsta=0;
    int indiceEstacion1=0;
    int indiceEstacion2=0;
    string nuevoNombre;
    do {
        cout << "Menu de Linea:" << endl;
        linea* selec = redObj.mostrarLineasYSeleccionar();
        cout << "Menu de Linea: Que deseas?" << endl;
        cout << "1. Agregar Estacion." << endl;
        cout << "2. Eliminar Estacion." << endl;
        cout << "3. Editar nombre de estacion." << endl;
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
            cout<<"Seleccione la estacion inicial";
            indiceEstacion1 = selec->mostrarEstacionesYSeleccionar();
            cout<<"Seleccione la estacion final";
            indiceEstacion2 = selec->mostrarEstacionesYSeleccionar();
            lineaObj.calcularTiempo(indiceEstacion1,indiceEstacion2);
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Por favor ingrese una opcion valida." << endl;
            break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (opcion != 0);
}
