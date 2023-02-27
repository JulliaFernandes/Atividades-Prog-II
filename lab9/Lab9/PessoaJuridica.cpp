#include "PessoaJuridica.hpp"
#include "Pessoa.hpp"
#include <iostream>

using namespace std;

PessoaJuridica :: PessoaJuridica (string _nome, string _endereco, long long int _cnpj, float _renda) : Pessoa(_nome, _endereco, _renda) {
    this -> cnpj = _cnpj;
    this -> proximo = NULL;
}

PessoaJuridica :: PessoaJuridica(){

}

void PessoaJuridica :: setProximo(PessoaJuridica* proximo){
    this -> proximo = proximo;
}
PessoaJuridica* PessoaJuridica ::  getProximo(){
    return this -> proximo;

}

/*void PessoaJuridica :: setCpfPF(long long int _cpfPF){
    this -> cpfPF = _cpfPF;
}
long long int PessoaJuridica ::  getCpfPF(){
    return this -> cpfPF;

}*/

void PessoaJuridica :: setCnpj(long long int _cnpj){
    this -> cnpj = _cnpj;
}
long long int PessoaJuridica ::  getCnpj(){
    return this -> cnpj;

}

void PessoaJuridica :: ImpostoDeRenda(){
   float renda = getRenda();
   float imposto;

   imposto = renda*(10.0/100.0);
   setImposto(imposto);
   //cout << "Seu imposto de renda: " << imposto << endl;
}


void PessoaJuridica :: imprimirpessoajuridica(){
    
    cout << "\n>Nome: " << this -> getNome() << endl;
    cout << ">Endereço: " << this -> getEndereco() << endl;
    cout << ">Cnpj: " << this -> getCnpj() << endl;
	cout << ">Imposto de Renda: " << this -> getImposto() << endl;

}