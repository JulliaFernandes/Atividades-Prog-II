#include "ListaPF.hpp"
#include <iostream>
#include <string>

using namespace std;

ListaPessoaFisica::ListaPessoaFisica(){
    this -> setPrimeiro(NULL);
    this -> setUltimo(NULL);
    this -> setItens(0);
}

ListaPessoaFisica :: ListaPessoaFisica(string _nome, string _endereco, long long int _cpf, float _renda){
    primeiro = new PessoaFisica (_nome, _endereco, _cpf, _renda);
    ultimo = primeiro;
    this -> setItens(0);
}

ListaPessoaFisica :: ~ListaPessoaFisica(){
    delete primeiro;
}

void ListaPessoaFisica :: setPrimeiro(PessoaFisica* primeiro){
    this -> primeiro = primeiro;
}
PessoaFisica* ListaPessoaFisica :: getPrimeiro(){
    return this -> primeiro;
}

void ListaPessoaFisica :: setUltimo(PessoaFisica* ultimo){
    this -> ultimo = ultimo;
}

PessoaFisica* ListaPessoaFisica :: getUltimo(){
    return this -> ultimo;
}

void ListaPessoaFisica :: setItens(int itens){
    this -> itens = itens;
}

int ListaPessoaFisica :: getItens(){
    return this -> itens;
}

void ListaPessoaFisica:: cadastrarpessoafisica(){

	long long int cpf;
	string nome, endereco;
    float renda;
    int aux = 0, error, error2;
    PessoaFisica* pf = this -> getPrimeiro();

    cin.ignore();
	cout << "\nDigite o nome da Pessoa Física: \n";
	getline(cin, nome);
    cout << "Digite o endereço da Pessoa Física: \n";
	getline(cin, endereco);
    do{
        error = 0;
        cout << "Digite o cpf: \n";
        cin >> cpf;
        if(cin.fail()){
            cout << "\nDIGITE SOMENTE NUMEROS" << endl;
            error = 1;
            cin.clear();
            cin.ignore(80, '\n');
        }
        while(pf){
            if(cpf == pf -> getCpf()){
                cout << "CPF ja cadastrado" << endl;
                aux = 1;
            }
            pf = pf -> getProximo();
        }
    }while(error == 1);

    if(aux == 0){
        do{
            error2 = 0;
            cout << "Digite sua renda no formato 0000.00: " << endl;
            cin >> renda;
            if(cin.fail()){
                cout << "\nDIGITE SOMENTE NUMEROS" << endl;
                error2 = 1;
                cin.clear();
                cin.ignore(80, '\n');
            }
        }while(error2 == 1);

        PessoaFisica* novapf = new PessoaFisica(nome, endereco, cpf, renda);
        novapf -> ImpostoDeRendaPF();

        if(this -> getItens() == 0){
            this -> setPrimeiro(novapf);
            this -> setUltimo(novapf);
            this -> setItens(1);
        }
        
        else{
            this-> getUltimo() -> setProximo(novapf);
            this -> setUltimo(novapf);
            this -> setItens(getItens()+1);
            
        }
    }
}

void ListaPessoaFisica :: imprimirUnico(){
    PessoaFisica* pf = this -> getPrimeiro();
    long long int cpfAux;
    int aux = 0, aux2= 0, error;

    if(this -> getItens() == 0){
        cout << "Nenhuma Pessoa Fisica cadastrada ate o momento" << endl;
        aux = 1;
    }
    if(aux == 0){
        do{
            error = 0;
            cout << "Digite o CPF que deseja consultar:" << endl;
            cin >> cpfAux;
            if(cin.fail()){
                cout << "\nDIGITE SOMENTE NUMEROS" << endl;
                error = 1;
                cin.clear();
                cin.ignore(80, '\n');
            }

        }while(error == 1);

        while(pf){
            if(cpfAux == pf -> getCpf()){
                pf -> imprimirpessoafisica();
                aux2 = 1; 
            }
            pf = pf -> getProximo();
        }
    }
    if(aux2 == 0){
        cout << "Este numero de CPF não esta cadastrado ate o momento" << endl;
    }
    
}

void ListaPessoaFisica :: excluirPF(){

    PessoaFisica* atual = this -> getPrimeiro();
    PessoaFisica* anterior = NULL;
    long long int cpf = 0;
    int aux = 0, aux2= 0, error;

    if(this -> getItens() == 0){
        cout << "Nenhuma Pessoa Fisica cadastrada ate o momento" << endl;
        aux = 1;
    }
    if(aux == 0){
        do{
            error = 0;
            cout << "Digite o CPF que deseja remover: " << endl;
            cin >> cpf;
            if(cin.fail()){
                cout << "\nDIGITE SOMENTE NUMEROS" << endl;
                error = 1;
                cin.clear();
                cin.ignore(80, '\n');
            }
        }while(error == 1);

        if(cpf == atual -> getCpf()){
            this -> setPrimeiro(atual -> getProximo());
            this -> setItens(getItens() - 1);
            delete atual;
            cout << "PESSOA FISICA REMOVIDA" <<  endl;
        } 
        else{
            while( (atual != NULL) && (atual -> getCpf() != cpf)){
                anterior = atual;
                atual = atual -> getProximo();
            }
            if(atual == NULL){
                cout << "Este numero de CPF nao esta cadastrado" << endl;
            }
            else{
                if( (this -> getPrimeiro() -> getProximo() -> getProximo() == NULL) && (this -> getUltimo() -> getCpf() == cpf)){
                    this -> getPrimeiro() -> setProximo(NULL);
                    this -> setUltimo(this -> getPrimeiro());
                    this -> setItens(this -> getItens() -1);

                    cout << "\nPESSOA JURIDICA EXCLUIDA." << endl;
                }
                else if( (atual == this -> getUltimo()) && (atual -> getCpf() == cpf)){
                    anterior -> setProximo(NULL);
                    this -> setUltimo(anterior);
                    delete atual;
                    this -> setItens(this -> getItens() -1);

                    cout << "\nPESSOA JURIDICA EXCLUIDA." << endl;
                }
                else{
                    anterior -> setProximo(atual -> getProximo());
                    delete atual;
                    this -> setItens(this -> getItens() -1);
                    cout << "\nPESSOA JURIDICA EXCLUIDA." << endl;
                }
            }
        }
    }
}

void ListaPessoaFisica :: imprimirlistapf(){
    int aux = 0;
    PessoaFisica* atual = this -> getPrimeiro();

    for (int i=0; i < this -> getItens(); i++){
        atual -> imprimirpessoafisica();
        atual = atual -> getProximo();
        aux = 1;
    }
    if(aux == 0){
        cout << "[LISTA DE PESSOAS FISICAS VAZIA]" << endl;
    }
}
