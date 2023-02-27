#include <iostream>
#include <string>
#include "ListaPF.hpp"
#include "ListaPJ.hpp"

using namespace std;

int main (){

    ListaPessoaFisica* lpf = new ListaPessoaFisica();
    ListaPessoaJuridica* lpj = new ListaPessoaJuridica();

    int opcao = 0, error;

    while(opcao != 9){
        do{
            error = 0;
            cout << "\n[1] Cadastrar Pessoa Física" << endl;
            cout << "[2] Cadastrar Pessoa Jurídica" << endl;
            cout << "[3] Informações de uma Pessoa Fisica" << endl;
            cout << "[4] Informações de uma Pessoas Jurídica" << endl;
            cout << "[5] Excluir Pessoa Juridica" << endl;
            cout << "[6] Excluir Pessoa Fisica" << endl;
            cout << "[7] Imprimir lista de pessoas físicas cadastradas" << endl;
            cout << "[8] Imprimir lista de pessoas jurídicas cadastradas" << endl;
            cout << "[9] Sair do programa" << endl;
            cin >> opcao;
            
            if(cin.fail()){
                cout << "\nNUMERO INVALIDO, DIGITE NOVAMENTE" << endl;
                error = 1;
                cin.clear();
                cin.ignore(80, '\n');            
            }
        }while(error == 1);

        switch (opcao){
            case 1:
                lpf -> cadastrarpessoafisica();
                break;

            case 2:
                lpj -> cadastrarpessoajuridica();
                break;

            case 3:
                lpf -> imprimirUnico();
                break;

            case 4:
                lpj -> imprimirUnico();
                break;

            case 5:
                lpj -> excluirPJ();
                break;

            case 6:
                lpf -> excluirPF();
                break;

            case 7:
                lpf -> imprimirlistapf();
                break; 

            case 8:
                lpj -> imprimirlistapj();
                break;
            case 9:
                cout << "\nFinalizando o programa" << endl;
                break;

        } 
    }
    return 0;
}