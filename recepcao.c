#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_PACIENTES 200
#define MAX_COMPRIMENTO_NOME 100
#define MAX_COMPRIMENTO_SINTOMAS 200
#define MAX_COMPRIMENTO_CPF 15
#define MAX_COMPRIMENTO_TELEFONE 20
#define MAX_COMPRIMENTO_RESIDENCIA 200

typedef struct {
	char nome[MAX_COMPRIMENTO_NOME];
	int idade;
	char cpf[MAX_COMPRIMENTO_CPF];
	char telefone[MAX_COMPRIMENTO_TELEFONE];
	char residencia[MAX_COMPRIMENTO_RESIDENCIA];
	char sintomas[MAX_COMPRIMENTO_SINTOMAS];
	int gravidade; 
} Paciente;

void limparTela() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void pausarTela() {
	printf("Pressione Enter para continuar...");
	getchar();
	getchar();
}

void adicionarPaciente(Paciente pacientes[], int *quantidadePacientes) {
	if (*quantidadePacientes >= MAX_PACIENTES) {
		printf("Capacidade máxima de pacientes atingida.\n");
		return;
	}

	printf("Nome do paciente: ");
	getchar();
	fgets(pacientes[*quantidadePacientes].nome, MAX_COMPRIMENTO_NOME, stdin);

	printf("Idade do paciente: ");
	scanf("%d", &pacientes[*quantidadePacientes].idade);
	getchar();

	printf("CPF do paciente: ");
	fgets(pacientes[*quantidadePacientes].cpf, MAX_COMPRIMENTO_CPF, stdin);
	fflush(stdin);

	printf("Telefone do paciente (com DDD): ");
	fgets(pacientes[*quantidadePacientes].telefone, MAX_COMPRIMENTO_TELEFONE, stdin);
	fflush(stdin);

	printf("Endereço do paciente: ");
	fgets(pacientes[*quantidadePacientes].residencia, MAX_COMPRIMENTO_RESIDENCIA, stdin);

	printf("Sintomas do paciente: ");
	fgets(pacientes[*quantidadePacientes].sintomas, MAX_COMPRIMENTO_SINTOMAS, stdin);

	printf("Informe a gravidade do caso:\n");
	printf("0 - Verde (pouco urgente)\n");
	printf("1 - Amarelo (urgente)\n");
	printf("2 - Laranja (muito urgente)\n");
	printf("3 - Vermelho (emergência)\n");
	scanf("%d", &pacientes[*quantidadePacientes].gravidade);

	(*quantidadePacientes)++;
	printf("Paciente adicionado com sucesso.\n");
}

int compararGravidade(const void *a, const void *b) {
	const Paciente *pacienteA = (const Paciente *)a;
	const Paciente *pacienteB = (const Paciente *)b;


	int gravidadeA, gravidadeB;
	switch (pacienteA->gravidade) {
		case 0:
			gravidadeA = 4;
			break;  // Verde
		case 1:
			gravidadeA = 3;
			break;  // Amarelo
		case 2:
			gravidadeA = 2;
			break;  // Laranja
		case 3:
			gravidadeA = 1;
			break;  // Vermelho
		default:
			gravidadeA = 0;
			break; // Valor inválido
	}
	switch (pacienteB->gravidade) {
		case 0:
			gravidadeB = 4;
			break;
		case 1:
			gravidadeB = 3;
			break;
		case 2:
			gravidadeB = 2;
			break;
		case 3:
			gravidadeB = 1;
			break;
		default:
			gravidadeB = 0;
			break;
	}

	return gravidadeB - gravidadeA; 
}

void triagemPacientes(Paciente pacientes[], int quantidadePacientes) {
	qsort(pacientes, quantidadePacientes, sizeof(Paciente), compararGravidade);

	if(quantidadePacientes <= 0) {
		printf("Nenhum paciente cadastrado!");
	} else {
		printf("Pacientes em ordem de triagem:\n");
		for (int i = 0; i < quantidadePacientes; i++) {
			printf("Paciente %d:\n", i + 1);
			printf("Nome: %s", pacientes[i].nome);
			printf("Idade: %d\n", pacientes[i].idade);
			printf("CPF: %s", pacientes[i].cpf);
			printf("Telefone: %s", pacientes[i].telefone);
			printf("Residência: %s", pacientes[i].residencia);
			printf("Sintomas: %s", pacientes[i].sintomas);
			printf("Gravidade: ");
			switch (pacientes[i].gravidade) {
				case 0:
					printf("Verde (pouco urgente)\n");
					break;
				case 1:
					printf("Amarelo (urgente)\n");
					break;
				case 2:
					printf("Laranja (muito urgente)\n");
					break;
				case 3:
					printf("Vermelho (emergência)\n");
					break;
				default:
					printf("Desconhecida\n");
					break;
			}
			printf("\n");
		}
	}
}



void menu() {
	printf("\nRecepção do Hospital\n");
	printf("1. Adicionar Paciente\n");
	printf("2. Triagem de Pacientes\n");
	printf("3. Sair\n");
	printf("Escolha uma opção: ");
}

void executarOpcao(int opcao, Paciente pacientes[], int *quantidadePacientes) {
	switch (opcao) {
		case 1:
			adicionarPaciente(pacientes, quantidadePacientes);
			pausarTela();
			break;
		case 2:
			triagemPacientes(pacientes, *quantidadePacientes);
			pausarTela();
			break;
		case 3:
			printf("Saindo...\n");
			break;
		default:
			printf("Opção inválida. Tente novamente.\n");
			pausarTela();
	}
}

int main() {
	setlocale(LC_ALL, "");

	Paciente pacientes[MAX_PACIENTES];
	int quantidadePacientes = 0;
	int opcao;

	do {
		limparTela();
		menu();
		scanf("%d", &opcao);
		limparTela();
		executarOpcao(opcao, pacientes, &quantidadePacientes);
	} while (opcao != 3);

	return 0;
}