#include <iostream>
#include "triangulo.hpp"
using namespace std;

int main(){
    float a, b, c;
    bool resultado;

    cout << "Digite o lado A:";
    cin >> a;

    cout << "Digite o lado B:";
    cin >> b;

    cout << "Digite o lado C:";
    cin >>c;

    Triangulo Tri(a,b,c);
    resultado = Tri.ehTriangulo(a,b,c);
    if(resultado){
        Tri.qualTriangulo(a,b,c);
    }
    else{
        cout << "Não é um triangulo" << endl;
    }

    cout << "CONT = " << Tri.getCONT() << endl;

    Triangulo Tri2(a,b,c);
    cout << "Digite o lado A:";
    cin >> a;

    cout << "Digite o lado B:";
    cin >> b;

    cout << "Digite o lado C:";
    cin >>c;

    resultado = Tri2.ehTriangulo(a,b,c);
    if(resultado){
        Tri2.qualTriangulo(a,b,c);
    }
    else{
        cout << "Não é um triangulo" << endl;
    }

    cout << "CONT = " << Tri2.getCONT() << endl;

return 0;
}