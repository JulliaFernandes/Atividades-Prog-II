#ifndef BANCO_HPP_
#define BANCO_HPP_
#include <iostream>
#include <string>
#include "ListaContaSemLimite.hpp"
#include "ListaContaCorrente.hpp"
#include "ListaContaPoupanca.hpp"
#include "ListaContaSemLimite.hpp"
#include "SaqueSemLimite.hpp"

class Banco{
    private:
        ListaContaSemLimite* lc;
        ListaContaCorrente* lcc;
        ListaContaPoupanca* lcp;

    public:
        Banco();
        Banco(ListaContaSemLimite* _lc, ListaContaCorrente* _lcc, ListaContaPoupanca* _lcp);

        void setListaContaSemLimite(ListaContaSemLimite* _lc);
        ListaContaSemLimite* getListaContaSemLimite();

        void setListaContaCorrente(ListaContaCorrente* _lcc);
        ListaContaCorrente* getListaContaCorrente();

        void setListaContaPoupanca(ListaContaPoupanca* _lcp);
        ListaContaPoupanca* getListaContaPoupanca();

        void cadastroC();
        void cadastroCC();
        void cadastroCP();

        void extratoC();
        void extratoCC();
        void extratoCP();

        void depositoC();
        void depositoCC();
        void depositoCP();

        void retiradaC();
        void retiradaCC();
        void retiradaCP();

        void imprimirNumConta();

};
#endif