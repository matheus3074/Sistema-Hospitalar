#ifndef RECEPCAO_HOSPITAL_H
#define RECEPCAO_HOSPITAL_H


#define MAX_PACIENTES 200
#define MAX_COMPRIMENTO_NOME 100
#define MAX_COMPRIMENTO_SINTOMAS 200
#define MAX_COMPRIMENTO_CPF 15
#define MAX_COMPRIMENTO_TELEFONE 20
#define MAX_DATA_LENGTH 11
#define MAX_HORA_LENGTH 6
// Incluir os headers necessários, incluindo evolucao_paciente.h se Paciente estiver definido lá

// Definir a estrutura Paciente
typedef struct {
    char nome[MAX_COMPRIMENTO_NOME];
    int idade;
    char cpf[MAX_COMPRIMENTO_CPF];
    char telefone[MAX_COMPRIMENTO_TELEFONE];
    char sintomas[MAX_COMPRIMENTO_SINTOMAS];
    int gravidade;
} Paciente;

// Em seguida, definir Consulta e ConsultaAgendada
typedef struct{
    char nome_medico[MAX_COMPRIMENTO_NOME];
    char data[MAX_DATA_LENGTH];
    char hora[MAX_HORA_LENGTH];
} Consulta;

struct ConsultaAgendada {
     Consulta consulta;
     Paciente paciente;
};

// Declaração externa de variáveis globais
extern struct ConsultaAgendada consultas_agendadas[MAX_PACIENTES];
extern int num_consultas;

// Declaração de funções
void limparTela();
void pausarTela();
int verificarEntradaNumerica(const char *entrada);
int verificarCPFValido(const char *cpf);
void agendarConsulta();
void adicionarPaciente(Paciente pacientes[], int *quantidadePacientes);
int compararGravidade(const void *a, const void *b);
void triagemPacientes(Paciente pacientes[], int quantidadePacientes);
void mostrarPacientesAgendados();
void menu();
void executarOpcao(int opcao, Paciente pacientes[], int *quantidadePacientes);

#endif /* RECEPCAO_HOSPITAL_H */
