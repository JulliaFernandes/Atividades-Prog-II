#include "curso.hpp"
#include <iostream>

using namespace std;

Curso :: Curso(string nome, ListaProfessor* prof, ListaAluno* aluno, ListaDisciplina* disciplina){
    this -> nome = nome;
    this -> aluno = new ListaAluno();
    this -> prof = new ListaProfessor();
    this -> disciplina = new ListaDisciplina();
}

Curso :: Curso(){
    this -> aluno = new ListaAluno();
    this -> prof = new ListaProfessor();
    this -> disciplina = new ListaDisciplina();
}

void Curso :: cadastrarAluno(){
    string nome, endereco;

    cin.ignore();
    cout << "Digite o nome do aluno:" << endl;
    getline(cin, nome);

    cout << "Digite o endereço do aluno:" << endl;
    getline(cin, endereco);

    for(auto &letra: nome)letra=towlower(letra);
    for(auto &letra: endereco)letra=towlower(letra);

    aluno -> inserir(nome, endereco);
}

void Curso :: cadastrarProfessor(){
    string nome, endereco, titulacao, curso;
    int controlador = -1;
    Professor* p = prof -> getPrimeiro();

    cin.ignore();
    cout << "Digite o nome do professor:" << endl;
    getline(cin, nome);

    for(auto &letra: nome)letra=towlower(letra);

    while(p){
        if (p -> getNome() == nome){
            cout << "PROFESSOR JA CADASTRADO" << endl;
            controlador = 1;
        }
        p = p -> obterProximo(); 
    }

    if(controlador != 1){

        cout << "Digite o endereço do professor:" << endl;
        getline(cin, endereco);

        cout << "Digite a titulaçao do professor:" << endl;
        getline(cin, titulacao);

        cout << "Digite qual curso o prefesssor da aula:" << endl;
        getline(cin, curso);

        for(auto &letra: endereco)letra=towlower(letra); 
        for(auto &letra: titulacao)letra=towlower(letra);
        for(auto &letra: curso)letra=towlower(letra);

        prof-> inserir(nome, endereco, titulacao, curso); 
    }
}

void Curso :: cadastrarDisciplina(){
    string nomeD, prof1;
    int CH;
    int controlador = -1, controlador2 = -1;

    cin.ignore();
    cout << "Digite o nome da Disciplina:" << endl;
    getline(cin,nomeD);
    cout << "Digite a carga horaria:" << endl;
    cin >>  CH;
    cin.ignore();
    cout << "Digite o nome do professor:" << endl;
    getline(cin, prof1);

    for(auto &letra: nomeD)letra=towlower(letra);
    for(auto &letra: prof1)letra=towlower(letra);

    if(prof -> vazia()){
        cout << "NENHUM PROFESSOR COM ESSE NOME CADASTRADO";
    }
    else{
        Professor* p = prof -> getPrimeiro();
        Disciplina* d = disciplina -> getPrimeiro();

        while(d){
            if(d -> getNomeD() == nomeD){
                cout << "DISCIPLINA JA CADASTRADA" << endl;
                controlador2 = 1;
            }
            d = d -> obterProximo();
        }

        if(controlador2 != 1){
            while(p){
                if(prof1 == p -> getNome()){
                    disciplina -> inserir(nomeD, CH, p);
                    controlador = 1;
                }
                p = p-> obterProximo();
            }

            if(controlador != 1){
                cout << "Professor nao cadastrado" << endl;
            }
        } 
    }
}

// bool Curso :: vazia(){
//     return (primeiro == NULL);
// }

void Curso :: imprimirAlunos(){
    Aluno* a = aluno -> getPrimeiro();

    if(aluno -> vazia()){
        cout << "SEM ALUNOS" << endl;
    }
    else{
        cout << "ALUNOS" << endl;

        while(a){
            cout << "Nome =" << a->getNome() << endl;
            cout << "Endereço =" << a->getEndereco() << endl;
            cout << "Matricula =" << a-> getMatricula() << endl;
            a = a -> obterProximo();
            cout << endl;
        }
        cout << "-----------------------------------------------" << endl;
    }
}

void Curso :: imprimirProfessores(){
    Professor* p = prof -> getPrimeiro();

    if(prof -> vazia()){
        cout << "SEM PROFESSORES" << endl;
    }
    else{
        cout << "PROFESSORES" << endl;

        while(p){
            cout << "Nome =" << p->getNome() << endl;
            cout << "Endereço =" << p->getEndereco() << endl;
            cout << "Titulação =" << p-> getTitulacao() << endl;
            cout << "Curso =" << p -> getCurso() << endl;
            p = p -> obterProximo();
            cout << endl;
        }
        cout << "-----------------------------------------------" << endl;
    }
}

void Curso :: imprimirDisciplinas(){
    Disciplina* d = disciplina -> getPrimeiro();

    if(disciplina -> vazia()){
        cout << "SEM DISCIPLINA" << endl;
    }
    else{
        cout << "DISCIPLINAS    " << endl;

        while(d){
            cout << "Nome =" << d -> getNomeD() << endl;
            cout << "CH =" << d -> getCH() << endl; 
            cout << "Professor =" << d -> getProfessor() -> getNome() << endl;
            d = d -> obterProximo();
            cout << endl;
        }
        cout << "-----------------------------------------------" << endl;
    }
}