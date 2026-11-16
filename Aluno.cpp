#include "Aluno.h"
#include <sstream>

Aluno::Aluno(int id, std::string nome) 
    : id(id), nome(nome), encarregado(nullptr) {}

Aluno::~Aluno() {
    
}

int Aluno::getId() const { return id; }
std::string Aluno::getNome() const { return nome; }
void Aluno::setNome(std::string nome) { this->nome = nome; }

void Aluno::setEncarregado(Encarregado* enc) { this->encarregado = enc; }
Encarregado* Aluno::getEncarregado() const { return encarregado; }

void Aluno::removerEncarregado() { 
    encarregado = nullptr; 
}

std::string Aluno::toString() const {
    std::stringstream ss;
    ss << id << ";" << nome << ";";
    if (encarregado) {
        ss << encarregado->getId() << ";" << encarregado->getNome() 
           << ";" << encarregado->getIdade();
    } else {
        ss << "0;;0";
    }
    return ss.str();
}