#ifndef _PILHALIVRO_HPP
#define _PILHALIVRO_HPP
#include <string>
#include <iostream>
#include "Livro.hpp"

using namespace std;

class PilhaLivro{
    private:
        Livro* primeiro;
        Livro* ultimo;
        int itens;

    public:
        PilhaLivro();
        PilhaLivro(string _nome, float _isbn);

        void setPrimeiro(Livro* primeiro);
        Livro* getPrimeiro();

        void setUltimo(Livro* ultimo);
        Livro* getUltimo(); 

        void setItens(int itens);
        int getItens();

        bool vazia();

        void CadastrarLivro(Livro* novoL);
        void Retirar();
        void ImprimirLivros();
};
#endif
