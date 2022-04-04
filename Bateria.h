#ifndef TP_FINAL_BATERIA_H
#define TP_FINAL_BATERIA_H

#include "Edificio.h"

class Bateria : public Edificio{
private:
    int nivel;
    int capacidade;
public:
    Bateria();
    ~Bateria() override;

    int trabalha() override;
    void upgrade () override;

    Edificio* duplicaEdificio () const override;
    string getEdificioString () const override;
};


#endif //TP_FINAL_BATERIA_H
