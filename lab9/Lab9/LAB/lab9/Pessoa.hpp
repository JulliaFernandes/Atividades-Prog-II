#ifndef _PESSOA_HPP
#define _PESSOA_HPP
#include <string>
#include <iostream>

using namespace std;

class Pessoa{
    private:
        string nome;
        string endereco;
        float renda, imposto;

    public:
        Pessoa();
        Pessoa(string _nome, string _endereco, float _renda);

        void setNome(string _nome);
        string getNome();

        void setEndereco(string _endereco);
        string getEndereco();

        void setRenda(float _renda);
        float getRenda();

        void setImposto(float _imposto);
        float getImposto();

};
#endif