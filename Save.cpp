#include "Save.h"

Save::Save(const string &nome, const Ilha &ilha) : saveNome(nome), ilhaSave(ilha){

}

Save::~Save() {

}

string Save::getSaveNome() const {
    return saveNome;
}

Ilha Save::getIlha() const {
    return ilhaSave;
}
