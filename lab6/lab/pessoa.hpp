#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include <string>

using namespace std;

class Pessoa{
    protected:
        string nome;
        string endereco;

    public:
        Pessoa(string nome, string endereco);
        Pessoa();
        void setNome();
        string getNome();
        void setEndereco();
        string getEndereco();
};

#endif
