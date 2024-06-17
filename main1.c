#include "cadastro.h"
#include "recepcao_hospital.h"
#include "evolucao_paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CREDENTIALS 2

typedef struct
{
    char username[50];
    char password[50];
} Credential;

void adminMenu(Cadastro *cadastros, int *quantidadeCadastros);
void recepcaoMenu(Paciente pacientes[], int *quantidadePacientes);
void evolucaoPacienteMenu(Paciente pacientes[], int quantidadePacientes);

int login(Credential *credentials, int numCredentials);

Credential adminCredentials[] = {
    {"matheus.azevedo", "matheus.1234"},
    {"moab.santos", "moab.1234"}};

Credential recepcaoCredentials[] = {
    {"joao.gabriel", "joao.1234"},
    {"pedro.santos", "pedro.1234"}};

Credential evolucaoCredentials[] = {
    {"gabriel.santos", "gabriel.1234"},
    {"luan.grilo", "luan.1234"}};

int main()
{
    Cadastro cadastros[qtdFuncionarios];
    int quantidadeCadastros = carregarDados(cadastros);

    Paciente pacientes[MAX_PACIENTES];
    int quantidadePacientes = 0;

    int opcao;
    int loggedIn = 0;

    while (!loggedIn)
    {
        printf("Sistema de Gestão Hospitalar\n");
        printf("1. Login Administrador\n");
        printf("2. Acessar Recepção\n");
        printf("3. Evolução de Pacientes\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do scanf

        switch (opcao)
        {
        case 1:
            if (login(adminCredentials, MAX_CREDENTIALS))
            {
                loggedIn = 1;
                adminMenu(cadastros, &quantidadeCadastros);
            }
            break;
        case 2:
            if (login(recepcaoCredentials, MAX_CREDENTIALS))
            {
                loggedIn = 1;
                recepcaoMenu(pacientes, &quantidadePacientes);
            }
            break;
        case 3:
            if (login(evolucaoCredentials, MAX_CREDENTIALS))
            {
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

int login(Credential *credentials, int numCredentials)
{
    char username[50], password[50];
    printf("Usuário: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline

    printf("Senha: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline

    for (int i = 0; i < numCredentials; i++)
    {
        if (strcmp(username, credentials[i].username) == 0 &&
            strcmp(password, credentials[i].password) == 0)
        {
            return 1;
        }
    }
    printf("Usuário ou senha incorretos.\n");
    return 0;
}

void adminMenu(Cadastro *cadastros, int *quantidadeCadastros)
{
    int opcao;
    do
    {
        limparTela();
        printf("Menu Administrador\n");
        printf("1. Cadastrar Funcionário\n");
        printf("2. Acessar Dados de Funcionários\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do scanf

        switch (opcao)
        {
        case 1:
            cadastroFuncionarios(cadastros, quantidadeCadastros);
            break;
        case 2:
            acessarDados(cadastros, *quantidadeCadastros);
            break;
        case 3:
            salvarDados(cadastros, *quantidadeCadastros);
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);
}

void recepcaoMenu(Paciente pacientes[], int *quantidadePacientes)
{
    int opcao;

    do
    {
        limparTela();
        menu();
        scanf("%d", &opcao);
        executarOpcao(opcao, pacientes, quantidadePacientes);
    } while (opcao != 3);
}

void evolucaoPacienteMenu(Paciente pacientes[], int quantidadePacientes)
{
    int opcao, opcaoDoc;

    do {
        limparTela();
        printf("Menu de Evolução de Pacientes\n");
        printf("1. Criar Documento de Evolução do Paciente\n");
        printf("2. Criar Documento de Alta do Paciente\n");
        printf("3. Criar Documento de Requisição do exame\n");
        printf("4. Procurar documentos\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do scanf

        switch (opcao) {
        case 1:
            system("cls");
            documentoDeEvolucaoDoPaciente();
            break;
        case 2:
            system("cls");
            documentoDeAltaDoPaciente();
            break;
        case 3:
            system("cls");
            requisicaoDeExames();
            break;
        case 4:
            do {
                system("cls");
                limparTela();
                printf("1. Procurar Documento de Evolução do Paciente\n");
                printf("2. Procurar Documento de Alta do Paciente\n");
                printf("3. Procurar Documento de Requisição do exame\n");
                printf("4. Sair\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcaoDoc);
                getchar(); // Limpa o buffer do scanf

                switch (opcaoDoc) {
                case 1:
                    system("cls");
                    acessarDocumentoEvolucao();
                    break;
                case 2:
                    system("cls");
                    acessarDocumentoAlta();
                    break;
                case 3:
                    system("cls");
                    acessarDocumentoRequisicaoExames();
                    break;
                case 4:
                    printf("Saindo do menu de procura...\n");
                    break;
                default:
                    printf("Opção inválida. Tente novamente.\n");
                }
            } while (opcaoDoc != 4);
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);
}
