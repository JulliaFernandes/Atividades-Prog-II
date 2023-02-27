#ifndef PRODUTO_HPP
#define PRODUTO_HPP
#include <iostream>
#include <string>

using namespace std;

class Produto{
    private:
        int id;
        int qtd;
        string nome;
        float preco;
        Produto* proximo;
    
    public:
        int getId();

        void setQtd(int qtd);
        int getQtd();

        void setNome(string nome);
        string getNome();

        void setPreco(float preco);
        float getpreco();

        void unico();

        Produto(int id, int qtd, string nome, float preco);
        Produto();

        Produto*obterProximo();

        void setProx(Produto* p);

};
#endif