#include <iostream>
#include <math.h>
#include "triangulo.hpp"
using namespace std;

    int Triangulo :: CONT=0;

    Triangulo :: Triangulo(){
        setLadoA(1);
        setLadoB(1);
        setLadoC(1);
        CONT++;
    }
    Triangulo :: Triangulo(float ladoA, float ladoB, float ladoC){
        setLadoA(ladoA);
        setLadoB(ladoB);
        setLadoC(ladoC);
        CONT++;

    }

    
    void Triangulo :: setLadoA(float ladoA){
        this -> ladoA = ladoA;
    }
    float Triangulo ::getLadoA(){
        return ladoA;
    }

    void Triangulo :: setLadoB(float ladoB){
        this -> ladoB = ladoB;
    }
    float Triangulo :: getLadoB(){
        return ladoB;
    }

    void Triangulo :: setLadoC(float ladoC){
        this -> ladoC = ladoC;
    }
    float Triangulo :: getLadoC(){
        return ladoC;
    }


    void Triangulo :: qualTriangulo(float ladoA, float ladoB, float ladoC){
        if((ladoA == ladoB) && (ladoB== ladoC)){
            cout << "É um triangulo equilatero" << endl;
        }
        else if((ladoA == ladoB) || (ladoA == ladoC) || (ladoB ==ladoC)){
            cout <<"É um triangulo isosceles" << endl;
        }
        else{
            cout << "É um triangulo escaleno" << endl; 
        }
    }

    bool Triangulo :: ehTriangulo(float ladoA, float ladoB, float ladoC){
        int controle=0;

        if((abs(ladoB-ladoC)<ladoA) && (ladoA<(ladoB+ladoC))){
            controle=1;
        }
        else if((abs(ladoA-ladoC)<ladoB) && (ladoB<(ladoA+ladoC))){
            controle=1;
        }
        else if((abs(ladoA-ladoB)<ladoC) && (ladoC<(ladoA+ladoB))){
            controle=1;
        }

        if(controle==1){
            return true;
        }
        else{
            return false;
        }
    }
    int Triangulo :: getCONT(){
        return this -> CONT;
    }