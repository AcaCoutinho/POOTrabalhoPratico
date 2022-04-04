#ifndef TP_FINAL_UI_H
#define TP_FINAL_UI_H

#include "Ilha.h"
#include "Save.h"
#include <vector>
#include <sstream>
#include <fstream>


class UI {
private:

    string coisa[4];
    Ilha ilha;
    vector<Save *> saves;
    int terminar;

public:
    UI(Ilha& ilha);
    ~UI();

    void adicionaSave(const string &nomeSave,const Ilha &ilhaSave);
    void removeSave(const string &nomeSave);
    Save* restauraSave (const string &nomeSave);

    void jogo ();
    void leComandos ();
    void leFicheiroComandos (const string &nomeFicheiro);
    void leFicheiroConfig (const string &nomeFicheiro);

};


#endif //TP_FINAL_UI_H
