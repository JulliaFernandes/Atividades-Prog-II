#ifndef LISTAPROFESSOR_HPP
#define LISTAPROFESSOR_HPP
#include <iostream>
#include "professor.hpp"

using namespace std;

class ListaProfessor{
    private:
        Professor* primeiro;
        Professor* ultimo;

    public:

        ListaProfessor(string nome, string endereco, string titulacao, string curso);
        ListaProfessor();

        void inserir(string nome, string endereco, string titulacao, string curso);
        
        void setPrimeiro(Professor * primeiro);
        Professor* getPrimeiro();

        void setUltimo(Professor* ultimo);
        Professor* getUltimo();

        bool vazia();
        virtual ~ListaProfessor();


};
#endif