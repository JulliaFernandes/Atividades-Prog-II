#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "pessoa.hpp"
#include <iostream>
#include <string>

using namespace std;

class Professor : public Pessoa{
    private:
        string titulacao;
        string curso;
        Professor* proximo;

    public:
        Professor(string nome, string endereco, string titulacao, string curso);
        Professor ();
        void setTitulacao(string titulacao);
        string getTitulacao();
        void setCurso(string curso);
        string getCurso();
        

        Professor* obterProximo();
        void setProximo(Professor* proximo);
};

#endif