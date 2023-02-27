#ifndef DISCIPLINA_HPP
#define DISCIPLINA_HPP
#include <iostream>
#include <string>
#include "professor.hpp"

using namespace std;

class Disciplina{
    private:
        string nomeD;
        int CH;
        Professor* prof;
        long long int cpfP;

    public: 
        Disciplina(string nomeD, int CH, Professor* prof, long long int cpfP);
        Disciplina();

        void setNomeD();
        string getNomeD();

        void setCH();
        int getCH();

        void setProfessor(Professor* prof);
        Professor* getProfessor();

        void setCpfP(long long int cpfP);
        long long int getCpfP();
};
#endif