#ifndef CONTASEMLIMITE_HPP
#define CONTASEMLIMITE_HPP
#include<iostream>
#include "Conta.hpp"

class ContaSemLimite : public Conta{
    private:
        ContaSemLimite* proximo;

    public:
        ContaSemLimite();
        ContaSemLimite(string _nome, int _numeroDaConta);

        void setProximo(ContaSemLimite* _proximo);
        ContaSemLimite* getProximo();
};

#endif