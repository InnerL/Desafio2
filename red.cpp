#include "red.h"
#include "linea.h"
#include "estacion.h"
#include <iostream>
#include <unordered_set>

linea objLinea;

using namespace std;

// Dentro de la clase red

void red::agregarLinea() {
    // Pedir al usuario los detalles de la línea a agregar
    string nombreLinea;
    string tipoTransporte;
    int numEstaciones;

    cout << "Ingrese el nombre de la linea: ";
    cin >> nombreLinea;
    cout << "Ingrese el tipo de transporte de la linea: ";
    cin >> tipoTransporte;
    cout << "Ingrese el numero de estaciones de la linea: ";
    cin >> numEstaciones;

    // Crear un nuevo objeto de la clase línea con los detalles proporcionados
    linea* nuevaLinea = new linea(nombreLinea, tipoTransporte, numEstaciones);

    // Agregar estaciones a la nueva línea
    for (int i = 0; i < numEstaciones; ++i) {
        // Pedir al usuario los detalles de la estación
        int idEstacion = i;
        string nombreEstacin;
        int tiempoSigEstacion;
        bool esTransferencia;

        cout << "Ingrese el nombre de la estacion " << i + 1 << ": ";
        cin >> nombreEstacin;
        if(i==0){
            tiempoSigEstacion = 0;
        }else{
            cout << "Ingrese el tiempo hacia la anterior estacion " << i + 1 << ": ";
            cin >> tiempoSigEstacion;
        }
        cout << "Es esta una estacion de transferencia? (1 para si, 0 para no): ";
        cin >> esTransferencia;

        // Crear un nuevo objeto de la clase estación con los detalles proporcionados
        estacion* nuevaEstacion = new estacion(idEstacion, nombreEstacin, tiempoSigEstacion, esTransferencia);

        // Agregar la nueva estación a la línea
        nuevaLinea->agregarEstacion(nuevaEstacion);
    }

    // Agregar la nueva línea al arreglo de líneas de la red
    // Primero, encontramos un espacio disponible en el arreglo de líneas
    int indice = 0;
    while (indice < cantLineas && lineas[indice] != nullptr) {
        indice++;
    }

    cantLineas++;

    // Si encontramos un espacio disponible, agregamos la nueva línea
    if (indice < cantLineas+1) {
        lineas[indice] = nuevaLinea;
        cout << "Linea agregada correctamente a la red." << endl;
    } else {
        cout << "No hay espacio disponible para agregar mas lineas." << endl;
        delete nuevaLinea;
    }
}


void red::eliminarLinea(int indiceLinea) {
    /*
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
*/
}

int red::cantEstacionRed() {
    /*
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
*/
}

void red::imprimirListaLineas(){
    cout << "Lista de lineas y estaciones en la red:" << endl;
    for (int i = 0; i < cantLineas; ++i) {
        if (lineas[i] != nullptr) {
            cout << "Linea " << i + 1 << ": " << lineas[i]->getNomLinea() << endl;
            cout << "Tipo de transporte: " << lineas[i]->getTipoTransporte() << endl;
            cout << "Estaciones:" << endl;
            for (int j = 0; j < lineas[i]->getNumestacions(); ++j) {
                if (lineas[i]->estacions[j] != nullptr) {
                    cout << " - " << lineas[i]->estacions[j]->getnomEstacion() << endl;
                    cout << "   Tiempo hacia la siguiente estacion: " << lineas[i]->estacions[j]->getTiempoSigEstacion() << " minutos" << endl;
                    cout << "   Es estacion de transferencia: " << (lineas[i]->estacions[j]->getEsTransferencia() ? "Sí" : "No") << endl;
                }
            }
            cout << endl;
        }
    }
}
