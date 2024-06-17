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
int loggedIn = 0;

Credential adminCredentials[] = {
    {"matheus.azevedo", "matheus.1234"},
    {"moab.rocha", "moab.1234"}
};

Credential recepcaoCredentials[] = {
    {"joao.santos", "joao.1234"},
    {"pedro.santos", "pedro.1234"}
};

Credential evolucaoCredentials[] = {
    {"gabriel.alves", "gabriel.1234"},
    {"luan.grilo", "luan.1234"}
};

int main() {
    Cadastro cadastros[qtdFuncionarios];
    int quantidadeCadastros = carregarDados(cadastros);

    Paciente pacientes[MAX_PACIENTES];
    int quantidadePacientes = 0;

    int opcao;
    

    while (!loggedIn) {
        printf("\n\t--Sistema de Gestão Hospitalar--\n");
        printf("\t  1. Recursos humanos\n");
        printf("\t  2. Recepcao\n");
        printf("\t  3. Centro Medico\n");
        printf("\t  4. Sair\n");
        printf("\t  Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

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
            printf("\tSaindo...\n");
            return 0;
        default:
            printf("\tOpção invalida. Tente novamente.\n");
        }
    }
    return 0;
}

int login(Credential *credentials, int numCredentials) {
    char username[50], password[50];
    
	system("cls");
    
    printf("\tUsuario: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0; 

    printf("\tSenha: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; 

    for (int i = 0; i < numCredentials; i++) {
        if (strcmp(username, credentials[i].username) == 0 &&
            strcmp(password, credentials[i].password) == 0) {
            return 1;
        }
    }
    
    system("cls");
    
    printf("\tUsuario ou senha incorretos.\n");
    return 0;
}

void adminMenu(Cadastro *cadastros, int *quantidadeCadastros) {
    int opcao;
    do {
        limparTela();
        printf("\n\tRecursos Humanos\n");
        printf("\t1. Cadastrar Funcionario novo\n");
        printf("\t2. Acessar Dados de Funcionarios\n");
        printf("\t3. Sair\n");
        printf("\tEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
        case 1:
            cadastroFuncionarios(cadastros, quantidadeCadastros);
            break;
        case 2:
            acessarDados(cadastros, *quantidadeCadastros);
            break;
        case 3:
            salvarDados(cadastros, *quantidadeCadastros);
            printf("\tSaindo...\n");
            system("cls");
            break;
        default:
            printf("\tOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);
    
    loggedIn = 0;
}

void recepcaoMenu(Paciente pacientes[], int *quantidadePacientes) {
    int opcao;

    do {
        limparTela();
        printf("\n\tRecepcaoo do Hospital\n");
		printf("\t1. Agendar Consulta\n");
		printf("\t2. Adicionar Paciente\n");
		printf("\t3. Triagem de Pacientes\n");
		printf("\t4. Mostrar Pacientes Agendados\n");
		printf("\t5. Sair\n");
		printf("\tEscolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
	        case 1:
	            system("cls");
	            agendarConsulta();
	            break;
	        case 2:
	            system("cls");
	            adicionarPaciente(pacientes, quantidadePacientes);
	            break;
	        case 3:
	            system("cls");
	            triagemPacientes(pacientes, *quantidadePacientes);
	            break;
	        case 4:
	            system("cls");
	            mostrarPacientesAgendados();
	            break;
	        case 5:
	        	printf("\tSaindo...\n");
	        	system("cls");
	        	break;
	        default:
	            printf("\tOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);
    
    loggedIn = 0;
}

void evolucaoPacienteMenu(Paciente pacientes[], int quantidadePacientes) {
    int opcao, opcaoDoc;

    do {
        limparTela();
        printf("\n\tCentro Medico\n");
        printf("\t1. Criar Documento de Evolução do Paciente\n");
        printf("\t2. Criar Documento de Alta do Paciente\n");
        printf("\t3. Criar Documento de Requisição do exame\n");
        printf("\t4. Sair\n");
        printf("\tEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

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
            printf("\tSaindo...\n");
            system("cls");
            break;
        default:
            printf("\tOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);
    
    loggedIn = 0;
}
