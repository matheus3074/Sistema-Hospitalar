#ifndef CADASTRO_H
#define CADASTRO_H

#define qtdFuncionarios 50
#define FILENAME "funcionarios.txt"

typedef struct {
    char nome[50];
    char cpf[13];
    char endereco[100];
    int numeroCasa;
    char email[50];
    char numeroTelefone[13];
    char funcao[50];
    int matricula;
} Cadastro;

int gerarMatricula(int contagem);
void mostrarCadastro(Cadastro funcionario);
void corrigirCadastro(Cadastro *funcionario);
void salvarDados(Cadastro *cadastros, int qtd);
int carregarDados(Cadastro *cadastros);
void cadastroFuncionarios();
void acessarDados (Cadastro *cadastros, int qtd);

#endif
