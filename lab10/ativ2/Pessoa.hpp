#ifndef _PESSOA_HPP
#define _PESSOA_HPP
#include <string>
#include <iostream>

using namespace std;

class Pessoa{
    private:
        string nome;
        long long int cpf;
        //int idade;
        Pessoa* proximo;

    public:
        Pessoa();
        Pessoa(string _nome, long long int _cpf);

        void setNome(string _nome);
        string getNome();

        void setCPF(long long int _cpf);
        long long int getCPF();

        //void setIdade(int _idade);
        //int getIdade();

        void setPosicao(int _posicao);
        int getPosicao();

        Pessoa* getProximo();
        void setProximo(Pessoa* proximo);

        bool vazia();

        

};
#endif