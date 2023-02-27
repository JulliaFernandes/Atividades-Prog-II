#include <iostream>
#include <string>
#include "taxi.hpp"
using namespace std;


//MODELO
void corrida :: setModelo(string modeloCarro){
    this->modeloCarro = modeloCarro;
}
string corrida :: getModelo(){
    return modeloCarro;
}

//MOTORIZAÇAO
void corrida :: setMotorizaçao(float motorizaçao){
    this->motorizaçao = motorizaçao;
}
float corrida :: getMotorizaçao(){
    return motorizaçao;
}

void corrida :: setFabricante(string fabricanteCarro){
    this->fabricanteCarro = fabricanteCarro;
}
string corrida :: getFabricante(){
    return fabricanteCarro;
}

//NOME
void corrida :: setNome(string nome){
    this->nome = nome;
}
string corrida :: getNome(){
    return nome;
}

//QUILOMETRAGEM INICIAL
void corrida :: setQuilometragemInicial(float kmInicial){
    this->kmInicial = kmInicial;
}
float corrida:: getQuilometragemInicial(){
    return kmInicial;
}

//QUILOMETRAGEM FINAL
void corrida :: setQuilometragemFinal(float kmFinal){
    this->kmFinal = kmFinal;
}
float corrida :: getQuilometragemFinal(){
    return kmFinal;
}

void corrida :: imprimir(){
    cout << "----------------------------------------" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Modelo carro: " << modeloCarro << endl;
    cout << "Fabricante do carro: " << fabricanteCarro << endl;
    cout << "Motorizaçao: " << motorizaçao << endl;
    cout << "Quilometragem Inicial: " << kmInicial << endl;
    cout << "Quilometragem Final: " << kmFinal << endl;
}
