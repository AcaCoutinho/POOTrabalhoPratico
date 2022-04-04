//
// Created by couti on 13/01/2022.
//

#ifndef TP_FINAL_EDIFICIOX_H
#define TP_FINAL_EDIFICIOX_H

#include "Edificio.h"



class EdificioX : Edificio{
private:
    int nivel;
public:
    EdificioX();
    ~EdificioX() override;

    int trabalha() override;
    void upgrade () override;

    Edificio* duplicaEdificio () const override;
    string getEdificioString () const override;
};


#endif //TP_FINAL_EDIFICIOX_H
