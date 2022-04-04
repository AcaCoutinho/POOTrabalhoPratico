#include "EdificioX.h"
#include "Zona.h"

EdificioX::EdificioX() {

}

EdificioX::~EdificioX() {

}

int EdificioX::trabalha() {
        return 1;
}

void EdificioX::upgrade() {
    if(nivel == 5)
        return;
    nivel += 1;
}

Edificio *EdificioX::duplicaEdificio() const {
    return new EdificioX(*this);
}

string EdificioX::getEdificioString() const {
    return " edX";
}
