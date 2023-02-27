#ifndef CONTA_HPP_
#define CONTA_HPP_

#include <iostream>
#include <string>

using namespace std;

class Conta{
    private:
        string nome;
        int numeroDaConta;
        double saldo;
        string transacao;

    public:
        Conta();
        Conta(string _nome, int _numeroDaConta);


        void setNome(string _nome);
        string getNome();

        void setNumeroDaConta(int _numeroDaConta);
        int getNumeroDaConta();

        void setSaldo(double _saldo);
        double getSaldo();
        
        void setTransacao(string _transacao);
        string getTransacao();

        //void deposito(double _valor);
        //void retirada(double _retirada);
};

#endif
