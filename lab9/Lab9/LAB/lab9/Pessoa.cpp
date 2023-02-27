#include "Pessoa.hpp"

using namespace std;

Pessoa :: Pessoa(string _nome, string _endereco, float _renda){
    this -> nome = _nome;
    this -> endereco = _endereco;
    this -> renda = _renda;
    this -> imposto = -1;

}
Pessoa :: Pessoa (){
}

void Pessoa::setNome(string _nome){
    this-> nome = _nome;
}
string Pessoa::getNome(){
    return this-> nome;
}

void Pessoa::setEndereco(string _endereco){
    this-> endereco = _endereco;
}
string Pessoa::getEndereco(){
    return this -> endereco;
}

void Pessoa :: setRenda(float _renda){
    this -> renda = _renda;
}
float Pessoa :: getRenda(){
    return this -> renda;
}

void Pessoa :: setImposto(float _imposto){
    this -> imposto = _imposto;
}
float Pessoa :: getImposto(){
    return this -> imposto;
}
