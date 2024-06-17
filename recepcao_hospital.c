#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_MEDICO 50
#define MAX_DATA_LENGTH 20
#define MAX_HORA_LENGTH 10
#define MAX_PACIENTES 200
#define MAX_COMPRIMENTO_NOME 100
#define MAX_COMPRIMENTO_SINTOMAS 200
#define MAX_COMPRIMENTO_CPF 15
#define MAX_COMPRIMENTO_TELEFONE 20

struct Paciente {
	char nome[MAX_COMPRIMENTO_NOME];
	int idade;
	char cpf[MAX_COMPRIMENTO_CPF];
	char telefone[MAX_COMPRIMENTO_TELEFONE];
	char sintomas[MAX_COMPRIMENTO_SINTOMAS];
	int gravidade;
};

struct Consulta {
	char nome_medico[MAX_COMPRIMENTO_NOME];
	char data[MAX_DATA_LENGTH];
	char hora[MAX_HORA_LENGTH];
};

struct ConsultaAgendada {
	struct Consulta consulta;
	struct Paciente paciente;
};

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
	printf("Pressione Enter para continuar...");
	getchar();
	getchar();
}

void agendarConsulta() {
	struct Consulta consulta;
	struct Paciente paciente;

	limparTela();

	printf("\n=== Agendamento de Consulta ===\n");

	printf("Digite o nome do médico: ");
	fgets(consulta.nome_medico, MAX_COMPRIMENTO_NOME, stdin);
	consulta.nome_medico[strcspn(consulta.nome_medico, "\n")] = '\0';

	printf("Digite a data da consulta (formato AAAA-MM-DD): ");
	fgets(consulta.data, MAX_DATA_LENGTH, stdin);
	consulta.data[strcspn(consulta.data, "\n")] = '\0';

	printf("Digite a hora da consulta (formato HH:MM): ");
	fgets(consulta.hora, MAX_HORA_LENGTH, stdin);
	consulta.hora[strcspn(consulta.hora, "\n")] = '\0';

	printf("Digite o nome do paciente: ");
	fgets(paciente.nome, MAX_COMPRIMENTO_NOME, stdin);
	paciente.nome[strcspn(paciente.nome, "\n")] = '\0';

	printf("Digite a idade do paciente: ");
	scanf("%d", &paciente.idade);
	getchar();

	printf("Digite o CPF do paciente: ");
	fgets(paciente.cpf, MAX_COMPRIMENTO_CPF, stdin);
	paciente.cpf[strcspn(paciente.cpf, "\n")] = '\0';

	printf("Digite o telefone do paciente: ");
	fgets(paciente.telefone, MAX_COMPRIMENTO_TELEFONE, stdin);
	paciente.telefone[strcspn(paciente.telefone, "\n")] = '\0';

	printf("Descreva os sintomas do paciente: ");
	fgets(paciente.sintomas, MAX_COMPRIMENTO_SINTOMAS, stdin);
	paciente.sintomas[strcspn(paciente.sintomas, "\n")] = '\0';

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

	printf("Consulta agendada com sucesso!\n");
}

void adicionarPaciente(struct Paciente pacientes[], int *quantidadePacientes) {

	printf("Nome do paciente: ");
	getchar();
	fgets(pacientes[*quantidadePacientes].nome, MAX_COMPRIMENTO_NOME, stdin);
	pacientes[*quantidadePacientes].nome[strcspn(pacientes[*quantidadePacientes].nome, "\n")] = '\0';

	printf("Idade do paciente: ");
	scanf("%d", &pacientes[*quantidadePacientes].idade);
	getchar();

	printf("CPF do paciente: ");
	fgets(pacientes[*quantidadePacientes].cpf, MAX_COMPRIMENTO_CPF, stdin);
	pacientes[*quantidadePacientes].cpf[strcspn(pacientes[*quantidadePacientes].cpf, "\n")] = '\0';

	printf("Telefone do paciente (com DDD): ");
	fgets(pacientes[*quantidadePacientes].telefone, MAX_COMPRIMENTO_TELEFONE, stdin);
	pacientes[*quantidadePacientes].telefone[strcspn(pacientes[*quantidadePacientes].telefone, "\n")] = '\0';

	printf("Descreva os sintomas do paciente: ");
	fgets(pacientes[*quantidadePacientes].sintomas, MAX_COMPRIMENTO_SINTOMAS, stdin);
	pacientes[*quantidadePacientes].sintomas[strcspn(pacientes[*quantidadePacientes].sintomas, "\n")] = '\0';

    printf("Informe a gravidade do caso:\n");
	printf("0 - Verde (pouco urgente)\n");
	printf("1 - Amarelo (urgente)\n");
	printf("2 - Laranja (muito urgente)\n");
	printf("3 - Vermelho (emergência)\n");
	scanf("%d", &pacientes->gravidade);
	int c;
    while ((c = getchar()) != '\n' && c != EOF);
    

	(*quantidadePacientes)++;
	printf("Paciente adicionado com sucesso.\n");
}

