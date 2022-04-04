#ifndef TP_FINAL_ZONA_H
#define TP_FINAL_ZONA_H

#include <iostream>
#include "Trabalhador.h"
#include "Edificio.h"
#include <vector>

using namespace std;

class Zona {
private:

    string tipoZona;
    Edificio *edificio;
    bool edificioLigado;
    vector<Trabalhador *> trabalhadores;

public:

    Zona();
    Zona(const Zona &zona);
    ~Zona();

    Edificio *getEdificio () const;

    void acrescentaTrabalhador (Trabalhador* trabalhador);
    void eliminaDespedidos ();
    void removeTrabalhador (const string &id);

    void setZona (int num);
    string getTipoZona () const;
    string getZonaString () const;
    string getTrabalhadoresString () const;
    string getNumTrabalhadoresString () const;
    string getEdificioString () const;
};


#endif
