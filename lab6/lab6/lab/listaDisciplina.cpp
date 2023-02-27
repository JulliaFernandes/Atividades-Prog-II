#include "listaDisciplina.hpp"
#include <iostream>
#include <string>

using namespace std;

int nItens;

ListaDisciplina :: ListaDisciplina(string nome,int ch, Professor* p){
    primeiro = new Disciplina(nome, ch, p);
    ultimo = primeiro;
}

ListaDisciplina :: ListaDisciplina(){
    primeiro = NULL;
    ultimo = NULL;
}

void ListaDisciplina :: inserir(string nome, int CH, Professor* p){
    
    Disciplina* nova_Disciplina = new Disciplina(nome, CH, p);

    if(vazia()){
        primeiro = nova_Disciplina;
        ultimo = nova_Disciplina;
    }
    else{
        ultimo -> setProximo(nova_Disciplina);
        ultimo = nova_Disciplina;
    }
}

void ListaDisciplina:: setPrimeiro(){
    this -> primeiro = primeiro;
}

Disciplina* ListaDisciplina :: getPrimeiro(){
    return primeiro;
}

void ListaDisciplina :: setUltimo(){
    this -> ultimo = ultimo;
}

Disciplina* ListaDisciplina :: getUltimo(){
    return ultimo;
}

ListaDisciplina :: ~ListaDisciplina(){
    delete primeiro;
}

bool ListaDisciplina :: vazia(){
    return (primeiro == NULL);
}

// ListaDisciplina* ListaDisciplina :: obterProximo(){
//     return this -> proximo;
// }

// void ListaDisciplina :: setProximo(ListaDisciplina* p){
//     this -> proximo = proximo;
// }