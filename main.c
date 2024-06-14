#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"
#include "evolucao_paciente.h"
#include "recepcao_hospital.h"

void mostrarMenu() {
    printf("\n=== Menu Inicial ===\n");
    printf("1. Cadastrar Funcionários\n");
    printf("2. Acessar dados do funcionarios\n");
    printf("3. Criar Documento de Evolução do Paciente\n");
    printf("4. Adicionar Paciente\n");
    printf("5. Triagem de Pacientes\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    Paciente pacientes[MAX_PACIENTES];
    int quantidadePacientes = 0;
    int opcao;
    char cpf;
    do {
        mostrarMenu();
        scanf("%d", &opcao);
        getchar(); // Limpar buffer do scanf

        switch (opcao) {
            case 1:
                cadastroFuncionarios();
                break;
            case 2:
                acessarDados (Cadastro *cadastros, int qtd);
                break;
            case 3:
                documentoDeEvolucaoDoPaciente();
                break;
            case 4:
                adicionarPaciente(pacientes, &quantidadePacientes);
                break;
            case 5:
                triagemPacientes(pacientes, quantidadePacientes);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
