#ifndef LISTAALUNO_HPP
#define LISTAALUNO_HPP

#include "aluno.hpp"

using namespace std; 

class ListaAluno{
    private:
        Aluno* primeiro;
        Aluno* ultimo;

    public:
        int nItens;
        void inserir(string nome, string endereco);
        ListaAluno(string nome, string endereco);
        ListaAluno();

        void setPrimeiro();
        Aluno* getPrimeiro();

        void setUltimo();
        Aluno* getUltimo();

        bool vazia();
        virtual ~ListaAluno();
};
#endif