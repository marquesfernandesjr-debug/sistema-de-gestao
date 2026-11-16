#include <iostream>
#include "GestorEscola.h"

int main() {
    GestorEscola escola;
    escola.carregarDados();
    
    int opcao;
    do {
        std::cout << "\n========== MENU ==========\n";
        std::cout << "1. Adicionar Aluno\n";
        std::cout << "2. Listar Todos os Alunos\n";
        std::cout << "3. Imprimir Aluno Especifico\n";
        std::cout << "4. Eliminar Aluno\n";
        std::cout << "5. Editar Aluno\n";
        std::cout << "6. Contar Alunos\n";
        std::cout << "7. Adicionar Encarregado\n";
        std::cout << "8. Remover Encarregado\n";
        std::cout << "9. Atribuir Encarregado a Aluno\n";
        std::cout << "0. Sair\n";
        std::cout << "==========================\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;
        
        int id;
        std::string nome;
        int idade;
        
        switch(opcao) {
            case 1:
                std::cout << "ID do aluno: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Nome do aluno: ";
                std::getline(std::cin, nome);
                escola.adicionarAluno(id, nome);
                break;
                
            case 2:
                escola.listarAlunos();
                break;
                
            case 3:
                std::cout << "ID do aluno: ";
                std::cin >> id;
                escola.imprimirAluno(id);
                break;
                
            case 4:
                std::cout << "ID do aluno a eliminar: ";
                std::cin >> id;
                escola.eliminarAluno(id);
                break;
                
            case 5:
                std::cout << "ID do aluno: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Novo nome: ";
                std::getline(std::cin, nome);
                escola.editarAluno(id, nome);
                break;
                
            case 6:
                std::cout << "Total de alunos: " << escola.contarAlunos() << "\n";
                break;
                
            case 7:
                std::cout << "ID do encarregado: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Nome do encarregado: ";
                std::getline(std::cin, nome);
                std::cout << "Idade do encarregado: ";
                std::cin >> idade;
                escola.adicionarEncarregado(id, nome, idade);
                break;
                
            case 8:
                std::cout << "ID do encarregado: ";
                std::cin >> id;
                escola.removerEncarregado(id);
                break;
                
            case 9:
                std::cout << "ID do aluno: ";
                std::cin >> id;
                std::cout << "ID do encarregado: ";
                std::cin >> idade;
                escola.atribuirEncarregadoAluno(id, idade);
                break;
                
            case 0:
                escola.gravarDados();
                std::cout << "A sair...\n";
                break;
                
            default:
                std::cout << "Opcao invalida!\n";
        }
    } while(opcao != 0);
    
    return 0;
}