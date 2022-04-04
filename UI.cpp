#include "UI.h"

UI::UI(Ilha &ilha) : ilha(ilha), terminar(0){ }

UI::~UI() { }

void UI::adicionaSave(const string &nomeSave, const Ilha &ilhaSave) {
    for (auto it = saves.begin(); it < saves.end(); it++){
        if (nomeSave == (*it)->getSaveNome())
            return;
    }
    saves.push_back(new Save(nomeSave, ilhaSave));
}

void UI::removeSave(const string &nomeSave) {
    for (auto it = saves.begin(); it < saves.end(); it++){
        if (nomeSave == (*it)->getSaveNome()){
            it = saves.erase(it);
        }
    }
}

Save *UI::restauraSave(const string &nomeSave) {
    for (auto it = saves.begin(); it < saves.end(); it++){
        if(nomeSave == (*it)->getSaveNome())
            return (*it);
    }
    return nullptr;
}

void UI::jogo() {

    int linha, coluna;

    cout << "Digite a linha e coluna que pretende:" << endl;
    cin >> linha >> coluna;
    ilha.setLinha(linha);
    ilha.setColuna(coluna);

    ilha.criaIlha();

    do{
        cout << "Inicio do dia: " << ilha.getDia() << endl;
        for (int i = 0; i < 3; i++){
            if(i == 0){
                cout << "Inicio da manha: " << endl;
                //acontecem os efeitos das zonas
            }
            if(i == 1){
                cout << "Inicio da tarde: " << endl;
                leComandos();
            }
            if(i == 2){
                cout << "Inicio da noite: " << endl;
                //recolha de recursos obtidos, considerando as mudanças da tarde
                cout << "Fim do dia " << ilha.getDia() << endl;
                cout << "Dinheiro: " << ilha.getMoney() << endl;
                cout << ilha.getRecusrsosString();
                ilha.setDia(ilha.getDia() + 1);
            }
        }
    }
    while (terminar == 0);
}

