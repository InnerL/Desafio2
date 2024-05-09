#ifndef RED_H
#define RED_H
#include <string>
#include "linea.h"

using namespace std;

class red {
public:
    string nomRed;
    linea** lineas;
    int cantLineas=0;

public:
    // Constructor
    red(int _cantLineas) {
        cantLineas = _cantLineas;
        lineas = new linea*[cantLineas];
        for (int i = 0; i < cantLineas; i++) {
            lineas[i] = nullptr;
        }
    }
    red(){}

    // Destructor
    ~red() {
        for (int i = 0; i < cantLineas; i++) {
            delete lineas[i];
        }
        delete[] lineas;
    }



    // Métodos set y get
    void setNomRed(string _nomRed) {
        nomRed = _nomRed;
    }
    string getNomRed(){
        return nomRed;
    }
    void setcantLineas(int _cantLineas) {
        cantLineas = _cantLineas;
    }
    int getcantLineas(){
        return cantLineas;
    }

    // Otros métodos
    void agregarLinea();
    void eliminarLinea();
    int cantEstacionRed();
    int cantidadLineas();
    void imprimirListaLineas();
    linea*  mostrarLineasYSeleccionar();
    void agregarEstacionesALinea(linea* lineaSeleccionada);

};

#endif // RED_H
