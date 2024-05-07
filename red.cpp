#include "red.h"
#include "linea.h"
#include "estacion.h"
#include <iostream>
#include <unordered_set>

using namespace std;

void red::agregarLinea() {
    string nombreLinea, tipoTransporte;
    int numEstaciones;

    cout << "Ingrese el nombre de la nueva linea: ";
    cin >> nombreLinea;
    cout << "Ingrese el tipo de transporte (tren o tranvia): ";
    cin >> tipoTransporte;
    cout << "Ingrese el numero de estaciones iniciales de la linea: ";
    cin >> numEstaciones;

    linea* nuevaLinea = new linea(nombreLinea, tipoTransporte, numEstaciones);

    // Agregar la nueva linea al arreglo de lineas
    for (int i = 0; i < cantLineas(); i++) {
        if (lineas[i] == nullptr) {
            lineas[i] = nuevaLinea;
            cout << "Linea agregada correctamente." << endl;
            return;
        }
    }

    cout << "No se pudo agregar la linea. La red esta llena." << endl;
}

void red::eliminarLinea(int indiceLinea) {
    cout << "Ingrese el indice de la linea a eliminar: ";
    cin >> indiceLinea;

    if (indiceLinea >= 0 && indiceLinea < cantLineas() && lineas[indiceLinea] != nullptr) {
        // Verificar si la linea tiene estaciones de transferencia
        bool tieneTransferencia = false;
        for (int i = 0; i < lineas[indiceLinea]->cantidadEstacionesLinea(); i++) {
            if (lineas[indiceLinea]->getEstacion(i)->getEsTransferencia()) {
                tieneTransferencia = true;
                break;
            }
        }

        if (tieneTransferencia) {
            cout << "No se puede eliminar una linea con estaciones de transferencia." << endl;
        } else {
            delete lineas[indiceLinea];
            lineas[indiceLinea] = nullptr;
            cout << "Linea eliminada correctamente." << endl;
        }
    } else {
        cout << "Indice de linea invalido." << endl;
    }
}

int red::cantLineas()  {
    return cantLineas();
}

int red::cantEstacionRed() {
    int totalEstaciones = 0;
    unordered_set<int> estacionesUnicas;

    for (int i = 0; i < cantLineas(); i++) {
        if (lineas[i] != nullptr) {
            for (int j = 0; j < lineas[i]->cantidadEstacionesLinea(); j++) {
                int idEstacion = lineas[i]->getEstacion(j)->getIdEstacion();
                if (estacionesUnicas.find(idEstacion) == estacionesUnicas.end()) {
                    estacionesUnicas.insert(idEstacion);
                    totalEstaciones++;
                }
            }
        }
    }

    return totalEstaciones;
}
