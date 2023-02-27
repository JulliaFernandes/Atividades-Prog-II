#ifndef LISTACONTAPOUPANCA_HPP
#define LISTACONTAPOUPANCA_HPP
#include<iostream>
#include <string>
#include "ContaPoupanca.hpp"

using namespace std;

class ListaContaPoupanca{
    private:
        ContaPoupanca* primeiro;
        ContaPoupanca* ultimo;
        int itens;

    public:
        ListaContaPoupanca();
        ListaContaPoupanca(string _nome, int _numeroDaConta, string _aniversario);

        void setPrimeiro(ContaPoupanca* _primeiro);
        ContaPoupanca* getPrimeiro();

        void setUltimo(ContaPoupanca* _ultimo);
        ContaPoupanca* getUltimo();

        void setItens(int _itens);
        int getItens();

        virtual ~ListaContaPoupanca();
        bool vazia();

        void inserirFinal(ContaPoupanca* conta);

       
};
#endif