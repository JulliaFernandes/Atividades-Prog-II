#include "ListaPJ.hpp"
#include "ListaPF.hpp"
#include <iostream>
#include <string>

using namespace std;

ListaPessoaJuridica::ListaPessoaJuridica(){
    primeiro = NULL;
    ultimo = NULL;
    this-> setItens(0);
}

ListaPessoaJuridica :: ListaPessoaJuridica( string _nome, string _endereco, long long int _cnpj, float _renda){
    primeiro = new PessoaJuridica (_nome, _endereco, _cnpj, _renda);
    ultimo = primeiro;
    this -> setItens(0);
}

ListaPessoaJuridica :: ~ListaPessoaJuridica(){
    delete primeiro;
}


void ListaPessoaJuridica :: setPrimeiro(PessoaJuridica* primeiro){
    this -> primeiro = primeiro;
}
PessoaJuridica* ListaPessoaJuridica :: getPrimeiro(){
    return this -> primeiro;
}

void ListaPessoaJuridica :: setUltimo(PessoaJuridica* ultimo){
    this -> ultimo = ultimo;
}

PessoaJuridica* ListaPessoaJuridica :: getUltimo(){
    return this -> ultimo;
}

void ListaPessoaJuridica :: setItens(int itens){
    this -> itens = itens;
}

int ListaPessoaJuridica :: getItens(){
    return this -> itens;
}


void ListaPessoaJuridica :: cadastrarpessoajuridica(){
    float imposto = 0;
	long long int cnpj;
	string nome, endereco;
    float renda;
    int aux = 0, error, error2;
    PessoaJuridica* pj = this -> getPrimeiro();

    cin.ignore();
	cout << "\nDigite o nome da Pessoa Jurídica: \n";
	getline(cin, nome);
	cout << "Digite o endereço da Pessoa Jurídica: \n";
	getline(cin, endereco);

    do{
        error = 0;
        cout << "Digite o CNPJ: \n";
        cin >> cnpj;
        if(cin.fail()){
            cout << "\nDIGITE SOMENTE NUMEROS" << endl;
            error = 1;
            cin.clear();
            cin.ignore(80, '\n');
        }
        while(pj){
        if(cnpj ==  pj -> getCnpj()){
            cout << "CNPJ ja cadastrado" << endl;
            aux = 1;
        }
        pj = pj -> getProximo();
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

        PessoaJuridica* novapj = new PessoaJuridica(nome, endereco, cnpj, renda);
        novapj -> ImpostoDeRenda();

        if(this -> getItens() == 0){
            this -> setPrimeiro(novapj);
            this -> setUltimo(novapj);
            this -> setItens(1);
        }
        
        else{
            this-> getUltimo() -> setProximo(novapj);
            this -> setUltimo(novapj);
            this -> setItens(getItens()+1);
            
        }
    }
}

void ListaPessoaJuridica :: imprimirUnico(){
    PessoaJuridica* pj = this -> getPrimeiro();
    long long int cnpjAux;
    int aux = 0, aux2 = 0, error;

    if(this -> getItens() == 0){
        cout << "Nenhuma Pessoa Juridica cadastrada ate o momento" << endl;
        aux = 1;
    }
    if(aux == 0){
        do{
            error = 0;
            cout << "Digite o CNPJ que deseja consultar:" << endl;
            cin >> cnpjAux;
            if(cin.fail()){
                cout << "\nDIGITE SOMENTE NUMEROS" << endl;
                error = 1;
                cin.clear();
                cin.ignore(80, '\n');
            }
        }while(error == 1);

        while(pj){
            if(cnpjAux == pj -> getCnpj()){
                pj -> imprimirpessoajuridica(); 
                aux2 = 1;
            }
            pj = pj -> getProximo();
        }
    }
    if(aux2 == 0){
        cout << "Este numero de CNPJ não esta cadastrado ate o momento" << endl;
    }
}


void ListaPessoaJuridica :: imprimirlistapj(){

    PessoaJuridica* atual = this -> getPrimeiro();
    int i, aux = 0;
    
    for( i =0; i < this -> getItens(); i++){
        atual -> imprimirpessoajuridica();
        atual = atual -> getProximo();
        aux = 1;
    }
    if(aux == 0){
        cout << "[LISTA DE PESSOAS JURIDICAS VAZIA]" << endl;
    }
}

void ListaPessoaJuridica :: excluirPJ(){

    PessoaJuridica* atual = this -> getPrimeiro();
    PessoaJuridica* anterior = NULL;
    long long int cnpj = 0;
    int aux = 0, error;

    if(this -> getItens() == 0){
        cout << "Nenhuma Pessoa Juridica cadastrada ate o momento" << endl;
        aux = 1;
    }
    if(aux == 0){
        do{
            error = 0;
            cout << "Digite o CNPJ que deseja remover: " << endl;
            cin >> cnpj;
            if(cin.fail()){
                cout << "\nDIGITE SOMENTE NUMEROS" << endl;
                error = 1;
                cin.clear();
                cin.ignore(80, '\n');
            }
        }while(error == 1);

        if(cnpj == atual -> getCnpj()){
            this -> setPrimeiro(atual -> getProximo());
            this -> setItens(getItens() - 1);
            delete atual;
            cout << "CNPJ REMOVIDO" <<  endl;
        } 
        else{
            while( (atual != NULL) && (atual -> getCnpj() != cnpj)){
                anterior = atual;
                atual = atual -> getProximo();
            }
            if(atual == NULL){
                cout << "Este numeor de CNPJ nao esta cadastrado" << endl;
            }
            else{
                if( (this -> getPrimeiro() -> getProximo() -> getProximo() == NULL) && (this -> getUltimo() -> getCnpj() == cnpj)){
                    this -> getPrimeiro() -> setProximo(NULL);
                    this -> setUltimo(this -> getPrimeiro());
                    this -> setItens(this -> getItens() -1);

                    cout << "\nPESSOA JURIDICA EXCLUIDA." << endl;
                }
                else if( (atual == this -> getUltimo()) && (atual -> getCnpj() == cnpj)){
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