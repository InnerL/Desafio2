#include "estacion.h"
#include <iostream>

void estacion::editarNomEstacion() {
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
    cout << "Ingrese el nuevo tiempo a la estacion anterior: ";
    cin >> nuevoTiempoAnt;
    tiempoSigEstacion = nuevoTiempoSig;
    tiempoAntEstacion = nuevoTiempoAnt;
    cout << "Tiempos de estacion actualizados correctamente." << endl;
}
