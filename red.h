#ifndef RED_H
#define RED_H
#include <string>
#include "linea.h" // añadimos la libreria linea para poder crear una nueva linea desde la red

using namespace std;

class red {
    string nomRed;
    linea** lineas;
    int numLineas;

public:
    // Constructor
    red(string _nomRed, int _cantLineas) {
        nomRed = _nomRed;
        numLineas = _cantLineas;
        lineas = new linea*[numLineas];
        for (int i = 0; i < numLineas; i++) {
            lineas[i] = nullptr;
        }
    }

    // Destructor
    ~red() {
        for (int i = 0; i < numLineas; i++) {
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

    // Otros métodos
    void agregarLinea(linea* nuevaLinea, int indice);
    void eliminarLinea(int indice);
    int cantLineas();
    int cantEstacionRed();
};

#endif // RED_H