void UI::leComandos() {
    string linhas, comando, tipo, nome, ficheiro, id;
    int linha, coluna, quanto, valor;
    float unidades;

    while(getline(cin, linhas)){
        istringstream iss(linhas);

        iss >> comando;
        if(comando == "next"){
            cout << ilha.getIlhaString() << endl;
            break;
        }
        if(comando == "exec"){
            iss >> ficheiro;
            leFicheiroComandos(ficheiro);
            cout << ilha.getIlhaString() << endl;
            break;
        }
        if(comando == "cons"){
            iss >> tipo >> linha >> coluna;
            if (tipo == "minaferro"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "minacarvao"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "central"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "bateria"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "fundicao"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "edificiox"){
                ilha.getZona(linha, coluna);
            }
            else{
                cout << "Esse tipo de edificio nao existe!" << endl;
            }
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "liga"){
            iss >> linha >> coluna;
            ilha.getZona(linha, coluna); //ligar edificio
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "des"){
            iss >> linha >> coluna;
            ilha.getZona(linha, coluna); //desliga edificio
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "move"){
            iss >> id >> linha >> coluna;

            //ilha.getZona(linha, coluna).acrescentaTrabalhador(ilha.encontraTrabalhador(id));
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "vende"){
            iss >> tipo >> unidades;
            if(tipo == "ferro"){
                ilha.setMoney(ilha.getMoney() + unidades);
                ilha.setFerro(ilha.getFerro() - unidades);
            }
            else if(tipo == "carvao") {
                ilha.setMoney(ilha.getMoney() + unidades);
                ilha.setFerro(ilha.getFerro() - unidades);
            }
            else if(tipo == "madeira"){
                ilha.setMoney(ilha.getMoney() + unidades);
                ilha.setFerro(ilha.getFerro() - unidades);
            }
            else if(tipo == "vigas"){
                ilha.setMoney(ilha.getMoney() + unidades*2);
                ilha.setFerro(ilha.getFerro() - unidades);
            }
            else if(tipo == "eletrecidade"){
                ilha.setMoney(ilha.getMoney() + unidades*1.5);
                ilha.setFerro(ilha.getFerro() - unidades);
            }
            else if(tipo == "barra"){
                ilha.setMoney(ilha.getMoney() + unidades*2);
                ilha.setFerro(ilha.getFerro() - unidades);
            }
            else {
                cout << "Esse recurso nao existe" << endl;
            }
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "cont"){
            iss >> tipo;
            if(tipo == "mineiro"){
                ilha.acrescentaTrabalhador(tipo);

            }
            else if(tipo == "operario"){
                ilha.acrescentaTrabalhador(tipo);
            }
            else if(tipo == "lenhador"){
                ilha.acrescentaTrabalhador(tipo);
            }
            else {
                cout << "Nao existe esse tipo de trabalhador" << endl;
            }
            ilha.encontraPasto().acrescentaTrabalhador(ilha.encontraTrabalhador(ilha.getIDUltimoTrabalhador()));
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "list"){
            iss >> linha >> coluna;
            cout << ilha.getZona(linha, coluna).getZonaString() << endl;
        }
        if(comando == "vende"){
            iss >> linha >> coluna;
            tipo = ilha.getZona(linha, coluna).getEdificio()->getEdificioString();
            if(tipo == "minaferro"){
                ilha.getZona(linha, coluna).getEdificio()->destroi();
                ilha.setMoney(ilha.getMoney() + 100);
            }
            if(tipo == "minacarvao"){
                ilha.getZona(linha, coluna).getEdificio()->destroi();
                ilha.setMoney(ilha.getMoney() + 100);
            }
            if(tipo == "central"){
                ilha.getZona(linha, coluna).getEdificio()->destroi();
                ilha.setMoney(ilha.getMoney() + 15);
            }
            if(tipo == "bateria"){
                ilha.getZona(linha, coluna).getEdificio()->destroi();
                ilha.setMoney(ilha.getMoney() + 10);
            }
            if(tipo == "fundicao"){
                ilha.getZona(linha, coluna).getEdificio()->destroi();
                ilha.setMoney(ilha.getMoney() + 10);
            }
            if(tipo == "edificiox"){
                ilha.getZona(linha, coluna).getEdificio()->destroi();
                ilha.setMoney(ilha.getMoney() + 50);
            }
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "save"){
            iss >> nome;
            adicionaSave(nome, ilha);
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "load"){
            iss >> nome;
            ilha = restauraSave(nome)->getIlha();
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "apaga"){
            iss >> nome;
            removeSave(nome);
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "config"){
            iss >> ficheiro;
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "debcash"){
            iss >> valor;
            if(valor >= 0){
                ilha.setMoney(ilha.getMoney() + valor);
            }
            else{
                ilha.setMoney(ilha.getMoney() - abs(valor));
            }
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "debed"){
            iss >> tipo >> linha >> coluna;
            if(tipo == "minaferro"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "minacarvao"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "central"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "bateria"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "fundicao"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "edificiox"){
                ilha.getZona(linha, coluna);
            }
            else{
                cout << "Este tipo de edificio nao existe" << endl;
            }
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "debkill"){
            iss >> id;
            ilha.eliminaTrabalhador(id);
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "terminar"){
            terminar = 1;
            cout << ilha.getIlhaString() << endl;
            break;
        }
    }
}

