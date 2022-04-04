#include "Zona.h"
#include "MinaCarvao.h"
#include <sstream>

Zona::Zona() : edificio(nullptr){
}

Zona::Zona(const Zona &zona) {

}

Zona::~Zona() {

}

string Zona::getTipoZona() const {
    return tipoZona;
}

string Zona::getZonaString() const {
    ostringstream oss;

    oss << "Tipo de Zona: " << getTipoZona() << endl;
    oss << "Edificio: " << getEdificioString() << endl;
    oss << "Numero de trabalhadores:" << getNumTrabalhadoresString() << endl;

    return oss.str();
}

Edificio *Zona::getEdificio() const {
    return edificio;
}

void Zona::setZona(int num) {
    if(num == 0)
        tipoZona = " dsr";
    if(num == 1)
        tipoZona = " pnt";
    if(num == 2)
        tipoZona = " mnt";
    if(num == 3)
        tipoZona = " pas";
    if(num == 4)
        tipoZona = " znX";
    if(num == 5)
        tipoZona = " flr";
}

string Zona::getTrabalhadoresString() const {
    ostringstream oss;

    return oss.str();
}

string Zona::getNumTrabalhadoresString() const {
    ostringstream oss;

    if(trabalhadores.size() < 10){
        oss << "   " << trabalhadores.size();
    }
    if(trabalhadores.size() >= 10 && trabalhadores.size() < 100){
        oss << "  " << trabalhadores.size();
    }
    if(trabalhadores.size() >= 100 && trabalhadores.size() < 1000){
        oss << " " << trabalhadores.size();
    }
    if(trabalhadores.size() >= 1000 && trabalhadores.size() < 10000){
        oss << trabalhadores.size();
    }

    return oss.str();
}

string Zona::getEdificioString() const {
    ostringstream oss;

    if(edificio == nullptr){
        oss << "    ";
    }
    else{
        oss << edificio->getEdificioString();
    }

    return oss.str();
}

void Zona::acrescentaTrabalhador(Trabalhador* trabalhador) {
    for (auto it = trabalhadores.begin(); it < trabalhadores.end(); it++) {
        if ((*it)->getID() == trabalhador->getID())
            return;
    }
    trabalhadores.push_back(trabalhador);
    trabalhador->setZona(this);
}

void Zona::eliminaDespedidos() {
    for (auto it = trabalhadores.begin(); it < trabalhadores.end(); it++){
        if((*it)->getDespedido())
            it = trabalhadores.erase(it);
    }
}

void Zona::removeTrabalhador(const string &id) {
    for (auto it = trabalhadores.begin(); it < trabalhadores.end(); it++){
        if((*it)->getID() == id)
            it = trabalhadores.erase(it);
    }
}
