#ifndef __LAMPADA__HPP
#define __LAMPADA__HPP
#include <string>
using namespace std;

class lampada{
    private:
        string modelo;
        float tensao;
        bool estado;
        static int CONT;

    public:
        void setModelo(string modelo);
        string getModelo();

        void setTensao(float tensao);
        float getTensao();

        void setEstado(bool estado);
        bool getEstado();

        lampada(string modelo, float tensao);

        void acender();
        void apagar();
        void estadoAtual();

        int getCONT();

};

#endif