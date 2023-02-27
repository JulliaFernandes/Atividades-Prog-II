#ifndef CURSO_HPP
#define CURSO_HPP
#include <iostream>
#include <string>
#include "aluno.hpp"
#include "professor.hpp"
#include "disciplina.hpp"
#include <vector>

using namespace std;

class Curso{
    private:
        string nome;
        vector<Aluno>alunos;
        vector<Professor>professores;
        vector<Disciplina>disciplinas;

    public:
        Curso(string nome,  vector<Aluno>_alunos, vector<Professor>_professores, vector<Disciplina>_disciplinas);
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