#include "curso.hpp"
#include <iostream>

using namespace std;

Curso :: Curso(string nome,  vector<Aluno>_alunos, vector<Professor>_professores, vector<Disciplina>_disciplinas){
    this -> nome = nome;
    this -> alunos = _alunos;
    this -> professores = _professores;
    this -> disciplinas = _disciplinas;
}

Curso :: Curso(){
    this -> nome = " ";
}

void Curso :: cadastrarAluno(){
    string nome, endereco;
    Aluno* a;
    cin.ignore();
    cout << "Digite o nome do aluno:" << endl;
    getline(cin, nome);

    cout << "Digite o endereço do aluno:" << endl;
    getline(cin, endereco);

    for(auto &letra: nome)letra=towlower(letra);
    for(auto &letra: endereco)letra=towlower(letra);

    a = new Aluno(nome, endereco);
    alunos.push_back(*a);
}

void Curso :: cadastrarProfessor(){
    string nome, endereco, titulacao, curso;
    int controlador = -1;
    long long int cpf;
    Professor* p;

    cin.ignore();
    cout << "Digite o nome do professor:" << endl;
    getline(cin, nome);

    for(auto &letra: nome)letra=towlower(letra);

    for(int i = 0; i < professores.size(); i++){
        if(professores[i].getNome() == nome){
            cout << "Professor ja cadastrado" << endl;
            controlador = 1;
        }
    }

    if(controlador != 1){

        cout << "Digite seu CPF:" << endl;
        cin >> cpf;

        controlador = 0;
        for(int i = 0; i < professores.size(); i++){
            if(professores[i].getCpf() == cpf){
                cout << "CPF ja cadastrado" << endl;
                controlador = 1;
            }
        }
        if(controlador != 1){
            cin.ignore();
            cout << "Digite o endereço do professor:" << endl;
            getline(cin, endereco);

            cout << "Digite a titulaçao do professor:" << endl;
            getline(cin, titulacao);

            cout << "Digite qual curso o prefesssor da aula:" << endl;
            getline(cin, curso);

            for(auto &letra: endereco)letra=towlower(letra); 
            for(auto &letra: titulacao)letra=towlower(letra);
            for(auto &letra: curso)letra=towlower(letra);

            p = new Professor(nome, endereco, titulacao, curso, cpf);
            professores.push_back(*p);
        } 
    }
}

void Curso :: cadastrarDisciplina(){
    string nomeD;
    int CH;
    long long int cpfP;
    int controlador = -1, controlador2 = -1;

    cin.ignore();
    cout << "Digite o nome da Disciplina:" << endl;
    getline(cin,nomeD);
    cout << "Digite a carga horaria:" << endl;
    cin >>  CH;
    cin.ignore();
    cout << "Digite o CPF do professor:" << endl;
    cin >> cpfP;

    for(auto &letra: nomeD)letra=towlower(letra);

    if(professores.size() == 0){
        cout << "NENHUM PROFESSOR CADASTRADO";
        controlador = 1;
    }
    if(controlador != 1){
        Professor p;
        Disciplina* d;

        for(int i = 0; i < disciplinas.size(); i++){
            if(disciplinas[i].getNomeD() == nomeD){
                cout << "DISCIPLINA JA CADASTRADA" << endl;
                controlador2 = 1;
            }
        }
        controlador = -1;
        if(controlador2 != 1){
            for(int i = 0; i <professores.size(); i++){
                 if(professores[i].getCpf() == cpfP){
                    p = professores[i];
                    d = new Disciplina(nomeD, CH, &p, cpfP);
                    disciplinas.push_back(*d);
                    controlador = 1;
                }
            }
            if(controlador != 1){
                cout << "Professor nao cadastrado" << endl;
            }
        } 
    }
}

void Curso :: imprimirAlunos(){

    if(alunos.size() == 0){
        cout << "[SEM ALUNOS]" << endl;
    }
        cout << "ALUNOS" << endl;
        for(int i = 0; i < alunos.size(); i++){
            cout << ">Nome: " << alunos[i].getNome() << endl;
            cout << ">Endereço: " << alunos[i].getEndereco() << endl;
            cout << ">Matricula: " << alunos[i].getMatricula() << endl;
            cout << endl;
            cout << "-----------------------------------------------" << endl;
        }
        
}

void Curso :: imprimirProfessores(){
    if(professores.size() == 0){
        cout << "[SEM PROFESSORES]" << endl;
    }
        cout << "PROFESSORES" << endl;
        for(int i = 0; i < professores.size(); i++){
            cout << ">Nome: " << professores[i].getNome() << endl;
            cout << ">CPF: " << professores[i].getCpf() << endl;
            cout << ">Endereço: " << professores[i].getEndereco() << endl;
            cout << ">Titulação: " << professores[i].getTitulacao() << endl;
            cout << ">Curso: " << professores[i].getCurso() << endl;
            cout << endl;
            cout << "-----------------------------------------------" << endl;
        }
}

void Curso :: imprimirDisciplinas(){

    if(disciplinas.size() == 0){
        cout << "[SEM DISCIPLINA]" << endl;
    }
        cout << "DISCIPLINAS    " << endl;
        for(int i = 0; i < disciplinas.size(); i++){
            cout << ">Nome da disciplina: " << disciplinas[i].getNomeD() << endl;
            cout << ">CH: " << disciplinas[i].getCH() << endl; 
            for(int j = 0; j < professores.size(); j++){
                if(professores[j].getCpf() == disciplinas[i].getCpfP()){
                    cout << ">Professor: " << professores[j].getNome() << endl;
                }
            }
            cout << endl;
            cout << "-----------------------------------------------" << endl;

        }
}