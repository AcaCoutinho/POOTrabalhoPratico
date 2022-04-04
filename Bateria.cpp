#include "Bateria.h"

Bateria::Bateria() : nivel(1), capacidade(100) {

}

Bateria::~Bateria() {

}

int Bateria::trabalha() {
    return 0;
}

void Bateria::upgrade() {
    if(nivel == 5)
        return;
    nivel += 1;
    capacidade += 10;
}

Edificio *Bateria::duplicaEdificio() const {
    return new Bateria(*this);
}

string Bateria::getEdificioString() const {
    return " bat";
}
