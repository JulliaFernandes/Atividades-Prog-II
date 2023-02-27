#include <iostream>
#include "lampada.hpp"
using namespace std;

int lampada::CONT=0;

lampada ::lampada(string modelo, float tensao){
    setModelo(modelo);
    setTensao(tensao);
    setEstado(false);
    CONT++; 
}
void lampada :: setModelo(string modelo){
    this ->modelo=modelo;
}
string lampada :: getModelo(){
    return modelo;
}

void lampada :: setTensao(float tensao){
    this ->tensao=tensao;
}
float lampada :: getTensao(){
    return tensao;
}

void lampada :: setEstado(bool estado){
    this->estado=estado;
}
bool lampada :: getEstado(){
    return estado;
}

void lampada :: acender(){
    setEstado(true);
}

void lampada :: apagar(){
    setEstado(false);
}

void lampada :: estadoAtual(){
    if(getEstado()){
        cout << "A lampada esta acesa" << endl;
    }
    else{
        cout << "A lampada esta apagada" << endl;
    }
}

int lampada :: getCONT(){
    return this -> CONT;
}