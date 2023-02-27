#include <iostream>
#include "curso.hpp"

using namespace std;

int main(){
    int op;
    Curso* c = new Curso();

    do{
        cout << "-------MENU-------" << endl;
        cout << "1-Cadastrar professor" << endl;
        cout << "2-Cadastrar aluno" << endl;
        cout << "3-Cadastrar discipina" << endl;
        cout << "4-Imprimir lista de profesores" << endl;
        cout << "5-Imprimir lista de alunos" << endl;
        cout << "6-Imprimir lista de disciplinas" << endl;
        cout << "0-Sair" << endl;
        cin >> op;
        switch (op){

            case 1:
                c -> cadastrarProfessor();
                break;
            
            case 2:
                c -> cadastrarAluno();
                break;

            case 3:
                c->cadastrarDisciplina();
                break;

            case 4:
                c -> imprimirProfessores();
                break;

            case 5:
                c -> imprimirAlunos();
                break;

            case 6:
                c -> imprimirDisciplinas();
                break;

            case 0:
                cout << "Saindo do programa" << endl;
                break;
        }
    }while(op != 0);


    return 0;
}