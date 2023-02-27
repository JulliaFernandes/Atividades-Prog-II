#include "Pessoa.hpp"

using namespace std;

Pessoa :: Pessoa(string _nome, long long int _cpf){
    this -> nome = _nome;
    this -> cpf = _cpf;
    this -> setProximo(NULL);
}
Pessoa :: Pessoa (){
}

void Pessoa::setNome(string _nome){
    this-> nome = _nome;
}
string Pessoa::getNome(){
    return this-> nome;
}

void Pessoa :: setCPF(long long int _cpf){
    this -> cpf = _cpf;
}
long long int Pessoa :: getCPF(){
    return this -> cpf;
}

void Pessoa :: setProximo(Pessoa* proximo){
    this -> proximo = proximo;
}
Pessoa* Pessoa ::  getProximo(){
    return this -> proximo;

}