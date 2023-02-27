#include "Livro.hpp" 

using namespace std;

Livro :: Livro(string _nome, float _isbn){
    this -> nome = _nome;
    this -> isbn = _isbn;
    this -> setProximo(NULL);
}
Livro :: Livro(){

}

void Livro :: setNome(string _nome){
    this -> nome = _nome;
}
string Livro :: getNome(){
    return this -> nome;
}

void Livro :: setISBN(float _isbn){
    this -> isbn = _isbn;
}
float Livro :: getISBN(){
    return this -> isbn;
}

void Livro :: setProximo(Livro* proximo){
    this -> proximo = proximo;
}
Livro* Livro :: getProximo(){
    return this -> proximo;
}