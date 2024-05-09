#ifndef LINEA_H
#define LINEA_H
#include <string>
#include "estacion.h"


using namespace std;

class linea{
public:
    int idLinea;
    string nomLinea;
    string tipoTransporte;
    estacion** estacions;
    int numestacions=0;


public:
    // Constructor
    linea(int _idLinea,string _nomLinea, string _tipoTransporte, int _numestacions) {
        idLinea = _idLinea;
        nomLinea = _nomLinea;
        tipoTransporte = _tipoTransporte;
        numestacions = _numestacions;
        int a = _numestacions-1;
        estacions = new estacion*[numestacions];
        for (int e = 0; e < numestacions; e++) {
            estacion newEstacion = agregarEstacionC(e, a);
            estacions[e] = new estacion(newEstacion);
        }


    }

    linea(string _nomLinea, string _tipoTransporte, int _numestacions) {
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
    string getNomLinea(){
        return nomLinea;
    }
    string getTipoTransporte(){
        return tipoTransporte;
    }
    int getnumestacions(){
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



    // Métodos
    void agregarEstacion(estacion* nuevaEstacion);
    void editarNomLinea();
    int cantidadEstacionsLinea();
    int calcularTiempo(int indiceEstacion1, int indiceEstacion2);

    estacion agregarEstacionC(int e, int a);
    int mostrarEstacionesYSeleccionar();
    void eliminarEstacion(int seleccion);

    void editarNombreEstacion(int indice, string nuevoNombre);
    void listaEstacion();

};

#endif // LINEA_H
