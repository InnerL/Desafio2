#ifndef LINEA_H
#define LINEA_H
#include <string>
#include "estacion.h" // añadimos estacion para poder añadirlas y eliminarlas desde la linea

using namespace std;

class linea {
    string nomLinea;
    string tipoTransporte;
    estacion** estaciones;
    int numEstaciones;

public:
    // Constructor
    linea(string _nomLinea, string _tipoTransporte, int _numEstaciones) {
        nomLinea = _nomLinea;
        tipoTransporte = _tipoTransporte;
        numEstaciones = _numEstaciones;
        estaciones = new estacion*[numEstaciones];
        for (int i = 0; i < numEstaciones; i++) {
            estaciones[i] = nullptr;
        }
    }

    // Destructor
    ~linea() {
        for (int i = 0; i < numEstaciones; i++) {
            delete estaciones[i];
        }
        delete[] estaciones;
    }

    // Métodos get y set
    string getNomLinea() const {
        return nomLinea;
    }
    string getTipoTransporte() const {
        return tipoTransporte;
    }
    void setNomLinea(const string& _nomLinea) {
        nomLinea = _nomLinea;
    }
    void setTipoTransporte(const string& _tipoTransporte) {
        tipoTransporte = _tipoTransporte;
    }

    // Métodos
    void agregarEstacion(estacion* nuevaEstacion, int indice);
    void eliminarEstacion(int indice);
    void editarNomLinea();
    int cantidadEstacionesLinea();
    int calcularTiempo();
};

#endif // LINEA_H
