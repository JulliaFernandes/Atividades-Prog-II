#include "disciplina.hpp"
#include <iostream>

using namespace std;

Disciplina :: Disciplina(string nomeD, int CH, Professor* prof, long long int cpfP){
    this -> nomeD = nomeD;
    this -> CH = CH;
    this -> prof = prof;
    this -> cpfP = cpfP;
}
Disciplina :: Disciplina(){

}


void Disciplina :: setNomeD(){
    this -> nomeD = nomeD;
}
string Disciplina :: getNomeD(){
    return nomeD;
}


void Disciplina :: setCH(){
    this -> CH = CH;
}
int Disciplina :: getCH(){
    return CH;
}


Professor* Disciplina :: getProfessor(){
    return this -> prof;
}
void Disciplina :: setProfessor(Professor* prof){
    this -> prof = prof;
}


void Disciplina :: setCpfP(long long int cpf){
    this -> cpfP = cpfP;
}
long long int Disciplina :: getCpfP(){
    return this -> cpfP;
}