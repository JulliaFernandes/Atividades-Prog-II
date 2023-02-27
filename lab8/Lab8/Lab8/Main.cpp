#include<iostream>
#include<string>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Banco.hpp"
#include "SaqueSemLimite.hpp"

using namespace std;

int main(){
    int op=-1, error;
    double _valor = 0;
    Banco* banco = new Banco();
    
    while(op != 0){
        do{
            error = 0;
            cout << "\n\t BEM VINDO AO BANCO " << endl;
            cout << "\n[1] Criar Conta Corrente" << endl;
            cout << "[2] Criar Conta Corrente com Limite" << endl;
            cout << "[3] Criar Conta Poupança" << endl;
            cout << "[4] Deposito na Conta Corrente" << endl;
            cout << "[5] Deposito na Conta Corrente com Limite" << endl;
            cout << "[6] Deposito na Conta Poupança" << endl;
            cout << "[7] Fazer retirada na Conta Corrente" << endl;
            cout << "[8] Fazer retirada na Conta Corrente com Limite" << endl;
            cout << "[9] Fazer retirada na Conta Poupança" << endl;
            cout << "[10] Imprimir extrato da Conta Corrente" << endl;
            cout << "[11] Imprimir extrato da Conta Corrente com Limite" << endl;
            cout << "[12] Imprimir extrato da Conta Poupança" << endl;
            cout << "[0] Sair" << endl;
            cin >> op;

            if(cin.fail()){
                cout << "\nNUMERO INVALIDO, DIGITE NOVAMENTE" << endl;
                error = 1;
                cin.clear();
                cin.ignore(80, '\n');
            }
        }while(error == 1);

        switch(op){
            case 1:
                banco -> cadastroC();
                break;

            case 2:
                banco -> cadastroCC();
                break;

            case 3:
                banco -> cadastroCP();
                break;
            
            case 4:
                banco -> depositoC();
                break;

            case 5:
                banco -> depositoCC();
                break;
            
            case 6:
                banco -> depositoCP();
                break;
            
            case 7:
            try{
                banco -> retiradaC();
            }
            catch(SaqueSemLimite &ex){
                cout << "Exceção: "
                << ex.what() << endl;
            }
                break;

            case 8:
            try{
                banco -> retiradaCC();
            }
            catch(SaqueSemLimite &ex){
                cout << "Exceção: "
                << ex.what() << endl;
            }
                break;

            case 9:
            try{
                banco -> retiradaCP();
            }
            catch(SaqueSemLimite &ex){
                cout << "Exceção: "
                << ex.what() << endl;
            }
                break;

            case 10:
                banco -> extratoC();
                break;

            case 11:
                banco -> extratoCC();
                break;

            case 12:
                banco -> extratoCP();
                break;
            
            case 0:
                cout << "\nSaindo do programa" << endl;
                break;
                
        }
    }
}