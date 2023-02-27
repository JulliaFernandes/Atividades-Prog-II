#include "PilhaLivro.hpp"

using namespace std;

int main(){
    int op = 0, error, error2, aux = 0, aux1 = 0, cont  = 0, auxCont = 0;
    string nome;
    float isbn;
    PilhaLivro* livro = new PilhaLivro();
    Livro* l;
    Livro* novo;

    do{
        do{
			error = 0;
			cout << "\n\t BEM VINDO " << endl;
			cout << "\n[1] Inserir Livro" << endl;
			cout << "[2] Remover Livro" << endl;
			cout << "[3] Imprimir Livro" << endl;
			cout << "[4] Status da pilha" << endl;
            cout << "[5] Topo da Pilha" << endl;
			cout << "[0] Sair" << endl;
			cin >> op;

			if(cin.fail()){
				cout << "\nDIGITE SOMENTE NUMERO" << endl;
				error = 1;
				cin.clear();
				cin.ignore(80, '\n');
			}
		}while(error == 1);

        switch (op){
            case 1:
            aux = 0;
                l = livro -> getPrimeiro();
                cin.ignore();
				cout << "Digite o nome do livro" << endl;
				getline(cin, nome);
				do{
					error2 = 0;
					cout << "Digite o ISBN: " << endl;
					cin >> isbn;

					if(cin.fail()){
						cout << "\nDIGITE SOMENTE NUMERO" << endl;
						error2 = 1;
						cin.clear();
						cin.ignore(80, '\n');
					}
				}while(error2 == 1);

                l = livro -> getPrimeiro();
                while(l){
                    if(l -> getISBN() == isbn){
                        cout << "ISBN JA CADASTRADO" << endl;
                        aux = 1;
                    }
                    l = l -> getProximo();
                }

                if(aux == 0){
                    novo = new Livro(nome, isbn);
                    livro -> CadastrarLivro(novo);
                }

                break;
            
            case 2:
                if(livro -> vazia()){
					cout << "[FILA VAZIA]" << endl;
				}
                else{
                    livro -> Retirar();
                }
                break;
            
            case 3:
                if(livro -> vazia()){
                    cout << "\n[PILHA VAZIA]" << endl;
                }
                else{
                    cout << "\t[PILHA DE LIVROS]" << endl;
                    livro -> ImprimirLivros();
                }
                break;
            
            case 4:
                if(livro -> vazia()){
                    cout << "\n[PILHA VAZIA]" << endl;
                }
                else{
                    cont = livro -> getItens();
                    cout << "Existem " << cont << " livros na pilha" << endl;
                }
                break;

            case 5:
                if(livro -> vazia()){
                        cout << "\n[PILHA VAZIA]" << endl;
                }
                else{
                    cout << "\t[Topo da Lista] " << endl;
                    cout << ">Nome: " << livro -> getPrimeiro() -> getNome() << endl;
                    cout << ">ISBN: " << livro -> getPrimeiro() -> getISBN() << endl;
                }
        }

    }while(op != 0);
}
