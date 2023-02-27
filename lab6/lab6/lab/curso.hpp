#ifndef CURSO_HPP
#define CURSO_HPP
#include <iostream>
#include <string>
#include "listaAlunos.hpp"
#include "listaProfessor.hpp"
#include "listaDisciplina.hpp"

using namespace std;

class Curso{
    private:
        string nome;
        ListaAluno* aluno;
        ListaProfessor* prof;
        ListaDisciplina* disciplina;

    public:
        Curso(string nome, ListaProfessor* prof, ListaAluno* aluno, ListaDisciplina* disciplina);
        Curso();

        void cadastrarProfessor();
        void cadastrarAluno();
        void cadastrarDisciplina();
        void imprimirProfessores();
        void imprimirAlunos();
        void imprimirDisciplinas();

        bool vazia();
};

#endif