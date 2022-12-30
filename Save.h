#ifndef TP_FINAL_SAVE_H
#define TP_FINAL_SAVE_H

#include "Ilha.h"

class Save {
private:

    string saveNome;
    Ilha ilhaSave;

public:

    Save(const string &nome, const Ilha &ilha);
    ~Save();

    string getSaveNome () const;
    Ilha getIlha () const;
};


#endif //TP_FINAL_SAVE_H
