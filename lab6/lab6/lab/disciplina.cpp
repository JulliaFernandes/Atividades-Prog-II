#include "disciplina.hpp"
#include <iostream>

using namespace std;

Disciplina :: Disciplina(string nomeD, int CH, Professor* prof){
    this -> nomeD = nomeD;
    this -> CH = CH;
    this -> prof = prof;
    this -> proximo = NULL;
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


// void Disciplina :: setDisciplina(){
//     this -> disciplina = disciplina;
// }
// Disciplina Disciplina :: getDisciplina(){
//     return Disciplina;
// }

Disciplina* Disciplina :: obterProximo(){
    return this -> proximo;
}
void Disciplina :: setProximo(Disciplina* proximo){
    this -> proximo = proximo;
}