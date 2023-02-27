#ifndef _ALUNO_HPP
#define _ALUNO_HPP
#include "pessoa.hpp"
#include <string>

using namespace std;

class Aluno : public Pessoa{
    private:
        int matricula;
        Aluno* proximo;

    public:
        Aluno(string nome, string endereco);
        Aluno();

        int getMatricula();

        Aluno* obterProximo();
        void setProximo(Aluno* proximo);

};
#endif