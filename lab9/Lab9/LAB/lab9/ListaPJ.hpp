#ifndef _LISTAPESSOAJURIDICA_HPP
#define _LISTAPESSOAJURIDICA_HPP
#include <iostream>
#include "PessoaJuridica.hpp"
#include "PessoaFisica.hpp"
#include "ListaPF.hpp"

using namespace std;

class ListaPessoaJuridica{

    private:
        PessoaJuridica* primeiro;
        PessoaJuridica* ultimo; 
        int itens;

    public:

        ListaPessoaJuridica(string _nome, string _endereco, long long int _cnpj, float _renda);
        ListaPessoaJuridica();
        
        virtual ~ListaPessoaJuridica();

        void setPrimeiro(PessoaJuridica* primeiro);
        PessoaJuridica* getPrimeiro();

        void setUltimo(PessoaJuridica* ultimo);
        PessoaJuridica* getUltimo(); 

        void setItens(int itens);
        int getItens(); 

        void cadastrarpessoajuridica();
        void imprimirUnico();
        void imprimirlistapj();
        void excluirPJ();
        
        //void imprimirassociacao(ListaPessoaFisica* _pf);
        //void associacaoentrepessoas(ListaPessoaFisica* pf, ListaPessoaJuridica* _pj);
       //void cadastrarpessoafisic(string nome, string endereco);
};
#endif