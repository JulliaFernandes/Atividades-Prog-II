#include "carrinho.hpp"

int main ()
{
    int op;
    Carrinho compras; //chamando o construtor
    Produto p;

    do{
        cout << endl;
        cout << "-------MENU------" << endl;
        cout << "1-Inserir um produto" << endl;
        cout << "2-Consultar algum produto" << endl;
        cout << "3-Mostrar todos os produtos" << endl;
        cout << "4-Remover algum produto" << endl;
        cout << "5-Modificar informaçao de algum produto"<< endl;
        cout << "6-Sair do programa \n >";
        cin >> op;
        cout << endl;
        switch (op){
            case 1:
                compras.adicionar();
            break;

            case 2:
                compras.unicoC();
                compras.consultar();
            break;
            
            case 3:
                compras.mostrar();
            break;

            case 4:
                compras.unicoC();
                compras.remover();
            break;

            case 5:
                compras.unicoC();
                compras.modificar();
            break;

            case 6:
                cout << "Saindo do programa" << endl;
            return 0;
        }
        
    }while(op != 6);

  return 0;
}