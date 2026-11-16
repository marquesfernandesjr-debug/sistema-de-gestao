#include "Encarregado.h"
#include <sstream>

Encarregado::Encarregado(int id, std::string nome, int idade) 
    : id(id), nome(nome), idade(idade) {}

int Encarregado::getId() const { return id; }
std::string Encarregado::getNome() const { return nome; }
int Encarregado::getIdade() const { return idade; }

void Encarregado::setNome(std::string nome) { this->nome = nome; }
void Encarregado::setIdade(int idade) { this->idade = idade; }

std::string Encarregado::toString() const {
    std::stringstream ss;
    ss << id << ";" << nome << ";" << idade;
    return ss.str();
}