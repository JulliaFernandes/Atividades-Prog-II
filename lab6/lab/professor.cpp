#include "professor.hpp"
#include <iostream>

using namespace std;


Professor :: Professor(string nome, string endereco, string titulacao, string curso) : Pessoa(nome, endereco){
    this -> titulacao = titulacao;
    this -> curso = curso; 
    this -> proximo = NULL;
}

Professor :: Professor(){

}

void Professor :: setTitulacao(string titulacao){
    this -> titulacao = titulacao;
}
string Professor :: getTitulacao(){
    return titulacao;
}

void Professor :: setCurso(string curso){
    this -> curso = curso;
}
string Professor :: getCurso(){
    return curso;
}

Professor* Professor :: obterProximo(){
    return this -> proximo;
}

void Professor :: setProximo(Professor* proximo){
    this -> proximo = proximo;
}


