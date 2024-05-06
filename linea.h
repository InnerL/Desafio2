#ifndef LINEA_H
#define LINEA_H
#include <iostream>
#include <string>
using namespace std;


class linea{
    string nomLinea;
    string tipoTransporte;

public:
    //Constructor-Destructor
    linea(string _nomLinea, string _tipoTransporte){ nomLinea = _nomLinea; tipoTransporte = _tipoTransporte;}
    linea(){}



    // Métodos get
    string getNomLinea() const {
        return nomLinea;
    }
    string getTipoTransporte() const {
        return tipoTransporte;
    }

    // Métodos set
    void setNomLinea(const string& _nomLinea) {
        nomLinea = _nomLinea;
    }
    void setTipoTransporte(const string& _tipoTransporte) {
        tipoTransporte = _tipoTransporte;
    }


    //Metodos
    void agregarEstacion(string nomEstacion);
    void eliminarEstacion(string nomEstacion);
    void editarnomLinea();
    int cantidadEstacionesLinea();
    int calcularTiempo();

};


#endif // LINEA_H
