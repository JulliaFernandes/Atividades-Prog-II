#ifndef _FILAPESSOA_HPP
#define _FILAPESSOA_HPP
#include <string>
#include <iostream>
#include "Pessoa.hpp"

using namespace std;

class FilaPessoa{
    private:
        Pessoa* primeiro;
        Pessoa* ultimo;
        int itens;

    public:
        FilaPessoa();
        FilaPessoa(string _nome, long long int _cpf);

        void setPrimeiro(Pessoa* primeiro);
        Pessoa* getPrimeiro();

        void setUltimo(Pessoa* ultimo);
        Pessoa* getUltimo(); 

        void setItens(int itens);
        int getItens();

        bool vazia();

        void CadastrarPessoas(Pessoa* novaP);
        void ImprimirPessoas();
        void Retirar();
};
#endif