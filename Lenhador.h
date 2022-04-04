#ifndef TP_FINAL_LENHADOR_H
#define TP_FINAL_LENHADOR_H

#include "Trabalhador.h"

class Lenhador : public Trabalhador{
private:
    int preco;
    int diasTrabalha;

public:
    Lenhador ();
    ~Lenhador() override;
    Trabalhador* duplicaTrabalhador () const override;

    void trabalha() override;
    void irEmbora() override;
};


#endif
