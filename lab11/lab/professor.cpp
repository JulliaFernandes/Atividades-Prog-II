#include "professor.hpp"
#include <iostream>

using namespace std;


Professor :: Professor(string nome, string endereco, string titulacao, string curso, long long int _cpf) : Pessoa(nome, endereco){
    this -> titulacao = titulacao;
    this -> curso = curso; 
    this -> cpf = _cpf;
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

void Professor :: setCpf(long long int _cpf){
    this -> cpf = _cpf;
}
long long int Professor :: getCpf(){
    return this -> cpf;
}


