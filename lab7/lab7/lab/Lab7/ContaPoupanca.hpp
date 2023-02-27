#ifndef CONTAPOUPANCA_HPP_
#define CONTAPOUPANCA_HPP_
#include<iostream>
#include "Conta.hpp"

using namespace std;

class ContaPoupanca : public Conta{
    private:
        string aniversario;
        ContaPoupanca* proximo;

    public:
        ContaPoupanca();
        ContaPoupanca(string _nome, int _numeroDaConta, string _aniversario);

        void setAniversario(string _aniversario);
        string getAniversario();

        void setProximo(ContaPoupanca* _proximo);
        ContaPoupanca* getProximo();
};

#endif