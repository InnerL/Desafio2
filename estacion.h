#ifndef ESTACION_H
#define ESTACION_H
#include <iostream>
#include <string>
using namespace std;

class estacion{
    string nomEstacion;
    int tiempoSigEstacion;
    int tiempoAntEstacion;
    bool transEstacion;

public:
    //Constructor-Destructor
    estacion(string _nomEstacion, int _tiempoSigEstacion, int _tiempoAntEstacion, bool _transEstacion){
        nomEstacion = _nomEstacion;
        tiempoSigEstacion = _tiempoSigEstacion;
        tiempoAntEstacion = _tiempoAntEstacion;
        transEstacion = _transEstacion;
    }
    estacion(){};


    //Metodos
    void eliminarEstacion();
    void editarNomEstacion();
    int editarTiempoEstacion();
};

#endif // ESTACION_H

