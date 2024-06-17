#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "recepcao_hospital.h"

#define MAX_PACIENTES 200
#define MAX_COMPRIMENTO_NOME 100
#define MAX_COMPRIMENTO_SINTOMAS 200
#define MAX_COMPRIMENTO_CPF 15
#define MAX_COMPRIMENTO_TELEFONE 20

struct ConsultaAgendada consultas_agendadas[MAX_PACIENTES];
int num_consultas = 0;

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausarTela() {
    printf("\tPressione Enter para continuar...");
    getchar();
    getchar();
}

int verificarEntradaNumerica(const char *entrada) {
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (!isdigit(entrada[i])) {
            return 0;
        }
    }
    return 1;
}

int verificarCPFValido(const char *cpf) {
    int i;

    for (i = 0; i < strlen(cpf); i++) {
        if (!isdigit(cpf[i])) {
            return 0;
        }
    }

    if (strlen(cpf) != 11) {
        return 0;
    }

    return 1;
}

void agendarConsulta() {
    Consulta consulta;
    Paciente paciente;
    int i;

    limparTela();

    if (num_consultas < MAX_PACIENTES) {
        printf("\n\t=== Agendamento de Consulta ===\n");

		fflush(stdin);

        printf("\tDigite o nome do medico: ");
        fgets(consulta.nome_medico, MAX_COMPRIMENTO_NOME, stdin);
        consulta.nome_medico[strcspn(consulta.nome_medico, "\n")] = '\0';

        printf("\tDigite a data da consulta (formato AAAA-MM-DD): ");
        fgets(consulta.data, MAX_DATA_LENGTH, stdin);
        consulta.data[strcspn(consulta.data, "\n")] = '\0';

		fflush(stdin);

        printf("\tDigite a hora da consulta (formato HH:MM): ");
        fgets(consulta.hora, MAX_HORA_LENGTH, stdin);
        consulta.hora[strcspn(consulta.hora, "\n")] = '\0';

		fflush(stdin);

        printf("\tDigite o nome do paciente: ");
        fgets(paciente.nome, MAX_COMPRIMENTO_NOME, stdin);
        paciente.nome[strcspn(paciente.nome, "\n")] = '\0';

        printf("\tDigite a idade do paciente: ");
        scanf("%d", &paciente.idade);
        getchar();

        if (paciente.idade <= 0) {
            printf("\tIdade invalida. Informe uma idade positiva.\n");
            return;
        }

        printf("\tDigite o CPF do paciente: ");
        fgets(paciente.cpf, MAX_COMPRIMENTO_CPF, stdin);
        paciente.cpf[strcspn(paciente.cpf, "\n")] = '\0';

        if (!verificarCPFValido(paciente.cpf)) {
            printf("\tCPF invalido. Deve conter exatamente 11 digitos numericos.\n");
            return;
        }

        printf("\tDigite o telefone do paciente: (**)*****-**** ");
        fgets(paciente.telefone, MAX_COMPRIMENTO_TELEFONE, stdin);
        paciente.telefone[strcspn(paciente.telefone, "\n")] = '\0';

        printf("\tDescreva os sintomas do paciente: ");
        fgets(paciente.sintomas, MAX_COMPRIMENTO_SINTOMAS, stdin);
        paciente.sintomas[strcspn(paciente.sintomas, "\n")] = '\0';

        printf("\tInforme a gravidade do caso:\n");
        printf("\t0 - Verde (pouco urgente)\n");
        printf("\t1 - Amarelo (urgente)\n");
        printf("\t2 - Laranja (muito urgente)\n");
        printf("\t3 - Vermelho (emergencia)\n");
        scanf("%d", &paciente.gravidade);
        getchar();

        if (paciente.gravidade < 0 || paciente.gravidade > 3) {
            printf("\tGravidade invalida. Escolha um valor entre 0 e 3.\n");
            return;
        }

        strcpy(consultas_agendadas[num_consultas].consulta.nome_medico, consulta.nome_medico);
        strcpy(consultas_agendadas[num_consultas].consulta.data, consulta.data);
        strcpy(consultas_agendadas[num_consultas].consulta.hora, consulta.hora);

        strcpy(consultas_agendadas[num_consultas].paciente.nome, paciente.nome);
        consultas_agendadas[num_consultas].paciente.idade = paciente.idade;
        strcpy(consultas_agendadas[num_consultas].paciente.cpf, paciente.cpf);
        strcpy(consultas_agendadas[num_consultas].paciente.telefone, paciente.telefone);
        strcpy(consultas_agendadas[num_consultas].paciente.sintomas, paciente.sintomas);
        consultas_agendadas[num_consultas].paciente.gravidade = paciente.gravidade;

        num_consultas++;

        printf("\tConsulta agendada com sucesso!\n");
    } else {
        printf("\tLimite maximo de consultas agendadas atingido.\n");
    }
}

