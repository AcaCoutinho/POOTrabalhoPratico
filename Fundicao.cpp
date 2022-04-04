#include "Fundicao.h"

string Fundicao::getEdificioString() const {
    return " fun";
}

Edificio *Fundicao::duplicaEdificio() const {
    return new Fundicao(*this);
}

int Fundicao::trabalha() {
    return 0;
}

Fundicao::~Fundicao() {

}

Fundicao::Fundicao() {

}

void Fundicao::upgrade() {}
