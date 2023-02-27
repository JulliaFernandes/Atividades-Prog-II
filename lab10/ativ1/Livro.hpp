#ifndef _LIVRO_HPP
#define _LIVRO_HPP
#include <string>
#include <iostream>

using namespace std;

class Livro{
    private: 
        string nome;
        float isbn;
        Livro* proximo;
    public:
        Livro();
        Livro(string _nome, float _isbn);

        void setNome(string _nome);
        string getNome();

        void setISBN(float _isbn);
        float getISBN();

        void setProximo(Livro* proximo);
        Livro* getProximo();

};
#endif