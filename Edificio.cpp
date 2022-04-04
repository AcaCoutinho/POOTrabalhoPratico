#include "Edificio.h"

Edificio::Edificio() : desligado(false), destruido(false){

}

Edificio::~Edificio() {

}

Edificio &Edificio::operator=(const Edificio &edificio) {
    if(this != &edificio){
        destruido = edificio.destruido;
        desligado = edificio.desligado;
    }
    return *this;
}

void Edificio::desliga() {
    desligado = true;
}

void Edificio::destroi() {
    destruido = true;
}

void Edificio::liga() {
    desligado = false;
}

