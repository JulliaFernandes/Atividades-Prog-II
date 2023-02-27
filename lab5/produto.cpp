#include "produto.hpp"

int NovoId=1;

Produto :: Produto(int  id, int qtd, string nome, float preco){
    this -> id = NovoId;
    this -> qtd= qtd;
    this -> nome = nome;
    this -> preco = preco;
    this -> proximo = NULL;
    NovoId++;
}

Produto :: Produto(){

}

Produto* Produto :: obterProximo(){
    return this -> proximo;
}

void Produto :: setProx(Produto * proximo){
    this -> proximo = proximo;
}

int Produto :: getId(){
    return this -> id;
}

void Produto :: setQtd(int quantidade){
    this -> qtd = qtd;
}
int Produto :: getQtd(){
    return qtd;
}

void Produto :: setNome(string nome){
    this -> nome = nome;
} 
string Produto :: getNome(){
    return nome;
}

void Produto :: setPreco(float preco){
    this -> preco = preco;
}
float Produto :: getpreco(){
    return preco;
}

void Produto :: unico(){
    cout << "O Produto é: " << nome << endl;
    cout << "O ID do produto é: " << id << endl;
}