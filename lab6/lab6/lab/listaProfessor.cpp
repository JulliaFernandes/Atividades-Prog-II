#include "listaProfessor.hpp"
#include <iostream>
#include <string> 

using namespace std;

#include "listaProfessor.hpp"


ListaProfessor :: ListaProfessor(){
    primeiro = NULL;
    ultimo = NULL;
}

ListaProfessor :: ListaProfessor(string nome, string endereco, string titulacao, string curso){
    primeiro = new Professor (nome, endereco, titulacao, curso);
    ultimo = primeiro;
}

void ListaProfessor :: inserir(string nome, string endereco, string titulacao, string curso){
    Professor* novo_Professor = new Professor(nome, endereco, titulacao, curso);

    if(vazia()){
        primeiro = novo_Professor;
        ultimo = novo_Professor;
    }
    else{
        ultimo -> setProximo(novo_Professor);
        ultimo = novo_Professor;
    }
}

ListaProfessor :: ~ListaProfessor(){
    delete primeiro;
}

void ListaProfessor :: setPrimeiro(Professor* primeiro){
    this -> primeiro = primeiro;
}
Professor* ListaProfessor ::  getPrimeiro(){
    return primeiro;
}

void ListaProfessor :: setUltimo(Professor* ultimo){
    this -> ultimo = ultimo;
}
Professor* ListaProfessor :: getUltimo(){
    return ultimo;
}
bool ListaProfessor :: vazia(){
    return (primeiro == NULL);
}

