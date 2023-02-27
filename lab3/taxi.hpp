#ifndef __CORRIDA__HPP
#define __CORRIDA__HPP
#include <string>
using namespace std;

class corrida{
    private:
        string modeloCarro;
        float motorizaçao, kmInicial, kmFinal;
        string fabricanteCarro;
        string nome;

    public:
        void setModelo(string modeloCarro);
        string getModelo();

        void setMotorizaçao(float motorizaçao);
        float getMotorizaçao();

        void setFabricante(string fabricanteCarro);
        string getFabricante();

        void setNome(string nome);
        string getNome();

        void setQuilometragemInicial(float kmInicial);
        float getQuilometragemInicial();

        void setQuilometragemFinal(float kmFinal);
        float getQuilometragemFinal();

        void imprimir();

};
#endif
