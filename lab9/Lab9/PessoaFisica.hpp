#ifndef _PESSOAFISICA_HPP
#define _PESSOAFISICA_HPP
#include "Pessoa.hpp"
#include <string>
#include <iostream>

using namespace std;

class PessoaFisica : public Pessoa{
    private:
        long long int cpf;
        PessoaFisica* proximo;

    public:

        PessoaFisica();
        PessoaFisica(string _nome, string _endereco, long long int _cpf, float _renda);

        PessoaFisica* getProximo();
        void setProximo(PessoaFisica* proximo);

        void setCpf(long long int _cpf);
        long long int getCpf();
        
        void ImpostoDeRendaPF();
        void imprimirpessoafisica();

};
#endif