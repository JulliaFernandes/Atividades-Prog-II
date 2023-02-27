#include "ListaContaSemLimite.hpp"

ListaContaSemLimite :: ListaContaSemLimite(){
    primeiro = NULL;
    ultimo = NULL;
    this -> setItens(0);
}
ListaContaSemLimite :: ListaContaSemLimite(string _nome, int _numeroDaConta){
    primeiro = new ContaSemLimite(_nome, _numeroDaConta);
    ultimo = primeiro;
    this -> setItens(0);
}

void ListaContaSemLimite ::setPrimeiro(ContaSemLimite* _primeiro){
    this -> primeiro = _primeiro;
}
ContaSemLimite* ListaContaSemLimite :: getPrimeiro(){
    return  this -> primeiro;
}


void ListaContaSemLimite :: setUltimo(ContaSemLimite* _ultimo){
    this -> ultimo = _ultimo;
}
ContaSemLimite* ListaContaSemLimite :: getUltimo(){
    return this -> ultimo;
}


void ListaContaSemLimite :: setItens(int _itens){
    this -> itens = _itens;
}
int ListaContaSemLimite :: getItens(){
    return this -> itens;
}


ListaContaSemLimite :: ~ListaContaSemLimite(){
    delete primeiro;
}

bool ListaContaSemLimite :: vazia(){
    return (primeiro == NULL);
}

void ListaContaSemLimite ::inserirFinal(ContaSemLimite* contaa){

    if(vazia()){
         primeiro = contaa;
         ultimo = contaa;
         itens++;
    }
    else{
        ultimo -> setProximo(contaa);
        ultimo = contaa;
        itens++;
    }

}

