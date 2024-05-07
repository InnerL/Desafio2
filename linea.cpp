#include "linea.h"
#include "estacion.h"
#include <iostream>

void linea::agregarEstacion(estacion* nuevaEstacion, int indice) {
    if (indice >= 0 && indice <= numEstaciones) {
        estacion** nuevoArreglo = new estacion*[numEstaciones + 1];

        for (int i = 0; i < indice; i++) {
            nuevoArreglo[i] = estaciones[i];
        }

        nuevoArreglo[indice] = nuevaEstacion;

        for (int i = indice; i < numEstaciones; i++) {
            nuevoArreglo[i + 1] = estaciones[i];
        }

        delete[] estaciones;
        estaciones = nuevoArreglo;
        numEstaciones++;

        cout << "Estacion agregada correctamente." << endl;
    } else {
        cout << "Indice de estacion invalido." << endl;
    }
}

void linea::eliminarEstacion(int indice) {
    if (indice >= 0 && indice < numEstaciones) {
        if (estaciones[indice]->getEsTransferencia()) {
            cout << "No se puede eliminar una estacion de transferencia." << endl;
        } else {
            estacion** nuevoArreglo = new estacion*[numEstaciones - 1];

            for (int i = 0; i < indice; i++) {
                nuevoArreglo[i] = estaciones[i];
            }

            for (int i = indice + 1; i < numEstaciones; i++) {
                nuevoArreglo[i - 1] = estaciones[i];
            }

            delete estaciones[indice];
            delete[] estaciones;
            estaciones = nuevoArreglo;
            numEstaciones--;

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

int linea::cantidadEstacionesLinea()  {
    return numEstaciones;
}

int linea::calcularTiempo() {
    int tiempoTotal = 0;
    for (int i = 0; i < numEstaciones - 1; i++) {
        tiempoTotal += estaciones[i]->getTiempoSigEstacion();
    }
    return tiempoTotal;
}
