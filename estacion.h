#ifndef ESTACION_H
#define ESTACION_H
#include <string>

using namespace std;

class estacion {
    string nomEstacion;
    int tiempoSigEstacion;
    int tiempoAntEstacion;
    bool esTransferencia;
    int idEstacion;

public:
    // Constructor
    estacion(string _nomEstacion, int _tiempoSigEstacion, int _tiempoAntEstacion, bool _esTransferencia, int _idEstacion) {
        nomEstacion = _nomEstacion;
        tiempoSigEstacion = _tiempoSigEstacion;
        tiempoAntEstacion = _tiempoAntEstacion;
        esTransferencia = _esTransferencia;
        idEstacion = _idEstacion;
    }

    // Métodos get y set
    string getNomEstacion() const {
        return nomEstacion;
    }
    int getTiempoSigEstacion() const {
        return tiempoSigEstacion;
    }
    int getTiempoAntEstacion() const {
        return tiempoAntEstacion;
    }
    bool getEsTransferencia() const {
        return esTransferencia;
    }
    int getIdEstacion() const {
        return idEstacion;
    }

    void setNomEstacion(const string& _nomEstacion) {
        nomEstacion = _nomEstacion;
    }
    void setTiempoSigEstacion(int _tiempoSigEstacion) {
        tiempoSigEstacion = _tiempoSigEstacion;
    }
    void setTiempoAntEstacion(int _tiempoAntEstacion) {
        tiempoAntEstacion = _tiempoAntEstacion;
    }
    void setEsTransferencia(bool _esTransferencia) {
        esTransferencia = _esTransferencia;
    }

    void eliminarEstacion();
    void editarTiempoEstacion();
    void editarNomEstacion();
};

#endif // ESTACION_H