void UI::leFicheiroComandos(const string &nomeFicheiro) {
    string linhas, comando, nome, tipo, id, ficheiro;
    int linha, coluna, quanto, valor;
    float unidades;

    ifstream ifs;
    ifs.open(nomeFicheiro);

    while (getline(ifs, linhas)){
        istringstream iss(linhas);

        iss >> comando;
        if(comando == "next"){
            break;
        }
        if(comando == "cons"){
            iss >> tipo >> linha >> coluna;
            if (tipo == "minaferro"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "minacarvao"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "central"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "bateria"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "fundicao"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "edificiox"){
                ilha.getZona(linha, coluna);
            }
            else{
                cout << "Esse tipo de edificio nao existe!" << endl;
            }
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "liga"){
            iss >> linha >> coluna;
            ilha.getZona(linha, coluna); //ligar edificio
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "des"){
            iss >> linha >> coluna;
            ilha.getZona(linha, coluna); //desliga edificio
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "move"){
            iss >> id >> linha >> coluna;
            ilha.encontraTrabalhador(id)->setZona(&(ilha.getZona(linha, coluna)));
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "vende"){
            iss >> tipo >> unidades;
            if(tipo == "ferro"){
                ilha.setMoney(ilha.getMoney() + unidades);
                ilha.setFerro(ilha.getFerro() - unidades);
            }
            else if(tipo == "carvao") {
                ilha.setMoney(ilha.getMoney() + unidades);
                ilha.setFerro(ilha.getFerro() - unidades);
            }
            else if(tipo == "madeira"){
                ilha.setMoney(ilha.getMoney() + unidades);
                ilha.setFerro(ilha.getFerro() - unidades);
            }
            else if(tipo == "vigas"){
                ilha.setMoney(ilha.getMoney() + unidades*2);
                ilha.setFerro(ilha.getFerro() - unidades);
            }
            else if(tipo == "eletrecidade"){
                ilha.setMoney(ilha.getMoney() + unidades*1.5);
                ilha.setFerro(ilha.getFerro() - unidades);
            }
            else if(tipo == "barra"){
                ilha.setMoney(ilha.getMoney() + unidades*2);
                ilha.setFerro(ilha.getFerro() - unidades);
            }
            else {
                cout << "Esse recurso nao existe" << endl;
            }
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "cont"){
            iss >> tipo;
            if(tipo == "mineiro"){
                ilha.acrescentaTrabalhador(tipo);
            }
            else if(tipo == "operario"){
                ilha.acrescentaTrabalhador(tipo);
            }
            else if(tipo == "lenhador"){
                ilha.acrescentaTrabalhador(tipo);
            }
            else {
                cout << "Nao existe esse tipo de trabalhador" << endl;
            }
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "list"){
            iss >> linha >> coluna;
            cout << ilha.getZona(linha, coluna).getZonaString() << endl;
        }
        if(comando == "vende"){
            iss >> linha >> coluna;
            tipo = ilha.getZona(linha, coluna).getEdificio()->getEdificioString();
            if(tipo == "minaferro"){
                ilha.getZona(linha, coluna).getEdificio()->destroi();
                ilha.setMoney(ilha.getMoney() + 100);
            }
            if(tipo == "minacarvao"){
                ilha.getZona(linha, coluna).getEdificio()->destroi();
                ilha.setMoney(ilha.getMoney() + 100);
            }
            if(tipo == "central"){
                ilha.getZona(linha, coluna).getEdificio()->destroi();
                ilha.setMoney(ilha.getMoney() + 15);
            }
            if(tipo == "bateria"){
                ilha.getZona(linha, coluna).getEdificio()->destroi();
                ilha.setMoney(ilha.getMoney() + 10);
            }
            if(tipo == "fundicao"){
                ilha.getZona(linha, coluna).getEdificio()->destroi();
                ilha.setMoney(ilha.getMoney() + 10);
            }
            if(tipo == "edificiox"){
                ilha.getZona(linha, coluna).getEdificio()->destroi();
                ilha.setMoney(ilha.getMoney() + 50);
            }
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "save"){
            iss >> nome;
            adicionaSave(nome, ilha);
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "load"){
            iss >> nome;
            ilha = restauraSave(nome)->getIlha();
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "apaga"){
            iss >> nome;
            removeSave(nome);
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "config"){
            iss >> ficheiro;
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "debcash"){
            iss >> valor;
            if(valor >= 0){
                ilha.setMoney(ilha.getMoney() + valor);
            }
            else{
                ilha.setMoney(ilha.getMoney() - abs(valor));
            }
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "debed"){
            iss >> tipo >> linha >> coluna;
            if(tipo == "minaferro"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "minacarvao"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "central"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "bateria"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "fundicao"){
                ilha.getZona(linha, coluna);
            }
            else if(tipo == "edificiox"){
                ilha.getZona(linha, coluna);
            }
            else{
                cout << "Este tipo de edificio nao existe" << endl;
            }
            cout << ilha.getIlhaString() << endl;
        }
        if(comando == "debkill"){
            iss >> id;
            ilha.eliminaTrabalhador(id);
            cout << ilha.getIlhaString() << endl;
        }
    }

    ifs.close();
}