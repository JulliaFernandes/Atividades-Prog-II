#include <iostream>

#ifndef __TRIANGULO__HPP
#define __TRIANGULO__HPP

class Triangulo {
    private:
    float ladoA, ladoB, ladoC;
    static int CONT;

    public:

    Triangulo();
    Triangulo(float ladoA, float ladoB, float ladoC);

    void setLadoA(float ladoA);
    float getLadoA();

    void setLadoB(float ladoB);
    float getLadoB();

    void setLadoC(float ladoC);
    float getLadoC();

    void qualTriangulo(float ladoA, float ladoB, float ladoC);

    bool ehTriangulo(float ladoA, float ladoB, float ladoC);
    
    int getCONT();
};
#endif
