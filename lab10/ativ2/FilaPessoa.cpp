#include "FilaPessoa.hpp"

using namespace std;

FilaPessoa :: FilaPessoa(){
    this -> setPrimeiro(NULL);
    this -> setUltimo(NULL);
    this -> setItens(0);

}
FilaPessoa :: FilaPessoa(string _nome, long long int _cpf){
    primeiro = new Pessoa (_nome, _cpf);
    ultimo = primeiro;
    this -> setItens(0);
}

void FilaPessoa :: setPrimeiro(Pessoa* primeiro){
    this -> primeiro = primeiro;
}
Pessoa* FilaPessoa :: getPrimeiro(){
    return this -> primeiro;
}

void FilaPessoa :: setUltimo(Pessoa* ultimo){
    this -> ultimo = ultimo;
}
Pessoa* FilaPessoa :: getUltimo(){
    return this -> ultimo;
}

void FilaPessoa :: setItens(int itens){
    this -> itens = itens;
}
int FilaPessoa :: getItens(){
    return this -> itens;
}

bool FilaPessoa :: vazia(){
    return(primeiro == NULL); //retorna True pq ta vazia
}

void FilaPessoa :: CadastrarPessoas(Pessoa* novaP){

    if(this -> getItens() == 0){
        this -> setPrimeiro(novaP);
        this -> setUltimo(novaP);
        this -> setItens(1);
    }
    else{
        this-> getUltimo() -> setProximo(novaP);
        this -> setUltimo(novaP);
        this -> setItens(getItens()+1);    
    } 
}

/*void FilaPessoa :: CadastrarPessoas(){
    string nome;
    long long int cpf;
    int prioridade;

    cin.ignore();
    cout << "Digite seu nome:" << endl;
    getline(cin, nome);
    cout << "Digite seu CPF: " << endl;
    cin >> cpf;
    cout << "Voce possui prioridade?" << endl;
    cout << "[1]-Sim \n[2]-Não" << endl;  
    cin >> prioridade;

    if(prioridade == 1){
        Pessoa* novo = new Pessoa(nome, cpf);

        if(vazia()){
            this -> setPrimeiro(novo);
            this -> setUltimo(novo);
            cout << "Primerio" << endl;
        }
        else{
            novo -> setProximo(primeiro);
            this -> setPrimeiro(novo);
            cout << "Segundo" << endl;
        }
        
    }
    else{
        Pessoa* novaP = new Pessoa(nome, cpf);

            if(this -> getItens() == 0){
                this -> setPrimeiro(novaP);
                this -> setUltimo(novaP);
                this -> setItens(1);
            }
            else{
                this-> getUltimo() -> setProximo(novaP);
                this -> setUltimo(novaP);
                this -> setItens(getItens()+1);
                
            } 
    }
}*/

void FilaPessoa :: ImprimirPessoas(){
    Pessoa* p = getPrimeiro();
    int aux = 0;
           
        while(p){
            cout << "\n>Nome: " << p -> getNome() << endl;
            cout << ">CPF: " << p -> getCPF() << endl;

            aux = 1;
            p = p -> getProximo();
        }
        cout << "----------------------------------------------" << endl; 
}
void FilaPessoa :: Retirar(){
    Pessoa* p = this -> getPrimeiro();

        cout << "[DADOS DA PESSOA REMOVIDA]" << endl;
        cout << ">Nome: " << p -> getNome() << endl;
        cout << ">CPF: " << p -> getCPF() << endl;

        this -> setPrimeiro(p -> getProximo());
        this -> setItens(this -> getItens() -1);
        delete p;

}
