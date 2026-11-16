#ifndef ENCARREGADO_H
#define ENCARREGADO_H

#include <string>

class Encarregado {
private:
    int id;
    std::string nome;
    int idade;

public:
    Encarregado(int id, std::string nome, int idade);
    
    int getId() const;
    std::string getNome() const;
    int getIdade() const;
    void setNome(std::string nome);
    void setIdade(int idade);
    
    std::string toString() const;
};

#endif