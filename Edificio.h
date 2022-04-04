#ifndef TP_FINAL_EDIFICIO_H
#define TP_FINAL_EDIFICIO_H

#include <iostream>

using namespace std;

class Edificio {
private:
    bool desligado;
    bool destruido;
public:
    Edificio();
    virtual ~Edificio();

    virtual int trabalha () = 0;
    virtual void upgrade () = 0;

    void desliga ();
    void liga ();
    void destroi ();

    virtual Edificio* duplicaEdificio () const = 0;

    virtual string getEdificioString () const = 0;
    Edificio& operator=(const Edificio &edificio);
};


#endif //TP_FINAL_EDIFICIO_H
