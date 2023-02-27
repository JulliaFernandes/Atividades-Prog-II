#include "ContaPoupanca.hpp"
#include <iostream>
using namespace std;

ContaPoupanca :: ContaPoupanca(){

}
ContaPoupanca :: ContaPoupanca(string _nome, int _numeroDaConta, string _aniversario) : Conta(_nome, _numeroDaConta){
    this -> aniversario = _aniversario;
    this -> setProximo(NULL);
}

void ContaPoupanca :: setAniversario(string _aniversario){
    this -> aniversario = _aniversario;
}
string ContaPoupanca :: getAniversario(){
    return this -> aniversario;
}

void ContaPoupanca :: setProximo(ContaPoupanca* _proximo){
    this -> proximo = _proximo;
}
ContaPoupanca* ContaPoupanca  :: getProximo(){
    return this -> proximo;
}