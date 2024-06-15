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
    printf("CPF: %s\n", funcionario.cpf);
    printf("Endereco: %s\n", funcionario.endereco);
    printf("Numero da casa: %d\n", funcionario.numeroCasa);
    printf("E-mail: %s\n", funcionario.email);
    printf("Telefone: %s\n", funcionario.numeroTelefone);
    printf("Funcao: %s\n", funcionario.funcao);
    printf("Matricula: %d\n", funcionario.matricula);
}

void corrigirCadastro(Cadastro *funcionario) {
    char opcao;

    system("cls");

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
                fgets(funcionario->cpf, sizeof(funcionario->cpf), stdin);
                funcionario->cpf[strcspn(funcionario->cpf, "\n")] = 0; // Remove newline
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
                fgets(funcionario->email, sizeof(funcionario->email), stdin);
                funcionario->email[strcspn(funcionario->email, "\n")] = 0; // Remove newline
                break;
            case 6:
                printf("Informe o novo telefone: ");
                fgets(funcionario->numeroTelefone, sizeof(funcionario->numeroTelefone), stdin);
                funcionario->numeroTelefone[strcspn(funcionario->numeroTelefone, "\n")] = 0; // Remove newline
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

        system("cls");
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
        fprintf(file, "%s;%s;%s;%d;%s;%s;%s;%d\n", cadastros[i].nome, cadastros[i].cpf, cadastros[i].endereco, 
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
        "%12[^;];"        // CPF
        "%99[^;];"   // Endereço
        "%d;"        // Número da Casa
        "%49[^;];"   // Email
        "%12[^;];"        // Número de Telefone
        "%49[^;];"   // Função
        "%d\n";      // Matrícula

    int qtd = 0;
    while (fscanf(file, format, 
                  cadastros[qtd].nome, cadastros[qtd].cpf, cadastros[qtd].endereco, &cadastros[qtd].numeroCasa, 
                  cadastros[qtd].email, cadastros[qtd].numeroTelefone, cadastros[qtd].funcao, 
                  &cadastros[qtd].matricula) != EOF) {
        qtd++;
    }

    fclose(file);
    printf("Dados carregados com sucesso.\n");
    return qtd;
}

void cadastroFuncionarios(Cadastro *cadastroDeFuncionarios, int *quantidadeCadastros) {
    char resposta;

    do {
        system("cls");
        printf("Informe o nome do funcionario: ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].nome, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].nome), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].nome[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].nome, "\n")] = 0; // Remove newline
        
        printf("\nInforme o CPF do funcionario: ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].cpf, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].cpf), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].cpf[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].cpf, "\n")] = 0; // Remove newline

        printf("\nInforme o endereco do funcionario: ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].endereco, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].endereco), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].endereco[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].endereco, "\n")] = 0; // Remove newline

        printf("\nInforme o numero da casa: ");
        scanf("%d", &cadastroDeFuncionarios[*quantidadeCadastros].numeroCasa);
        getchar(); // Limpa o buffer do scanf

        printf("\nInforme o e-mail do funcionario: ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].email, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].email), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].email[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].email, "\n")] = 0; // Remove newline

        printf("\nInforme o telefone do funcionario: ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].numeroTelefone, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].numeroTelefone), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].numeroTelefone[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].numeroTelefone, "\n")] = 0; // Remove newline

        printf("\nInforme a funcao do funcionario: ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].funcao, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].funcao), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].funcao[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].funcao, "\n")] = 0; // Remove newline

        cadastroDeFuncionarios[*quantidadeCadastros].matricula = gerarMatricula(*quantidadeCadastros);
        
        printf("\nFuncionario cadastrado com sucesso!\n");
        mostrarCadastro(cadastroDeFuncionarios[*quantidadeCadastros]);
        
        corrigirCadastro(&cadastroDeFuncionarios[*quantidadeCadastros]);

        (*quantidadeCadastros)++;

        printf("\nDeseja cadastrar outro funcionario? (S/N): ");
        scanf(" %c", &resposta);
        getchar(); // Limpa o buffer do scanf

    } while (resposta == 'S' || resposta == 's');

    salvarDados(cadastroDeFuncionarios, *quantidadeCadastros);
}

void acessarDados(Cadastro *cadastros, int quantidadeCadastros) {
    system("cls");
    int matricula;
    printf("Informe a matricula do funcionario: ");
    scanf("%d", &matricula);
    getchar(); // Limpa o buffer do scanf

    int encontrado = 0;
    for (int i = 0; i < quantidadeCadastros; i++) {
        if (cadastros[i].matricula == matricula) {
            mostrarCadastro(cadastros[i]);
            encontrado = 1;

            printf("\nPressione Enter para continuar...");
            getchar(); // Pausa para permitir que o usuário veja a informação
            
            corrigirCadastro(&cadastros[i]);
            salvarDados(cadastros, quantidadeCadastros);
            

            break;
        }
    }

    if (!encontrado) {
        printf("Funcionario nao encontrado.\n");
    }

    printf("\nPressione Enter para voltar ao menu principal...");
    getchar(); // Pausa para permitir que o usuário veja a informação
}
