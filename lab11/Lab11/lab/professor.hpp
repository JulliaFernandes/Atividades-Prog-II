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
        long long int cpf;

    public:
        Professor(string nome, string endereco, string titulacao, string curso, long long int _cpf);
        Professor ();

        void setTitulacao(string titulacao);
        string getTitulacao();

        void setCurso(string curso);
        string getCurso();
        
        void setCpf(long long int _cpf);
        long long int getCpf();
};

#endif