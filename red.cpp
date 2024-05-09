#include "red.h"
#include "linea.h"
#include "estacion.h"
#include <iostream>

linea objLinea;

using namespace std;

// Dentro de la clase red



void red::agregarLinea() {
    // Pedir al usuario los detalles de la línea a agregar
    string nombreLinea="";
    string tipoTransporte="";
    int numestacions=0, a=0;

    cout << "Ingrese el nombre de la linea: ";
    cin >> nombreLinea;
    cout << "Ingrese el tipo de transporte de la linea: ";
    cin >> tipoTransporte;
    cout << "Ingrese el numero de estaciones de la linea: ";
    cin >> numestacions;
    a = numestacions;

    int idLinea = 0;
    while (idLinea< cantLineas && lineas[idLinea] != nullptr) {
        idLinea++;
    }

    // Crear un nuevo objeto de la clase línea con los detalles proporcionados
    linea* nuevaLinea = new linea(idLinea, nombreLinea, tipoTransporte, numestacions);

    //Encontramos un espacio disponible en el arreglo de líneas
    int indice = 0;
    while (indice < cantLineas && lineas[indice] != nullptr) {
        indice++;
    }

    cantLineas++;
    setcantLineas(cantLineas);

    // Si encontramos un espacio disponible, agregamos la nueva línea
    if (indice < cantLineas+1) {
        lineas[indice] = nuevaLinea;
        cout << "Linea agregada correctamente a la red." << endl;
    } else {
        cout << "No hay espacio disponible para agregar mas lineas." << endl;
        delete nuevaLinea;
    }
}


void red::eliminarLinea() {
    int contadorLineas = 0;
    for (int i = 0; i < cantLineas; ++i) {
        if (lineas[i] != nullptr) {
            contadorLineas++;
        }
    }

    if (contadorLineas == 1) {
        // Eliminar la única línea registrada
        for (int i = 0; i < cantLineas; ++i) {
            if (lineas[i] != nullptr) {
                delete lineas[i];
                lineas[i] = nullptr;
                cout << "La unica línea registrada ha sido eliminada." << endl;
                return; // Salir de la función después de eliminar la línea
            }
        }
    } else {
        cout << "No se puede eliminar la linea. Asegurate de que haya exactamente una linea registrada en la red." << endl;
    }
}

int red::cantEstacionRed() {
    int totalEstaciones = 0;
    for (int i = 0; i < cantLineas; ++i) {
        if (lineas[i] != nullptr) {
            totalEstaciones += lineas[i]->getnumestacions();
        }
    }
    return totalEstaciones;
}

int red::cantidadLineas()
{
    int contadorLineas = 0;
    cout << "Lista de lineas en la red " << getNomRed()<< ":" << endl;
    for (int i = 0; i < cantLineas; ++i) {
        if (lineas[i] != nullptr) {
            cout << i + 1 << ". " << lineas[i]->getNomLinea() << endl;
            contadorLineas++;
        }
    }
    return contadorLineas;
}

void red::imprimirListaLineas(){
    cout << "Lista de lineas y estaciones en la red:" << endl;
    int cant=0;
    cant = getcantLineas();
    for (int i = 0; i < cant; ++i) {
        if (lineas[i] != nullptr) {
            cout << "Linea " << i + 1 << ": " << lineas[i]->getNomLinea() << endl;
            cout << "Tipo de transporte: " << lineas[i]->getTipoTransporte() << endl;
            cout << "Estaciones:" << endl;
            for (int j = 0; j < lineas[i]->getnumestacions(); ++j) {
                if (lineas[i]->estacions[j] != nullptr) {
                    cout << " - " << lineas[i]->estacions[j]->getnomEstacion() << endl;
                    cout << "   Tiempo hacia la siguiente estacion: " << lineas[i]->estacions[j]->getTiempoSigEstacion() << " minutos" << endl;
                    cout << "   Es estacion de transferencia: " << (lineas[i]->estacions[j]->getEsTransferencia() ? "Si" : "No") << endl;
                }
            }
            cout << endl;
        }
    }
}

linea* red::mostrarLineasYSeleccionar(){
    cout << "Lista de lineas en la red:" << endl;
    for (int i = 0; i < cantLineas; ++i) {
        if (lineas[i] != nullptr) {
            cout << i + 1 << ". " << lineas[i]->getNomLinea() << endl;
        }
    }
    int seleccion;
    do {
        cout << "Seleccione el numero de la linea que desea: ";
        cin >> seleccion;
    } while (seleccion < 1 || seleccion > cantLineas || lineas[seleccion - 1] == nullptr);

    // Aquí puedes hacer lo que necesites con la línea seleccionada, como mostrar más detalles o trabajar con ella.
    cout << "Ha seleccionado la linea: " << lineas[seleccion - 1]->getNomLinea() << endl;

    return lineas[seleccion - 1];;
}

void red::agregarEstacionesALinea(linea *lineaSeleccionada)
{ // Pedir al usuario los detalles de las estaciones a agregar
    int numEstaciones;
    cout << "Ingrese el numero de estaciones que desea agregar a la linea " << lineaSeleccionada->getNomLinea() << ": ";
    cin >> numEstaciones;

    int a = lineaSeleccionada->cantidadEstacionsLinea() + numEstaciones;
    int e = lineaSeleccionada->cantidadEstacionsLinea();

    for (int i = 0; i < numEstaciones; ++i) {
        e++;
        // Pedir al usuario los detalles de la estación
        estacion newEstacion = objLinea.agregarEstacionC(e, a);
        // Crear un nuevo objeto de la clase estación con los detalles proporcionados
        estacion* nuevaEstacion = new estacion(newEstacion);

        // Agregar la nueva estación a la línea seleccionada
        lineaSeleccionada->agregarEstacion(nuevaEstacion);
    }

    cout << "Estaciones agregadas correctamente a la línea " << lineaSeleccionada->getNomLinea() << "." << endl;

}
