#ifndef ESTACION_H
#define ESTACION_H
#include <string>

using namespace std;



class estacion{
public:
    int idEstacion;
    string nomEstacion;
    int tiempoSigEstacion;
    bool esTransferencia;

public:
    // Constructor
    estacion( int _idEstacion, string _nomEstacion, int _tiempoSigEstacion , bool _esTransferencia) {
        idEstacion = _idEstacion;
        nomEstacion = _nomEstacion;
        tiempoSigEstacion = _tiempoSigEstacion;
        esTransferencia = _esTransferencia;
    }    
    estacion(){}

    //Destructor
    ~estacion() {
    }

    // Métodos get y set
    int getIdEstacion() const {
        return idEstacion;
    }
    string getnomEstacion() const {
        return nomEstacion;
    }
    int getTiempoSigEstacion() const {
        return tiempoSigEstacion;
    }
    bool getEsTransferencia() const {
        return esTransferencia;
    }


    void setnomEstacion(string _nomEstacion) {
        nomEstacion = _nomEstacion;
    }
    void setTiempoSigEstacion(int _tiempoSigEstacion) {
        tiempoSigEstacion = _tiempoSigEstacion;
    }
    void setEsTransferencia(bool _esTransferencia) {
        esTransferencia = _esTransferencia;
    }

    void eliminarEstacion();
    void editarTiempoEstacion();
    void editarnomEstacion();
};

#endif // ESTACION_H
