#ifndef LISTACONTACORRENTE_HPP
#define LISTACONTACORRENTE_HPP
#include<iostream>
#include "ContaCorrente.hpp"

using namespace std;

class ListaContaCorrente{
    private:
        ContaCorrente* primeiro;
        ContaCorrente* ultimo;
        int itens;

    public:
        ListaContaCorrente();
        ListaContaCorrente(string _nome, int _numeroDaConta, double _limite, double _limiteAux);

        void setPrimeiro(ContaCorrente* _primeiro);
        ContaCorrente* getPrimeiro();

        void setUltimo(ContaCorrente* _ultimo);
        ContaCorrente* getUltimo();

        void setItens(int _itens);
        int getItens();

        virtual ~ListaContaCorrente();
        bool vazia();

        void inserirFinal(ContaCorrente* conta);

        
};
#endif