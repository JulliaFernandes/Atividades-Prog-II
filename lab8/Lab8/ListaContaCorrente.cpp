#include "ListaContaCorrente.hpp"
#include <iostream>
#include <string>

using namespace std;

ListaContaCorrente :: ListaContaCorrente(){
    primeiro = NULL;
    ultimo = NULL;
    this -> setItens(0);
}
ListaContaCorrente :: ListaContaCorrente(string _nome, int _numeroDaConta, double _limite, double _limiteAux){
    primeiro = new ContaCorrente(_nome, _numeroDaConta, _limite, _limiteAux);
    ultimo = primeiro;
    this -> setItens(0);
}

void ListaContaCorrente ::setPrimeiro(ContaCorrente* _primeiro){
    this -> primeiro = _primeiro;
}
ContaCorrente* ListaContaCorrente :: getPrimeiro(){
    return  this -> primeiro;
}


void ListaContaCorrente :: setUltimo(ContaCorrente* _ultimo){
    this -> ultimo = _ultimo;
}
ContaCorrente* ListaContaCorrente :: getUltimo(){
    return this -> ultimo;
}


void ListaContaCorrente :: setItens(int _itens){
    this -> itens = _itens;
}
int ListaContaCorrente :: getItens(){
    return this -> itens;
}


ListaContaCorrente :: ~ListaContaCorrente(){
    delete primeiro;
}

bool ListaContaCorrente :: vazia(){
    return (primeiro == NULL);
}

void ListaContaCorrente :: inserirFinal(ContaCorrente* conta){
    if(vazia()){
        setPrimeiro(conta);
        setUltimo(conta);
        setItens(getItens() +1);
    }
    else{
        getUltimo() -> setProximo(conta);
        setUltimo(conta);
        setItens(getItens() +1);
    }
}

