#include "GestorEscola.h"
#include <fstream>
#include <sstream>
#include <iostream>

GestorEscola::GestorEscola(std::string ficheiro) : nomeFicheiro(ficheiro) {}

GestorEscola::~GestorEscola() {
    for (Aluno* aluno : alunos) delete aluno;
    for (Encarregado* enc : encarregados) delete enc;
}

Aluno* GestorEscola::encontrarAluno(int id) const {
    for (Aluno* aluno : alunos) {
        if (aluno->getId() == id) return aluno;
    }
    return nullptr;
}

Encarregado* GestorEscola::encontrarEncarregado(int id) const {
    for (Encarregado* enc : encarregados) {
        if (enc->getId() == id) return enc;
    }
    return nullptr;
}

// CRUD Alunos
void GestorEscola::adicionarAluno(int id, std::string nome) {
    if (encontrarAluno(id)) {
        std::cout << "Erro: Aluno com ID " << id << " ja existe.\n";
        return;
    }
    alunos.push_back(new Aluno(id, nome));
    std::cout << "Aluno adicionado com sucesso.\n";
}

void GestorEscola::listarAlunos() const {
    if (alunos.empty()) {
        std::cout << "Nenhum aluno cadastrado.\n";
        return;
    }
    std::cout << "\n=== Lista de Alunos ===\n";
    for (Aluno* aluno : alunos) {
        std::cout << "ID: " << aluno->getId() 
                  << " | Nome: " << aluno->getNome();
        if (aluno->getEncarregado()) {
            std::cout << " | Encarregado: " << aluno->getEncarregado()->getNome();
        }
        std::cout << "\n";
    }
}

void GestorEscola::imprimirAluno(int id) const {
    Aluno* aluno = encontrarAluno(id);
    if (!aluno) {
        std::cout << "Aluno nao encontrado.\n";
        return;
    }
    std::cout << "\n=== Dados do Aluno ===\n";
    std::cout << "ID: " << aluno->getId() << "\n";
    std::cout << "Nome: " << aluno->getNome() << "\n";
    if (aluno->getEncarregado()) {
        std::cout << "Encarregado: " << aluno->getEncarregado()->getNome() 
                  << " (ID: " << aluno->getEncarregado()->getId() << ")\n";
    } else {
        std::cout << "Sem encarregado atribuido.\n";
    }
}

void GestorEscola::eliminarAluno(int id) {
    for (auto it = alunos.begin(); it != alunos.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            alunos.erase(it);
            std::cout << "Aluno eliminado com sucesso.\n";
            return;
        }
    }
    std::cout << "Aluno nao encontrado.\n";
}

void GestorEscola::editarAluno(int id, std::string novoNome) {
    Aluno* aluno = encontrarAluno(id);
    if (!aluno) {
        std::cout << "Aluno nao encontrado.\n";
        return;
    }
    aluno->setNome(novoNome);
    std::cout << "Aluno editado com sucesso.\n";
}

int GestorEscola::contarAlunos() const {
    return alunos.size();
}

// Encarregados
void GestorEscola::adicionarEncarregado(int id, std::string nome, int idade) {
    if (encontrarEncarregado(id)) {
        std::cout << "Erro: Encarregado com ID " << id << " ja existe.\n";
        return;
    }
    encarregados.push_back(new Encarregado(id, nome, idade));
    std::cout << "Encarregado adicionado com sucesso.\n";
}

void GestorEscola::removerEncarregado(int id) {
    for (auto it = encarregados.begin(); it != encarregados.end(); ++it) {
        if ((*it)->getId() == id) {
            // Remover referência de todos os alunos
            for (Aluno* aluno : alunos) {
                if (aluno->getEncarregado() == *it) {
                    aluno->removerEncarregado();
                }
            }
            delete *it;
            encarregados.erase(it);
            std::cout << "Encarregado removido com sucesso.\n";
            return;
        }
    }
    std::cout << "Encarregado nao encontrado.\n";
}

void GestorEscola::atribuirEncarregadoAluno(int idAluno, int idEncarregado) {
    Aluno* aluno = encontrarAluno(idAluno);
    Encarregado* enc = encontrarEncarregado(idEncarregado);
    
    if (!aluno) {
        std::cout << "Aluno nao encontrado.\n";
        return;
    }
    if (!enc) {
        std::cout << "Encarregado nao encontrado.\n";
        return;
    }
    
    aluno->setEncarregado(enc);
    std::cout << "Encarregado atribuido com sucesso.\n";
}

// Ficheiros
void GestorEscola::gravarDados() {
    std::ofstream ficheiro(nomeFicheiro);
    if (!ficheiro.is_open()) {
        std::cout << "Erro ao abrir ficheiro para gravar.\n";
        return;
    }
    
    for (Aluno* aluno : alunos) {
        ficheiro << aluno->toString() << "\n";
    }
    
    ficheiro.close();
    std::cout << "Dados gravados com sucesso.\n";
}

void GestorEscola::carregarDados() {
    std::ifstream ficheiro(nomeFicheiro);
    if (!ficheiro.is_open()) {
        std::cout << "Ficheiro nao encontrado. A criar novo.\n";
        return;
    }
    
    std::string linha;
    while (std::getline(ficheiro, linha)) {
        if (linha.empty()) continue;
        
        std::stringstream ss(linha);
        std::string token;
        std::vector<std::string> tokens;
        
        while (std::getline(ss, token, ';')) {
            tokens.push_back(token);
        }
        
        if (tokens.size() >= 2) {
            int idAluno = std::stoi(tokens[0]);
            std::string nomeAluno = tokens[1];
            
            Aluno* aluno = new Aluno(idAluno, nomeAluno);
            
            if (tokens.size() >= 5 && tokens[2] != "0") {
                int idEnc = std::stoi(tokens[2]);
                std::string nomeEnc = tokens[3];
                int idadeEnc = std::stoi(tokens[4]);
                
                Encarregado* enc = encontrarEncarregado(idEnc);
                if (!enc) {
                    enc = new Encarregado(idEnc, nomeEnc, idadeEnc);
                    encarregados.push_back(enc);
                }
                aluno->setEncarregado(enc);
            }
            
            alunos.push_back(aluno);
        }
    }
    
    ficheiro.close();
    std::cout << "Dados carregados com sucesso.\n";
}