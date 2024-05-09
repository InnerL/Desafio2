#ifndef RED_H
#define RED_H
#include <string>
#include "linea.h" // añadimos la libreria linea para poder crear una nueva linea desde la red

using namespace std;

class red {
public:
    string nomRed;
    linea** lineas;
    // ID(numLineas)int - Nombre String - tipotransporte
    int cantLineas;

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
    string getNomRed() const {
        return nomRed;
    }
    void setcantLineas(int _cantLineas) {
        cantLineas = _cantLineas;
    }
    int getcantLineas() const {
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
    //Linea

    void setCantLineas(int newCantLineas);
};

#endif // RED_H
