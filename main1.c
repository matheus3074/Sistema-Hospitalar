#include "cadastro.h"
#include "recepcao_hospital.h"
#include "evolucao_paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CREDENTIALS 2

typedef struct {
    char username[50];
    char password[50];
} Credential;

void adminMenu(Cadastro *cadastros, int *quantidadeCadastros);
void recepcaoMenu(Paciente pacientes[], int *quantidadePacientes);
void evolucaoPacienteMenu(Paciente pacientes[], int quantidadePacientes);

int login(Credential *credentials, int numCredentials);

Credential adminCredentials[] = {
    {"matheus.azevedo", "matheus.1234"},
    {"moab.santos", "moab.1234"}
};

Credential recepcaoCredentials[] = {
    {"joao.gabriel", "joao.1234"},
    {"pedro.santos", "pedro.1234"}
};

Credential evolucaoCredentials[] = {
    {"gabriel.santos", "gabriel.1234"},
    {"luan.grilo", "luan.1234"}
};

int main() {
    Cadastro cadastros[qtdFuncionarios];
    int quantidadeCadastros = carregarDados(cadastros);

    Paciente pacientes[MAX_PACIENTES];
    int quantidadePacientes = 0;

    int opcao;
    int loggedIn = 0;

    while (!loggedIn) {
        printf("Sistema de Gestão Hospitalar\n");
        printf("1. Login Administrador\n");
        printf("2. Acessar Recepção\n");
        printf("3. Evolução de Pacientes\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do scanf

        switch (opcao) {
            case 1:
                if (login(adminCredentials, MAX_CREDENTIALS)) {
                    loggedIn = 1;
                    adminMenu(cadastros, &quantidadeCadastros);
                }
                break;
            case 2:
                if (login(recepcaoCredentials, MAX_CREDENTIALS)) {
                    loggedIn = 1;
                    recepcaoMenu(pacientes, &quantidadePacientes);
                }
                break;
            case 3:
                if (login(evolucaoCredentials, MAX_CREDENTIALS)) {
                    loggedIn = 1;
                    evolucaoPacienteMenu(pacientes, quantidadePacientes);
                }
                break;
            case 4:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

