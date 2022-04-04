#ifndef TP_FINAL_MINACARVAO_H
#define TP_FINAL_MINACARVAO_H

#include "Edificio.h"

class MinaCarvao : public Edificio{
private:
    int nivel;
public:
    MinaCarvao();
    ~MinaCarvao() override;

    int trabalha() override;
    void upgrade () override;

    Edificio* duplicaEdificio () const override;
    string getEdificioString () const override;
};


#endif //TP_FINAL_MINACARVAO_H
