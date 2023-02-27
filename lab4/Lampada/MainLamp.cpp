#include <iostream>
#include <string>
#include "lampada.hpp"
using namespace std;

int main(){
    string nome;
    float t;

    cout << "Digite o modelo da lampada:" << endl;
    cin >> nome;

    cout << "Digite a tensao da lampada:" << endl;
    cin >> t;
    
    lampada L(nome, t);
    L.estadoAtual();
    L.acender();
    L.estadoAtual();
    L.apagar();
    L.estadoAtual();
    cout << "CONT = " << L.getCONT() << endl;


    cout << "Digite o modelo da lampada:" << endl;
    cin >> nome;

    cout << "Digite a tensao da lampada:" << endl;
    cin >> t;

    lampada L2(nome, t);
    L2.estadoAtual();
    L2.acender();
    L2.estadoAtual();
    L2.apagar();
    L2.estadoAtual();

    cout << "CONT = " << L2.getCONT() << endl;
    return 0;

}
