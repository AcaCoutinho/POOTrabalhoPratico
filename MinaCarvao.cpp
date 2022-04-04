#include "MinaCarvao.h"

MinaCarvao::MinaCarvao() : nivel(1){

}

MinaCarvao::~MinaCarvao() {

}

int MinaCarvao::trabalha() {
    return 2;
}

void MinaCarvao::upgrade() {
    if(nivel == 5)
        return;
    nivel += 1;
}

Edificio *MinaCarvao::duplicaEdificio() const {
    return new MinaCarvao(*this);
}

string MinaCarvao::getEdificioString() const {
    return " mnc";
}
