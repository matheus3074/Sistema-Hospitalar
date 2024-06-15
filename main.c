#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"
#include "evolucao_paciente.h"
#include "recepcao_hospital.h"

void mostrarMenu() {
    printf("\n=== Menu Inicial ===\n");
    printf("1. Cadastrar Funcionários\n");
    printf("2. Acessar dados do funcionários\n");
    printf("3. Criar Documento de Evolução do Paciente\n");
    printf("4. Adicionar Paciente\n");
    printf("5. Triagem de Pacientes\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    Cadastro cadastros[qtdFuncionarios];
    Paciente pacientes[MAX_PACIENTES];
    int quantidadeCadastros = carregarDados(cadastros); // Carrega dados no início
    int quantidadePacientes = 0;
    int opcao;

    do {
        system("cls");
        mostrarMenu();
        scanf("%d", &opcao);
        getchar(); // Limpar buffer do scanf

        switch (opcao) {
            case 1:
                system("cls");
                cadastroFuncionarios(cadastros, &quantidadeCadastros);
                break;
            case 2:
                system("cls");
                acessarDados(cadastros, quantidadeCadastros);
                break;
            case 3:
                system("cls");
                documentoDeEvolucaoDoPaciente();
                break;
            case 4:
                system("cls");
                adicionarPaciente(pacientes, &quantidadePacientes);
                break;
            case 5:
                system("cls");
                triagemPacientes(pacientes, quantidadePacientes);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}