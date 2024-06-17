#ifndef RECEPCAO_HOSPITAL_H
#define RECEPCAO_HOSPITAL_H

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

void limparTela();
void pausarTela();
void agendarConsulta();
void mostrarPacientesAgendados();
void adicionarPaciente(Paciente pacientes[], int *quantidadePacientes);
void triagemPacientes(Paciente pacientes[], int quantidadePacientes);
void menu();
void executarOpcao(int opcao, Paciente pacientes[], int *quantidadePacientes);

#endif
