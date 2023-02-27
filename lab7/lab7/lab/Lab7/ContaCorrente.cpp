#include "ContaCorrente.hpp"

using namespace std;

ContaCorrente :: ContaCorrente(){

}
ContaCorrente :: ContaCorrente(string _nome, int _numeroDaConta, double _limite, double _limiteAux) : Conta(_nome, _numeroDaConta){
    this -> limite = _limite;
    this -> limiteAux = _limite;
    this -> setProximo(NULL);
}


void ContaCorrente:: setLimite(double _limite){
    this -> limite = _limite;
}
double ContaCorrente :: getLimite(){
    return this -> limite;
}

void ContaCorrente:: setLimiteAux(double _limiteAux){
    this -> limiteAux = limite;
}
double ContaCorrente :: getLimiteAux(){
    return this -> limiteAux;
}

void ContaCorrente :: setProximo(ContaCorrente* _proximo){
    this -> proximo = _proximo;
}
ContaCorrente* ContaCorrente :: getProximo(){
    return this -> proximo;
}