#ifndef TP_FINAL_FUNDICAO_H
#define TP_FINAL_FUNDICAO_H

#include "Edificio.h"

class Fundicao : public Edificio{
private:

public:
    Fundicao();
    ~Fundicao() override;

    int trabalha() override;
    void upgrade () override;

    Edificio* duplicaEdificio () const override;
    string getEdificioString () const override;
};


#endif //TP_FINAL_FUNDICAO_H
