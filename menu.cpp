#include "menu.h"
#include "red.h"
#include "linea.h"
#include "estacion.h"
red redObj;
linea lineaObj;
estacion estacionObj;

string nomEstacion = "Niquia";

void opcionRed()
{
    int opcion;
    do{
        cout<<"Menu de red: Que deseas?"<<endl;
        cout<<"1. Agregar Linea."<<endl;
        cout<<"2. Eliminar Linea."<<endl;
        cout<<"3. Cantidad de lineas."<<endl;
        cout<<"4. Cantidad de estaciones."<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese una opcion: "<<endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            redObj.agregarLinea();
            break;
        case 2:
            redObj.eliminarLinea();
            break;
        case 3:
            redObj.cantLineas();
            break;
        case 4:
            redObj.cantEstacionRed();
            break;
        case 0:
            break;
        default:
            cout<<"Opcion invalida. Por favor ingrese una opcion valida."<<endl;
            break;
        }
    }while(opcion != 0);
}

void opcionLinea()
{
    int opcion;
    do{
        cout<<"Menu de Linea: Que deseas?"<<endl;
        cout<<endl<<"Mostrar lista de lineas disponible***\h"<<endl;
        cout<<"1. Agregar Estacion."<<endl;
        cout<<"2. Eliminar Estacion."<<endl;
        cout<<"3. Editar nombre de linea."<<endl;
        cout<<"4. Cantidad de estaciones."<<endl;
        cout<<"5. Calcular tiempo entre estaciones."<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese una opcion: "<<endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            lineaObj.agregarEstacion(nomEstacion);
            break;
        case 2:
            lineaObj.eliminarEstacion(nomEstacion);
            break;
        case 3:
            lineaObj.editarnomLinea();
            break;
        case 4:
            lineaObj.cantidadEstacionesLinea();
            break;
        case 5:
            lineaObj.calcularTiempo();
            break;
        case 0:
            break;
        default:
            cout<<"Opcion invalida. Por favor ingrese una opcion valida."<<endl;
            break;
        }
    }while(opcion != 0);
}

void opcionEstacion()
{
    int opcion;
    int opcLinea;

    do{
        cout<<"Menu de Estacion:"<<endl;
        cout<<"Escoja la linea que desea ver o 0 para salir:"<<endl;
        cout<<"Visualizar lineas**"<<endl;
        cin>>opcLinea;
        if(opcLinea==0) break;
        cout<<"Menu de Estacion:"<<endl;
        cout<<"Visualizar estaciones de la linea**"<<endl;
        cout<<"1. Editar Nombre de la estacion."<<endl;
        cout<<"2. Editar tiempo entre las estaciones."<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese una opcion: "<<endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            estacionObj.editarNomEstacion();
            break;
        case 2:
            estacionObj.editarTiempoEstacion();
            break;
        case 0:
            break;
        default:
            cout<<"Opcion invalida. Por favor ingrese una opcion valida."<<endl;
            break;
        }
    }while(opcion != 0);}

void VisualizarMetro()
{
    cout<<"En mantenimiento"<<endl;
}