void adicionarPaciente(Paciente pacientes[], int *quantidadePacientes) {
    Paciente paciente;
    int i;

    printf("\tNome do paciente: ");
    getchar();
    fgets(pacientes[*quantidadePacientes].nome, MAX_COMPRIMENTO_NOME, stdin);
    pacientes[*quantidadePacientes].nome[strcspn(pacientes[*quantidadePacientes].nome, "\n")] = '\0';

    printf("\tIdade do paciente: ");
    scanf("%d", &pacientes[*quantidadePacientes].idade);
    getchar();

    if (pacientes[*quantidadePacientes].idade <= 0) {
        printf("\tIdade invalida. Informe uma idade positiva.\n");
        return;
    }

    do {
        printf("\tCPF do paciente: ");
        fgets(pacientes[*quantidadePacientes].cpf, MAX_COMPRIMENTO_CPF, stdin);
        pacientes[*quantidadePacientes].cpf[strcspn(pacientes[*quantidadePacientes].cpf, "\n")] = '\0';

        if (!verificarCPFValido(pacientes[*quantidadePacientes].cpf)) {
            printf("\tCPF invalido. Deve conter exatamente 11 digitos numericos.\n");
        }
    } while (!verificarCPFValido(pacientes[*quantidadePacientes].cpf));

    printf("\tTelefone do paciente (com DDD): ");
    fgets(pacientes[*quantidadePacientes].telefone, MAX_COMPRIMENTO_TELEFONE, stdin);
    pacientes[*quantidadePacientes].telefone[strcspn(pacientes[*quantidadePacientes].telefone, "\n")] = '\0';

    printf("\tDescreva os sintomas do paciente: ");
    fgets(pacientes[*quantidadePacientes].sintomas, MAX_COMPRIMENTO_SINTOMAS, stdin);
    pacientes[*quantidadePacientes].sintomas[strcspn(pacientes[*quantidadePacientes].sintomas, "\n")] = '\0';

    printf("\tInforme a gravidade do caso (0 a 3):\n");
    printf("\t0 - Verde (pouco urgente)\n");
    printf("\t1 - Amarelo (urgente)\n");
    printf("\t2 - Laranja (muito urgente)\n");
    printf("\t3 - Vermelho (emergencia)\n");
    scanf("%d", &pacientes[*quantidadePacientes].gravidade);
    getchar();

    if (pacientes[*quantidadePacientes].gravidade < 0 || pacientes[*quantidadePacientes].gravidade > 3) {
        printf("\tGravidade invalida. Escolha um valor entre 0 e 3.\n");
        return;
    }

    (*quantidadePacientes)++;
    printf("\tPaciente adicionado com sucesso.\n");
}

int compararGravidade(const void *a, const void *b) {
    Paciente *pacienteA = (Paciente *)a;
    Paciente *pacienteB = (Paciente *)b;

    if (pacienteA->gravidade < pacienteB->gravidade) {
        return 1;
    } else if (pacienteA->gravidade > pacienteB->gravidade) {
		return -1;
	} else {
		return strcmp(pacienteA->nome, pacienteB->nome);
	}
}

void triagemPacientes(Paciente pacientes[], int quantidadePacientes) {
	limparTela();

	if (quantidadePacientes <= 0) {
		printf("\tNenhum paciente cadastrado!\n");
	} else {
		qsort(pacientes, quantidadePacientes, sizeof(Paciente), compararGravidade);
		printf("\tPacientes em ordem de triagem:\n");
		
		for (int i = 0; i < quantidadePacientes; i++) {
			printf("\tPaciente %d:\n", i + 1);
			printf("\tNome: %s\n", pacientes[i].nome);
			printf("\tIdade: %d\n", pacientes[i].idade);
			printf("\tCPF: %s\n", pacientes[i].cpf);
			printf("\tTelefone: %s\n", pacientes[i].telefone);
			printf("\tSintomas: %s\n", pacientes[i].sintomas);
			printf("\tGravidade: ");
			switch (pacientes[i].gravidade) {
				case 0:
					printf("\tVerde (pouco urgente)\n");
					break;
				case 1:
					printf("\tAmarelo (urgente)\n");
					break;
				case 2:
					printf("\tLaranja (muito urgente)\n");
					break;
				case 3:
					printf("\tVermelho (emergencia)\n");
					break;
				default:
					printf("\tDesconhecida\n");
					break;
			}
			printf("\t--------------------------\n");
		}
	}
}

void mostrarPacientesAgendados() {
	if(num_consultas == 0){
		printf("\n Nao ha consultas agendadas!! \n");
	} else{
		system("cls");
		printf("\n\t--- Pacientes Agendados ---\n");
		for (int i = 0; i < num_consultas; i++) {
			printf("\tConsulta %d:\n", i + 1);
			printf("\tMedico: %s\n", consultas_agendadas[i].consulta.nome_medico);
			printf("\tData: %s\n", consultas_agendadas[i].consulta.data);
			printf("\tHora: %s\n", consultas_agendadas[i].consulta.hora);
			printf("\tPaciente: %s\n", consultas_agendadas[i].paciente.nome);
			printf("\tIdade: %d\n", consultas_agendadas[i].paciente.idade);
			printf("\tCPF: %s\n", consultas_agendadas[i].paciente.cpf);
			printf("\tTelefone: %s\n", consultas_agendadas[i].paciente.telefone);
			printf("\tSintomas: %s\n", consultas_agendadas[i].paciente.sintomas);
			printf("\tGravidade: ");
			switch (consultas_agendadas[i].paciente.gravidade) {
				case 0:
					printf("\tVerde (pouco urgente)\n");
					break;
				case 1:
					printf("\tAmarelo (urgente)\n");
					break;
				case 2:
					printf("\tLaranja (muito urgente)\n");
					break;
				case 3:
					printf("\tVermelho (emergencia)\n");
					break;
				default:
					printf("\tDesconhecida\n");
					break;
			}
			printf("\t--------------------------\n");
		}
	}
}