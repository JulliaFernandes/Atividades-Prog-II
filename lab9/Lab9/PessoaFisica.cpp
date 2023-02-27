#include "PessoaFisica.hpp"
#include <iostream>

using namespace std;

PessoaFisica :: PessoaFisica (string _nome, string _endereco, long long int _cpf, float _renda) : Pessoa(_nome, _endereco, _renda){
    this -> cpf = _cpf;
    this -> proximo = NULL;
}

PessoaFisica :: PessoaFisica(){

}

void PessoaFisica :: setCpf(long long int _cpf){
    this -> cpf = _cpf;
}
long long int PessoaFisica:: getCpf(){
    return this -> cpf;
}


void PessoaFisica :: setProximo(PessoaFisica* proximo){
    this -> proximo = proximo;
}
PessoaFisica* PessoaFisica ::  getProximo(){
    return this -> proximo;

}

void PessoaFisica :: ImpostoDeRendaPF(){
    float renda = getRenda();
    float imposto;

    if(renda <= 1903.98){
        cout << "Isento de aliquota" << endl;
        imposto = 0;
        setImposto(imposto);
    }
    else if((renda > 1903.98) && (renda <= 2826.65) ){
        imposto = (renda*0.075) - 142.80;
        setImposto(imposto);
    }
    else if((renda > 2826.65) && (renda <= 3751.06)){
        imposto = (renda*0.15) - 354.80;
        setImposto(imposto);
    }
    else if((renda > 3751.06) && (renda <= 4664.68)){
        imposto = (renda*0.225) - 636.13;
        setImposto(imposto);
    }
    else if(renda > 4664.68){
        imposto = (renda*0.275) - 869.36;
        setImposto(imposto);
    }

    //cout << "Seu imposto de renda é: " << imposto << endl;
}

void PessoaFisica :: imprimirpessoafisica(){
    
    cout << "\n>Nome: " << this -> getNome()  << endl;
    cout << ">Endereço: " << this -> getEndereco() << endl;
    cout << ">Cpf: " << this -> getCpf() << endl;
    cout << ">Seu imposto de renda: " << this -> getImposto() << endl;
    
}
