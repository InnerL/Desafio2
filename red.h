#ifndef RED_H
#define RED_H
#include <iostream>
#include <string>
using namespace std;

class red{
    string nomRed;
    string *linea;
    int cantLinea;

public:
    //Constructor-Destructor
    red(string _nomRed, string *_linea, int _cantLinea) {nomRed = _nomRed; *linea = *_linea; cantLinea = _cantLinea;};
    red(){};


    //Metodos
    void estabecerNombre(string);
    void agregarLinea();
    void eliminarLinea();
    int cantLineas();
    int cantEstacionRed();

};


#endif // RED_H
