#ifndef _PESSOAJURIDICA_HPP
#define _PESSOAJURIDICA_HPP
#include <string>
#include <iostream>
#include "ListaPF.hpp"
#include "Pessoa.hpp"

using namespace std;

class PessoaJuridica : public Pessoa{

    private:

        long long int cnpj;
        PessoaJuridica* proximo;
        //PessoaFisica* PF;

    public:

        PessoaJuridica();
        PessoaJuridica(string _nome, string _endereco, long long int _cnpj, float _renda);

        void setProximo(PessoaJuridica* proximo);
        PessoaJuridica* getProximo();

        //void setPF(PessoaFisica* _PF);
        //PessoaFisica* getPF();

        void setCnpj(long long int _cnpj);
        long long int getCnpj();
        
        void ImpostoDeRenda();
        void imprimirpessoajuridica();

        //void setCpfPF(long long int _cpfPF);
        //long long int getCpfPF();

};
#endif