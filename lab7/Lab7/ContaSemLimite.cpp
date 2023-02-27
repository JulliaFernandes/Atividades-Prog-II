# include "ContaSemLimite.hpp"

using namespace std;

ContaSemLimite :: ContaSemLimite(){
    this -> setProximo(NULL);
}
ContaSemLimite :: ContaSemLimite(string _nome, int _numeroDaConta) : Conta(_nome, _numeroDaConta){
    this -> setProximo(NULL);
}

void ContaSemLimite :: setProximo(ContaSemLimite* _proximo){
    this -> proximo = _proximo;
}
ContaSemLimite* ContaSemLimite  :: getProximo(){
    return this -> proximo;
}