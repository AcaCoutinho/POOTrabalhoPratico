#ifndef TP_FINAL_CENTRAL_H
#define TP_FINAL_CENTRAL_H

#include "Edificio.h"

class Central : public Edificio{
private:

public:
    Central();
    ~Central() override;

    int trabalha() override;
    void upgrade () override;

    Edificio* duplicaEdificio () const override;
    string getEdificioString () const override;

};


#endif //TP_FINAL_CENTRAL_H
