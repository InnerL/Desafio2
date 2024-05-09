#include <iostream>
#include "menu.h"
#include "red.h"
#include "linea.h"
#include "estacion.h"
#include <iostream>

using namespace std;
red objred(0);

int main() {

    string nuevoNombre;

    objred.agregarLinea();
    objred.agregarLinea();
    objred.agregarLinea();
    objred.imprimirListaLineas();
    linea* selec = objred.mostrarLineasYSeleccionar();
    selec->listaEstacion();
    int selecEsta = selec->mostrarEstacionesYSeleccionar();
    cout<<"Ingrese el nuevo nombre de la estacion: ";
    cin>>nuevoNombre;
    selec->editarNombreEstacion(selecEsta, nuevoNombre);


    objred.imprimirListaLineas();




    //linea linea1(0, "Linea A", "Metro", 0);


    // Agregar estacions a la línea
    /*
    estacion estacionA(0, "Estacion A", 5, false);
    estacion estacionB(1, "Estacion B", 7, true);
    estacion estacionC(2, "Estacion C", 4, true);
*/
/*

    int id;
    string nombre;
    int tiempo;
    bool transferencia;
    cout << "ID: ";
    cin >> id;
    cin.ignore(); // Limpiar el buffer del salto de línea
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Tiempo hasta la siguiente estacion: ";
    cin >> tiempo;
    cout << "Es una estacion de transferencia? (1: Si, 0: No): ";
    cin >> transferencia;
    cin.ignore(); // Limpiar el buffer del salto de línea

    // Crear la estación y agregarla a la línea
    estacion* nuevaEstacion = new estacion(id, nombre, tiempo, transferencia);
    linea1.agregarEstacion(nuevaEstacion);



    estacion* nuevaEstacion1 = new estacion(1, "Bello", 5, 0);
    linea1.agregarEstacion(nuevaEstacion1);

    estacion* nuevaEstacion2 = new estacion(2, "Madera", 6, "0");
    linea1.agregarEstacion(nuevaEstacion2);


*/
    /*
    linea1.agregarEstacion(&estacionA, 0);
    linea1.agregarEstacion(&estacionB, 1);
    linea1.agregarEstacion(&estacionC, 2);
*/
    // Acceder a la información de las estacions


    /*

    cout << "estacions de la linea " << linea1.nomLinea << ":" << endl;
        for (int i = 0; i < linea1.numestacions; ++i) {
            cout << "ID: " << linea1.estacions[i]->idEstacion << ", Nombre: " << linea1.estacions[i]->nomEstacion<< ", TipoTrans: "<<linea1.tipoTransporte<< endl;
        }

    for (int i = 0; i < objred.cantLineas; ++i) {
        cout << "ID: " <<  objred.lineas[i]->idLinea << ", Nombre: " << objred.lineas[i]->nomLinea << endl;
    }
*/


    /*
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
            mostrarMenuRed();
            break;
        case 2:
            mostrarMenuLinea();
            break;
        case 3:
            mostrarMenuEstacion();
            break;
        case 4:
            // Implementar la función VisualizarMetro()
//            VisualizarMetro();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Por favor ingrese una opcion valida." << endl;
            break;
        }
    } while (opcion != 0);
*/
    return 0;
}
