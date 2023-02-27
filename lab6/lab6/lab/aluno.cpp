#include "aluno.hpp"
#include "pessoa.hpp"
#include <iostream>

using namespace std; 

int matricula1 = 2022300;

Aluno :: Aluno(){

}

Aluno :: Aluno(string nome, string endereco) : Pessoa (nome , endereco){
    this -> matricula = matricula1;
    this -> proximo = NULL;
    matricula1++;
}

int Aluno :: getMatricula(){
    return matricula;
}

Aluno* Aluno :: obterProximo(){
    return this -> proximo;
}

void Aluno :: setProximo(Aluno* proximo){
    this -> proximo = proximo;
}