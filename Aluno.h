#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include "Encarregado.h"

class Aluno {
private:
    int id;
    std::string nome;
    Encarregado* encarregado;

public:
    Aluno(int id, std::string nome);
    ~Aluno();
    
    int getId() const;
    std::string getNome() const;
    void setNome(std::string nome);
    
    void setEncarregado(Encarregado* enc);
    Encarregado* getEncarregado() const;
    void removerEncarregado();
    
    std::string toString() const;
};

#endif