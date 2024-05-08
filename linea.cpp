#include "linea.h"
#include "estacion.h"
#include <iostream>
#include <string>


int indice = 0;



void linea::agregarEstacion(estacion* nuevaEstacion) {

    // Aumentar el tamaño del arreglo de estacions
    estacion** nuevaLista = new estacion*[numestacions];
    // Copiar las estacions existentes a la nueva lista
    for (int i = 0; i <= numestacions; ++i) {
        nuevaLista[i] = estacions[i];
    }
    // Agregar la nueva estación al final de la lista
    nuevaLista[numestacions] = nuevaEstacion;
    // Liberar la memoria ocupada por la lista anterior
    /*for (int i = 0; i <= numestacions; ++i) {
        delete nuevaLista[i];
    }
    delete[] nuevaEstacion;*/
    // Actualizar la lista de estacions de la línea
    estacions = nuevaLista;
    // Incrementar el contador de estacions
    numestacions++;
}

void linea::agregarEstacion1(estacion* nuevaEstacion) {
    // Primero, encontramos un espacio disponible en el arreglo de estaciones
    int indice = 0;
    while (indice < numestacions && estacions[indice] != nullptr) {
        indice++;
    }

    // Si encontramos un espacio disponible, agregamos la nueva estación
    if (indice < numestacions) {
        estacions[indice] = nuevaEstacion;
        cout << "Estacion agregada correctamente a la linea." << endl;
    } else {
        cout << "No hay espacio disponible para agregar mas estaciones a la linea." << endl;
        delete nuevaEstacion; // Liberamos la memoria si no hay espacio disponible
    }
}


/*
void linea::agregarEstacion(estacion* nuevaEstacion, int indice) {
    if (indice >= 0 && indice < numestacions) {
        estacions[indice] = nuevaEstacion;
    } else {
        std::cout << "Índice de estación fuera de rango." << std::endl;
    }
}
*/
/*
void linea::agregarEstacion(linea& linea) {

    if (indice >= 0 && indice <= numestacions) {
        estacion** nuevoArreglo = new estacion*[numestacions + 1];

        for (int i = 0; i < indice; i++) {
            nuevoArreglo[i] = estacions[i];
        }

        nuevoArreglo[indice] = nuevaEstacion;

        for (int i = indice; i < numestacions; i++) {
            nuevoArreglo[i + 1] = estacions[i];
        }

        delete[] estacions;
        estacions = nuevoArreglo;
        numestacions++;

        cout << "Estacion agregada correctamente." << endl;
    } else {
        cout << "Indice de estacion invalido." << endl;
    }

}*/


void linea::eliminarEstacion(int indice) {
    if (indice >= 0 && indice < numestacions) {
        if (estacions[indice]->getEsTransferencia()) {
            cout << "No se puede eliminar una estacion de transferencia." << endl;
        } else {
            estacion** nuevoArreglo = new estacion*[numestacions - 1];

            for (int i = 0; i < indice; i++) {
                nuevoArreglo[i] = estacions[i];
            }

            for (int i = indice + 1; i < numestacions; i++) {
                nuevoArreglo[i - 1] = estacions[i];
            }

            delete estacions[indice];
            delete[] estacions;
            estacions = nuevoArreglo;
            numestacions--;

            cout << "Estacion eliminada correctamente." << endl;
        }
    } else {
        cout << "Indice de estacion invalido." << endl;
    }
}

void linea::editarNomLinea() {
    string nuevoNombre;
    cout << "Ingrese el nuevo nombre para la linea: ";
    cin >> nuevoNombre;
    nomLinea = nuevoNombre;
    cout << "Nombre de linea actualizado correctamente." << endl;
}

int linea::cantidadestacionsLinea()  {
    return numestacions;
}

int linea::calcularTiempo() {
    int tiempoTotal = 0;
    for (int i = 0; i < numestacions - 1; i++) {
        tiempoTotal += estacions[i]->getTiempoSigEstacion();
    }
    return tiempoTotal;
}
