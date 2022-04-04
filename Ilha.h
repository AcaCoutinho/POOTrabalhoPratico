#ifndef TP_FINAL_ILHA_H
#define TP_FINAL_ILHA_H

#include "Zona.h"
#include <iostream>

using namespace std;

class Ilha {
private:
    int money = 0, dia = 1;
    int linha, coluna;
    Zona **zonas;
    vector<Trabalhador *> trabalhadoresTotal;
    float ferro = 0, barra = 0, carvao = 0, madeira = 0, vigas = 0, elect = 0;

public:
    Ilha();
    Ilha(const Ilha &ilha);
    ~Ilha();

    void criaIlha();

    int getMoney ();
    int getDia ();
    int getLinha();
    int getColuna();
    void setDia (int n);
    void setLinha (int linha);
    void setColuna (int coluna);
    Zona& getZona (const int &linha, const int &coluna);
    void setMoney(int n);
    void setFerro (float n);
    void setBarra (float n);
    void setCarvao (float n);
    void setMadeira (float n);
    void setVigas (float n);
    void setElect (float n);
    float getFerro ();
    float getBarra ();
    float getCarvao ();
    float getMadeira ();
    float getVigas ();
    float getElect ();

    void eliminaTrabalhador (const string &id);
    Trabalhador* encontraTrabalhador (const string &id);
    void acrescentaTrabalhador (const string &tipo);
    string getIDUltimoTrabalhador () const;

    string getIlhaString () const;
    string getRecusrsosString () const;
    Ilha& operator = (const Ilha &ilha);

    Zona &encontraPasto();
};

#endif