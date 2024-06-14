#include "cadastro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gerarMatricula(int contagem) {
    return 1000 + contagem;
}

void mostrarCadastro(Cadastro funcionario) {
    printf("\nDados do funcionario cadastrado:\n");
    printf("Nome: %s\n", funcionario.nome);
    printf("CPF: %d\n", funcionario.cpf);
    printf("Endereco: %s\n", funcionario.endereco);
    printf("Numero da casa: %d\n", funcionario.numeroCasa);
    printf("E-mail: %s\n", funcionario.email);
    printf("Telefone: %d\n", funcionario.numeroTelefone);
    printf("Funcao: %s\n", funcionario.funcao);
    printf("Matricula: %d\n", funcionario.matricula);
}

void corrigirCadastro(Cadastro *funcionario) {
    char opcao;
    printf("\nDeseja corrigir algum campo? (S/N): ");
    scanf(" %c", &opcao);
    getchar(); // Limpa o buffer do scanf

    while (opcao == 'S' || opcao == 's') {
        printf("\nQual campo deseja corrigir?\n");
        printf("1. Nome\n");
        printf("2. CPF\n");
        printf("3. Endereco\n");
        printf("4. Numero da casa\n");
        printf("5. E-mail\n");
        printf("6. Telefone\n");
        printf("7. Funcao\n");
        printf("Escolha uma opcao: ");
        int escolha;
        scanf("%d", &escolha);
        getchar(); // Limpa o buffer do scanf

        switch (escolha) {
            case 1:
                printf("Informe o novo nome: ");
                fgets(funcionario->nome, sizeof(funcionario->nome), stdin);
                funcionario->nome[strcspn(funcionario->nome, "\n")] = 0; // Remove newline
                break;
            case 2:
                printf("Informe o novo CPF: ");
                scanf("%d", &funcionario->cpf);
                getchar(); // Limpa o buffer do scanf
                break;
            case 3:
                printf("Informe o novo endereco: ");
                fgets(funcionario->endereco, sizeof(funcionario->endereco), stdin);
                funcionario->endereco[strcspn(funcionario->endereco, "\n")] = 0; // Remove newline
                break;
            case 4:
                printf("Informe o novo numero da casa: ");
                scanf("%d", &funcionario->numeroCasa);
                getchar(); // Limpa o buffer do scanf
                break;
            case 5:
                printf("Informe o novo e-mail: ");
                scanf("%s", funcionario->email);
                getchar(); // Limpa o buffer do scanf
                break;
            case 6:
                printf("Informe o novo telefone: ");
                scanf("%d", &funcionario->numeroTelefone);
                getchar(); // Limpa o buffer do scanf
                break;
            case 7:
                printf("Informe a nova funcao: ");
                fgets(funcionario->funcao, sizeof(funcionario->funcao), stdin);
                funcionario->funcao[strcspn(funcionario->funcao, "\n")] = 0; // Remove newline
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }

        mostrarCadastro(*funcionario);
        printf("\nDeseja corrigir outro campo? (S/N): ");
        scanf(" %c", &opcao);
        getchar(); // Limpa o buffer do scanf
    }
}

void salvarDados(Cadastro *cadastros, int qtd) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        fprintf(file, "%s;%d;%s;%d;%s;%d;%s;%d\n", cadastros[i].nome, cadastros[i].cpf, cadastros[i].endereco, 
                cadastros[i].numeroCasa, cadastros[i].email, cadastros[i].numeroTelefone, cadastros[i].funcao, 
                cadastros[i].matricula);
    }

    fclose(file);
    printf("Dados salvos com sucesso.\n");
}

int carregarDados(Cadastro *cadastros) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Nenhum arquivo de dados encontrado, começando com lista vazia.\n");
        return 0;
    }

    const char *format = 
        " %49[^;];"  // Nome
        "%d;"        // CPF
        "%99[^;];"   // Endereço
        "%d;"        // Número da Casa
        "%49[^;];"   // Email
        "%d;"        // Número de Telefone
        "%49[^;];"   // Função
        "%d\n";      // Matrícula

    int qtd = 0;
    while (fscanf(file, format, 
                  cadastros[qtd].nome, &cadastros[qtd].cpf, cadastros[qtd].endereco, &cadastros[qtd].numeroCasa, 
                  cadastros[qtd].email, &cadastros[qtd].numeroTelefone, cadastros[qtd].funcao, 
                  &cadastros[qtd].matricula) != EOF) {
        qtd++;
    }

    fclose(file);
    printf("Dados carregados com sucesso.\n");
    return qtd;
}

void cadastroFuncionarios() {
    Cadastro cadastroDeFuncionarios[qtdFuncionarios];
    char resposta;
    int contagem = carregarDados(cadastroDeFuncionarios);

    do {
        printf("Informe o nome do funcionario: ");
        fgets(cadastroDeFuncionarios[contagem].nome, sizeof(cadastroDeFuncionarios[contagem].nome), stdin);
        cadastroDeFuncionarios[contagem].nome[strcspn(cadastroDeFuncionarios[contagem].nome, "\n")] = 0; // Remove newline
        
        printf("\nInforme o CPF do funcionario: ");
        scanf("%d", &cadastroDeFuncionarios[contagem].cpf);
        getchar(); // Limpa o buffer do scanf

        printf("\nInforme o endereco do funcionario: ");
        fgets(cadastroDeFuncionarios[contagem].endereco, sizeof(cadastroDeFuncionarios[contagem].endereco), stdin);
        cadastroDeFuncionarios[contagem].endereco[strcspn(cadastroDeFuncionarios[contagem].endereco, "\n")] = 0; // Remove newline
        
        printf("\nInforme o numero da casa do funcionario: ");
        scanf("%d", &cadastroDeFuncionarios[contagem].numeroCasa);
        getchar(); // Limpa o buffer do scanf
        
        printf("\nInforme o e-mail do funcionario: ");
        scanf("%s", cadastroDeFuncionarios[contagem].email);
        getchar(); // Limpa o buffer do scanf

        printf("\nInforme o telefone do funcionario: ");
        scanf("%d", &cadastroDeFuncionarios[contagem].numeroTelefone);
        getchar(); // Limpa o buffer do scanf

        printf("\nInforme a funcao do funcionario: ");
        fgets(cadastroDeFuncionarios[contagem].funcao, sizeof(cadastroDeFuncionarios[contagem].funcao), stdin);
        cadastroDeFuncionarios[contagem].funcao[strcspn(cadastroDeFuncionarios[contagem].funcao, "\n")] = 0; // Remove newline

        // Gerar matrícula para o funcionário
        cadastroDeFuncionarios[contagem].matricula = gerarMatricula(contagem);

        // Mostra os dados cadastrados e pergunta se algo precisa ser corrigido
        mostrarCadastro(cadastroDeFuncionarios[contagem]);
        corrigirCadastro(&cadastroDeFuncionarios[contagem]);

        printf("\n\nDeseja cadastrar um novo funcionario (S/N)? ");
        scanf("%c", &resposta);
        getchar(); // Limpa o buffer do scanf

        contagem++;

        if (resposta == 'N' || resposta == 'n' || contagem >= qtdFuncionarios) {
            break;
        }

        system("cls");

    } while (1);

    salvarDados(cadastroDeFuncionarios, contagem);
    printf("Cadastro concluído.\n");
}
