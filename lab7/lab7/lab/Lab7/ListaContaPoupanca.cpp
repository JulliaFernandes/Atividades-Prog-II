#include "ListaContaPoupanca.hpp"
#include <iostream>
#include <string>

using namespace std;

ListaContaPoupanca :: ListaContaPoupanca(){
    primeiro = NULL;
    ultimo = NULL;
    this -> setItens(0);
}
ListaContaPoupanca :: ListaContaPoupanca(string _nome, int _numeroDaConta, string _aniversario){
    primeiro = new ContaPoupanca(_nome, _numeroDaConta, _aniversario);
    ultimo = primeiro;
    this -> setItens(0);
}

void ListaContaPoupanca :: setPrimeiro(ContaPoupanca* _primeiro){
    this -> primeiro = _primeiro;
}
ContaPoupanca* ListaContaPoupanca :: getPrimeiro(){
    return  this -> primeiro;
}


void ListaContaPoupanca :: setUltimo(ContaPoupanca* _ultimo){
    this -> ultimo = _ultimo;
}
ContaPoupanca* ListaContaPoupanca :: getUltimo(){
    return this -> ultimo;
}


void ListaContaPoupanca :: setItens(int _itens){
    this -> itens = _itens;
}
int ListaContaPoupanca :: getItens(){
    return this -> itens;
}


ListaContaPoupanca :: ~ListaContaPoupanca(){
    delete primeiro;
}

bool ListaContaPoupanca :: vazia(){
    return (primeiro == NULL);
}

void ListaContaPoupanca :: inserirFinal(ContaPoupanca* conta){
    if(getItens() == 0){
        setPrimeiro(conta);
        setUltimo(conta);
        setItens(getItens() +1);
    }
    else{
        
        getUltimo() -> setProximo(conta);
        setUltimo(conta);
        setItens( getItens() +1);
    }
}
