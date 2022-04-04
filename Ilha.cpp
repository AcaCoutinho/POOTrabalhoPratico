#include "Ilha.h"
#include "Mineiro.h"
#include "Lenhador.h"
#include "Operario.h"
#include <sstream>

Ilha::Ilha() : zonas(nullptr) { }

Ilha::Ilha(const Ilha &ilha) {
    *this = ilha;
}

Ilha::~Ilha() {
    for (int i = 0; i < linha; ++i)
        delete [] zonas[i];
    delete [] zonas;
}

void Ilha::criaIlha() {
    int num = 0;
    zonas = new Zona * [linha];
    for (int i = 0; i < linha; i++)
        zonas[i] = new Zona[coluna];

    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            zonas[i][j].setZona(num);
            num++;
            if(num > 5){
                num = 0;
            }
        }
    }
}

string Ilha::getIlhaString() const {
    ostringstream oss;

    for (int i = 0; i < linha; i++){
        for (int k = 0; k < 4; k++){
            oss << "\n\t";
            for (int j = 0; j < coluna; j++){
                switch(k){
                    case 0:
                        oss << "|" << zonas[i][j].getTipoZona() << "|";
                        break;
                    case 1:
                        oss << "|" << zonas[i][j].getEdificioString() << "|";
                        break;
                    case 2:
                        oss << "|" << "    " << "|";
                        break;
                    case 3:
                        oss << "|" << zonas[i][j].getNumTrabalhadoresString() << "|";
                        break;
                }
            }
        }
        oss << "\n";
    }
    oss << endl;

    return oss.str();
}

Ilha &Ilha::operator=(const Ilha &ilha) {
    if(this != &ilha){

    }
    return *this;
}

int Ilha::getMoney() {
    return money;
}

int Ilha::getDia() {
    return dia;
}

Zona &Ilha::getZona(const int &linha, const int &coluna) {
    return zonas[linha][coluna];
}

void Ilha::eliminaTrabalhador(const string &id) {
    for (auto it = trabalhadoresTotal.begin(); it < trabalhadoresTotal.end(); it++){
        if((*it)->getID() == id){
            it = trabalhadoresTotal.erase(it);
        }
    }
}

Trabalhador *Ilha::encontraTrabalhador(const string &id) {
    for (auto it = trabalhadoresTotal.begin(); it < trabalhadoresTotal.end(); it++){
        if((*it)->getID() == id){
            return *it;
        }
    }
    return nullptr;
}

void Ilha::acrescentaTrabalhador(const string &tipo) {
    if(tipo == "mineiro"){
        trabalhadoresTotal.push_back(new Mineiro());
    }
    else if(tipo == "operario"){
        trabalhadoresTotal.push_back(new Operario());
    }
    else if(tipo == "lenhador"){
        trabalhadoresTotal.push_back(new Lenhador());
    }
}

int Ilha::getLinha() {
    return linha;
}

int Ilha::getColuna() {
    return coluna;
}

void Ilha::setLinha(int linha1) {
    linha = linha1;
}

void Ilha::setColuna(int coluna1) {
    coluna = coluna1;
}

void Ilha::setMoney(int n) {
    money = n;
}

string Ilha::getRecusrsosString() const {
    ostringstream oss;

    oss << "Ferro: " << ferro << endl;
    oss << "Barras de aco: " << barra << endl;
    oss << "Carvao: " << carvao << endl;
    oss << "Madeira: " << madeira << endl;
    oss << "Vigas de Madeira: " << vigas << endl;
    oss << "Electricidade: " << elect << endl;

    return oss.str();
}

void Ilha::setDia(int n) {
    dia = n;
}

void Ilha::setFerro(float n) {
    ferro = n;
}

void Ilha::setBarra(float n) {
    barra = n;
}

void Ilha::setCarvao(float n) {
    carvao = n;
}

void Ilha::setMadeira(float n) {
    madeira = n;
}

void Ilha::setVigas(float n) {
    vigas = n;
}

void Ilha::setElect(float n) {
    elect = n;
}

float Ilha::getFerro() {
    return ferro;
}

float Ilha::getBarra() {
    return barra;
}

float Ilha::getCarvao() {
    return carvao;
}

float Ilha::getMadeira() {
    return madeira;
}

float Ilha::getVigas() {
    return vigas;
}

float Ilha::getElect() {
    return elect;
}

Zona &Ilha::encontraPasto() {
    for(int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            if(zonas[i][j].getTipoZona() == " pas")
                return zonas[i][j];
        }
    }
}

string Ilha::getIDUltimoTrabalhador() const{
    return trabalhadoresTotal.back()->getID();
}

