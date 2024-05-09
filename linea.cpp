#include "linea.h"
#include "estacion.h"
#include <iostream>
#include <string>
int indice = 0;

estacion linea::agregarEstacionC(int e,int a){
    string nombreEstacin;
    int tiempoSigEstacion=0;
    bool esTransferencia=false;

    cout << "Ingrese el nombre de la estacion " << e + 1 << ": ";
    cin >> nombreEstacin;
    if(e==a){
        tiempoSigEstacion = 0;
    }else{
        cout << "Ingrese el tiempo hacia la siguiente estacion " << e + 1 << ": ";
        cin >> tiempoSigEstacion;
    }
    cout << "Es esta una estacion de transferencia? (1 para si, 0 para no): ";
    cin >> esTransferencia;

    return estacion(e, nombreEstacin, tiempoSigEstacion, esTransferencia);
}

void linea::agregarEstacion(estacion* nuevaEstacion) {
    // Primero, encontramos un espacio disponible en el arreglo de estaciones
    int indice = 0;
    while (indice < numestacions && estacions[indice] != nullptr) {
        indice++;
    }

    numestacions++;

    // Si encontramos un espacio disponible, agregamos la nueva estación
    if (indice < numestacions+1) {
        estacions[indice] = nuevaEstacion;
        cout << "Estacion agregada correctamente a la linea." << endl;
    } else {
        cout << "No hay espacio disponible para agregar mas estaciones a la linea." << endl;
        delete nuevaEstacion; // Liberamos la memoria si no hay espacio disponible
    }
}


void linea::editarNomLinea() {
    string nuevoNombre;
    cout << "Ingrese el nuevo nombre para la linea: ";
    cin >> nuevoNombre;
    nomLinea = nuevoNombre;
    cout << "Nombre de linea actualizado correctamente." << endl;
}

int linea::cantidadEstacionsLinea()  {
    int contadorEstaciones = 0;
    for (int i = 0; i < numestacions; ++i) {
        if (estacions[i] != nullptr) {
            contadorEstaciones++;
        }
    }
    return contadorEstaciones;
}


int linea::calcularTiempo(int indiceEstacion1, int indiceEstacion2) {
    if (indiceEstacion1 < 0 || indiceEstacion1 >= numestacions || indiceEstacion2 < 0 || indiceEstacion2 >= numestacions) {
        cout << "Los índices de estaciones proporcionados son inválidos." << endl;
        return -1; // Valor de retorno indicando error
    }

    int distanciaTotal = 0;
    int indiceInicio = min(indiceEstacion1, indiceEstacion2);
    int indiceFin = max(indiceEstacion1, indiceEstacion2);

    for (int i = indiceInicio; i < indiceFin; ++i) {
        if (estacions[i] != nullptr && estacions[i + 1] != nullptr) {
            distanciaTotal += estacions[i]->getTiempoSigEstacion();
        } else {
            cout << "Una o ambas estaciones seleccionadas no tienen tiempo hacia la siguiente estación." << endl;
            return -1; // Valor de retorno indicando error
        }
    }

    return distanciaTotal;
}

int linea::mostrarEstacionesYSeleccionar(){
    cout << "Lista de estaciones en la linea " << nomLinea << ":" << endl;
    for (int i = 0; i < numestacions; ++i) {
        if (estacions[i] != nullptr) {
            cout << i + 1 << ". " << estacions[i]->getnomEstacion() << endl;
        }
    }
    int seleccion;
    do {
        cout << "Seleccione el numero de la estacion que desea: ";
        cin >> seleccion;
    } while (seleccion < 1 || seleccion > numestacions || estacions[seleccion - 1] == nullptr);

    // Aquí puedes hacer lo que necesites con la estación seleccionada
    cout << "Ha seleccionado la estacion: " << estacions[seleccion - 1]->getnomEstacion() << endl;
    return seleccion-1;
}

void linea::eliminarEstacion(int seleccion){
    if (seleccion >= 0 && seleccion < numestacions && estacions[seleccion] != nullptr) {
        if (estacions[seleccion]->getEsTransferencia() == false) {
            delete estacions[seleccion];
            estacions[seleccion] = nullptr;
            cout << "Estacion eliminada correctamente de la linea." << endl;
        } else {
            cout << "No se puede eliminar la estacion de transferencia." << endl;
        }
    } else {
        cout << "No se puede eliminar la estacion. Índice invalido o estacion inexistente." << endl;
    }
}

void linea::editarNombreEstacion(int seleccion, string nuevoNombre) {
    if (seleccion >= 0 && seleccion < numestacions && estacions[seleccion] != nullptr) {
        estacions[seleccion]->setnomEstacion(nuevoNombre);
        cout << "Nombre de la estación editado correctamente." << endl;
    } else {
        cout << "No se puede editar el nombre de la estación. Índice inválido o estación inexistente." << endl;
    }
}

void linea::listaEstacion(){
    int i = 0;
    cout << "Lista de estaciones en la linea " << nomLinea << ":" << endl;
    for (i ; i < numestacions; ++i) {
       if (estacions[i] != nullptr) {
           cout << i + 1 << ". " << estacions[i]->getnomEstacion() << endl;
       }
    }
    cout<<"Con un total de "<<i<<" estaciones"<<endl;
}
