#include "Lenhador.h"

Lenhador::Lenhador() : diasTrabalha(0){

}

Trabalhador *Lenhador::duplicaTrabalhador() const {
    return new Lenhador(*this);
}

void Lenhador::trabalha() {
    if(diasTrabalha == 4){
        diasTrabalha = 0;
        return;
    }
    diasTrabalha++;
}

void Lenhador::irEmbora() { }

Lenhador::~Lenhador() {

}
