#ifndef _LISTAPESSOAFISICA_HPP
#define _LISTAPESSOAFISICA_HPP
#include <iostream>
#include <string>
#include "PessoaFisica.hpp"

using namespace std;

class ListaPessoaFisica{
    private:
        PessoaFisica* primeiro;
        PessoaFisica* ultimo; 
        int itens;

    public:
        ListaPessoaFisica(string _nome, string _endereco, long long int _cpf, float _renda);
        ListaPessoaFisica();
        
        virtual ~ListaPessoaFisica();
        //bool vazia();

        void setPrimeiro(PessoaFisica* primeiro);
        PessoaFisica* getPrimeiro();

        void setUltimo(PessoaFisica* ultimo);
        PessoaFisica* getUltimo(); 

        void setItens(int itens);
        int getItens();

       void cadastrarpessoafisica();
       void imprimirUnico();
       void imprimirlistapf();
       void excluirPF();
       
};
#endif