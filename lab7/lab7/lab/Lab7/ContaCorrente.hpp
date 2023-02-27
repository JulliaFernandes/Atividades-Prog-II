#ifndef CONTACORRENTE_HPP
#define CONTACORRENTE_HPP
#include<iostream>
#include "Conta.hpp"

using namespace std;

class ContaCorrente : public Conta{
    private:
        double limite, limiteAux = 0;
        ContaCorrente* proximo;

    public:

        ContaCorrente();
        ContaCorrente(string _nome, int _numeroDaConta, double _limite, double _limiteAux);
        
        void setLimite(double _limite);
        double getLimite();

        void setLimiteAux(double _limiteAux);
        double getLimiteAux();

        void setProximo(ContaCorrente* _proximo);
        ContaCorrente* getProximo();

};
#endif