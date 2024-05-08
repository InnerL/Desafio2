#include "estacion.h"
#include <iostream>

void estacion::editarnomEstacion() {
    string nuevoNombre;
    cout << "Ingrese el nuevo nombre para la estacion: ";
    cin >> nuevoNombre;
    nomEstacion = nuevoNombre;
    cout << "Nombre de estacion actualizado correctamente." << endl;
}

void estacion::editarTiempoEstacion() {
    int nuevoTiempoSig, nuevoTiempoAnt;
    cout << "Ingrese el nuevo tiempo a la siguiente estacion: ";
    cin >> nuevoTiempoSig;   
    tiempoSigEstacion = nuevoTiempoSig;
    cout << "Tiempos de estacion actualizados correctamente." << endl;
}

