#ifndef CARRINHO_HPP
#define CARRINHO_HPP
#include "produto.hpp"

class Carrinho{
    private:
        Produto* primeiro;
        Produto* ultimo;
        int cont = 0;
        float totalizador = 0;

        
    public:
        Carrinho();
        Carrinho(int id, int qtd, string nome, float preco);

        virtual ~Carrinho();

        void unicoC();
        //void Imprimir();

        bool vazio();

        void adicionar();
        void consultar();
        void mostrar();
        void remover();
        void modificar();
};
#endif
