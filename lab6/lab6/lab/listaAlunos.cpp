#include "listaAlunos.hpp"
#include <iostream>
#include <string>

using namespace std;

ListaAluno :: ListaAluno(){
    primeiro = NULL;
    ultimo = NULL;
}

ListaAluno :: ListaAluno(string nome, string endereco){
    primeiro = new Aluno(nome, endereco);
    ultimo = primeiro;
    this -> nItens = 0;
}

void ListaAluno :: inserir(string nome, string endereco){
    Aluno* novo_aluno = new Aluno(nome, endereco);

    if(vazia()){
        primeiro = novo_aluno;
        ultimo = novo_aluno;
    }
    else{
        ultimo -> setProximo(novo_aluno);
        ultimo = novo_aluno;
    }
}

ListaAluno :: ~ListaAluno(){
    delete primeiro;
}

void ListaAluno :: setPrimeiro(){
    this -> primeiro = primeiro;
}
Aluno* ListaAluno ::  getPrimeiro(){
    return primeiro;
}

void ListaAluno :: setUltimo(){
    this -> ultimo = ultimo;
}
Aluno*  ListaAluno :: getUltimo(){
    return ultimo;
}

bool ListaAluno :: vazia(){
    return (primeiro == NULL);
}
