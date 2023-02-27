#include <iostream>
#include "taxi.hpp"

int main(){

    corrida taxi;
    string modeloCarro;
    float motorizaçao, kmInicial, kmFinal;
    string fabricanteCarro;
    string nome;
    float valorTotal=0;

    cout << "Digite o nome do motorista: " << endl;
    getline(cin, nome);
    taxi.setNome(nome);

    cout << "Digite o modelo do carro: " << endl; 
    getline(cin, modeloCarro);
    taxi.setModelo(modeloCarro);

    cout << "Digite o fabricante do veiculo: " << endl;
    getline(cin, fabricanteCarro);
    taxi.setFabricante(fabricanteCarro);

    cout << "Digite a motorizaçao do carro: " << endl;
    cin >> motorizaçao;
    taxi.setMotorizaçao(motorizaçao);

    cout << "Digite a Quilometragem Inicial: " << endl;
    cin >> kmInicial;
    taxi.setQuilometragemInicial(kmInicial);

    cout << "Digite a Quilometragem Final: " << endl;
    cin >> kmFinal; 
    taxi.setQuilometragemFinal(kmFinal);

    taxi.imprimir();

    valorTotal=(taxi.getQuilometragemFinal()- taxi.getQuilometragemInicial());
    valorTotal = valorTotal*3.75;
    cout << "O valor total da corrida é: " << valorTotal << endl;

}