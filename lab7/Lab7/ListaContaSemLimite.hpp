#ifndef CONTAPOUPANCA_HPP
#define CONTAPOUPANCA_HPP
#include<iostream>
#include "ContaSemLimite.hpp"

using namespace std;

class ListaContaSemLimite{
    private:
        ContaSemLimite* primeiro;
        ContaSemLimite* ultimo;
        int itens;
    public:
        ListaContaSemLimite();
        ListaContaSemLimite(string _nome, int _numeroDaConta);

        void setPrimeiro(ContaSemLimite* _primeiro);
        ContaSemLimite* getPrimeiro();

        void setUltimo(ContaSemLimite* _ultimo);
        ContaSemLimite* getUltimo();

        void setItens(int _itens);
        int getItens();

        virtual ~ListaContaSemLimite();
        bool vazia();

        void inserirFinal(ContaSemLimite* contaa);
        
};

#endif