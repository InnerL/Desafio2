#ifndef LINEA_H
#define LINEA_H
#include <string>
#include "estacion.h" // añadimos estacion para poder añadirlas y eliminarlas desde la linea
#include <iostream>


using namespace std;

class linea{
public:
    int idLinea;
    string nomLinea;
    string tipoTransporte;
    estacion** estacions;
    int numestacions;


public:
    // Constructor
    linea(string _nomLinea, string _tipoTransporte, int _numestacions) {
        nomLinea = _nomLinea;
        tipoTransporte = _tipoTransporte;
        numestacions = _numestacions;
        estacions = new estacion*[numestacions];
        for (int i = 0; i < numestacions; i++) {
            estacions[i] = nullptr;
        }
    }
    linea(int _idLinea,string _nomLinea, string _tipoTransporte, int _numestacions) {
        idLinea = _idLinea;
        nomLinea = _nomLinea;
        tipoTransporte = _tipoTransporte;
        numestacions = _numestacions;
        estacions = new estacion*[numestacions];
        for (int i = 0; i < numestacions; i++) {
            estacions[i] = nullptr;
        }
    }

    linea(){}

    // Destructor
    ~linea() {
        for (int i = 0; i < numestacions; i++) {
            delete estacions[i];
        }
        delete[] estacions;
    }




    // Métodos get y set
    string getNomLinea() const {
        return nomLinea;
    }
    string getTipoTransporte() const {
        return tipoTransporte;
    }
    int getNumestacions() const {
        return numestacions;
    }



    void setNomLinea(const string& _nomLinea) {
        nomLinea = _nomLinea;
    }
    void setTipoTransporte(const string& _tipoTransporte) {
        tipoTransporte = _tipoTransporte;
    }
    void setNumestacions(int newNumestacions)
    {
        numestacions = newNumestacions;
    }
    /*
    void getLineas(linea** lineas){
        for (int i = 0; i < numLineas; ++i) {
            // Acceder a los elementos de la linea[i] usando indirección doble
            // Por ejemplo, para acceder al nombre de la línea
            std::string nombreLinea = lineas[i]->getNomLinea();

            // Haz lo que necesites con la información de la línea...
        }
    };
*/
    // Métodos
    void agregarEstacion(estacion* nuevaEstacion);
//    void agregarEstacion(estacion* nuevaEstacion, int indice);
    void eliminarEstacion(int indice);
    void editarNomLinea();
    int cantidadestacionsLinea();
    int calcularTiempo();

    void agregarEstacion1(estacion* nuevaEstacion);

};

#endif // LINEA_H