int compararGravidade(const void *a, const void *b) {
	const struct Paciente *pacienteA = (const struct Paciente *)a;
	const struct Paciente *pacienteB = (const struct Paciente *)b;

	return pacienteB->gravidade - pacienteA->gravidade;
}

void triagemPacientes(struct Paciente pacientes[], int quantidadePacientes) {
	limparTela();

    qsort(pacientes, quantidadePacientes, sizeof(struct Paciente), compararGravidade);

	printf("Pacientes em ordem de triagem:\n");
	for (int i = 0; i < quantidadePacientes; i++) {
		printf("Paciente %d:\n", i + 1);
		printf("Nome: %s\n", pacientes[i].nome);
		printf("Idade: %d\n", pacientes[i].idade);
		printf("CPF: %s\n", pacientes[i].cpf);
		printf("Telefone: %s\n", pacientes[i].telefone);
		printf("Sintomas: %s\n", pacientes[i].sintomas);
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
		printf("--------------------------\n");
	}
}

void mostrarPacientesAgendados() {
	printf("\n--- Pacientes Agendados ---\n");
	for (int i = 0; i < num_consultas; i++) {
		printf("Consulta %d:\n", i + 1);
		printf("Médico: %s\n", consultas_agendadas[i].consulta.nome_medico);
		printf("Data: %s\n", consultas_agendadas[i].consulta.data);
		printf("Hora: %s\n", consultas_agendadas[i].consulta.hora);
		printf("Paciente: %s\n", consultas_agendadas[i].paciente.nome);
		printf("Idade: %d\n", consultas_agendadas[i].paciente.idade);
		printf("CPF: %s\n", consultas_agendadas[i].paciente.cpf);
		printf("Telefone: %s\n", consultas_agendadas[i].paciente.telefone);
		printf("Sintomas: %s\n", consultas_agendadas[i].paciente.sintomas);
		printf("Gravidade: ");
		switch (consultas_agendadas[i].paciente.gravidade) {
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
		printf("--------------------------\n");
	}
}

void menu() {
	printf("\nRecepção do Hospital\n");
	printf("1. Agendar Consulta\n");
	printf("2. Adicionar Paciente\n");
	printf("3. Triagem de Pacientes\n");
	printf("4. Mostrar Pacientes Agendados\n");
	printf("5. Sair\n");
	printf("Escolha uma opção: ");
}

void executarOpcao(int opcao, struct Paciente pacientes[], int *quantidadePacientes) {
	switch (opcao) {
		case 1:
			agendarConsulta();
			pausarTela();
			break;
		case 2:
			adicionarPaciente(pacientes, quantidadePacientes);
			pausarTela();
			break;
		case 3:
			triagemPacientes(pacientes, *quantidadePacientes);
			pausarTela();
			break;
		case 4:
			mostrarPacientesAgendados();
			pausarTela();
			break;
		case 5:
			printf("Saindo...\n");
			break;
		default:
			printf("Opção inválida. Tente novamente.\n");
			pausarTela();
	}
}

int main() {
	struct Paciente pacientes[MAX_PACIENTES];
	int quantidadePacientes = 0;
	int opcao;

	do {
		limparTela();
		menu();
		scanf("%d", &opcao);
		getchar();

		executarOpcao(opcao, pacientes, &quantidadePacientes);
	} while (opcao != 5);

	
}







