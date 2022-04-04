#include <iostream>
#include "Ilha.h"
#include "UI.h"
#include <ctime>
#include <cstdlib>


int main() {
    srand(time(NULL));
    Ilha ilha;
    UI ui(ilha);

    ui.jogo();
    return 0;
}
