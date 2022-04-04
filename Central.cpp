#include "Central.h"

Central::Central() {

}

Central::~Central() {

}

int Central::trabalha() {
    return 1;
}

void Central::upgrade() {}

Edificio *Central::duplicaEdificio() const {
    return new Central(*this);
}

string Central::getEdificioString() const {
    return "elec";
}
