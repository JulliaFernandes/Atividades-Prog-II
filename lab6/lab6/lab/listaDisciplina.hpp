#ifndef LISTADISCIPLINA_HPP
#define LISTADISCIPLINA_HPP
#include <iostream>

using namespace std;

#include "disciplina.hpp"

class ListaDisciplina{
    private:
        Disciplina* primeiro;
        Disciplina* ultimo;

    public:
        int nItens;
        void inserir(string nome, int CH, Professor* p);
        ListaDisciplina(string nome, int ch, Professor* p);
        ListaDisciplina();

        void setPrimeiro();
        Disciplina* getPrimeiro();

        void setUltimo();
        Disciplina* getUltimo();

        bool vazia();
        virtual ~ListaDisciplina();

        ListaDisciplina* obterProximo();
        void setProximo(ListaDisciplina* p);
};
#endif