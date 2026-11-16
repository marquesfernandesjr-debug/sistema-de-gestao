#ifndef GESTOR_ESCOLA_H
#define GESTOR_ESCOLA_H

#include "Aluno.h"
#include "Encarregado.h"
#include <vector>
#include <string>

class GestorEscola {
private:
    std::vector<Aluno*> alunos;
    std::vector<Encarregado*> encarregados;
    std::string nomeFicheiro;

public:
    GestorEscola(std::string ficheiro = "lista_alunos.txt");
    ~GestorEscola();
    
    // CRUD Alunos
    void adicionarAluno(int id, std::string nome);
    void listarAlunos() const;
    void imprimirAluno(int id) const;
    void eliminarAluno(int id);
    void editarAluno(int id, std::string novoNome);
    int contarAlunos() const;
    
    // Encarregados
    void adicionarEncarregado(int id, std::string nome, int idade);
    void removerEncarregado(int id);
    void atribuirEncarregadoAluno(int idAluno, int idEncarregado);
    
    // Ficheiros
    void gravarDados();
    void carregarDados();
    
private:
    Aluno* encontrarAluno(int id) const;
    Encarregado* encontrarEncarregado(int id) const;
};

#endif