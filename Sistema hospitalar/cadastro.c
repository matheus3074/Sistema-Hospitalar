#include "cadastro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gerarMatricula(int contagem) {
    return 1000 + contagem;
}

void mostrarCadastro(Cadastro funcionario) {
    printf("\n\tDados do funcionario cadastrado:\n");
    printf("\tNome: %s\n", funcionario.nome);
    printf("\tCPF: %s\n", funcionario.cpf);
    printf("\tEndereco: %s\n", funcionario.endereco);
    printf("\tNumero da casa: %d\n", funcionario.numeroCasa);
    printf("\tE-mail: %s\n", funcionario.email);
    printf("\tTelefone(com DDD): %s\n", funcionario.numeroTelefone);
    printf("\tFuncao: %s\n", funcionario.funcao);
    printf("\tMatricula: %d\n", funcionario.matricula);
    printf("\tLogin: %s\n", funcionario.login);
    printf("\tSenha: %d\n", funcionario.senha);
}

void corrigirCadastro(Cadastro *funcionario) {
    char opcao;

    system("cls");

     printf("\n\tDeseja corrigir algum campo? (S/N): ");
    scanf(" %c", &opcao);
    getchar(); 

    while (opcao == 'S' || opcao == 's') {
        printf("\n\tQual campo deseja corrigir?\n");
        printf("\t1. Nome\n");
        printf("\t2. CPF\n");
        printf("\t3. Endereco\n");
        printf("\t4. Numero da casa\n");
        printf("\t5. E-mail\n");
        printf("\t6. Telefone\n");
        printf("\t7. Funcao\n");
        printf("\t8. Login\n");
        printf("\t9. Senha\n");
        printf("\tEscolha uma opcao: ");
        int escolha;
        scanf("%d", &escolha);
        getchar(); 

        switch (escolha) {
            case 1:
                printf("\tInforme o novo nome: ");
                fgets(funcionario->nome, sizeof(funcionario->nome), stdin);
                funcionario->nome[strcspn(funcionario->nome, "\n")] = '\0'; 
                break;
            case 2:
                printf("\tInforme o novo CPF (somente numeros): ");
                fgets(funcionario->cpf, sizeof(funcionario->cpf), stdin);
                funcionario->cpf[strcspn(funcionario->cpf, "\n")] = '\0'; 
                break;
            case 3:
                printf("\tInforme o novo endereco: ");
                fgets(funcionario->endereco, sizeof(funcionario->endereco), stdin);
                funcionario->endereco[strcspn(funcionario->endereco, "\n")] = 0; 
                break;
            case 4:
                printf("\tInforme o novo numero da casa: ");
                scanf("%d", &funcionario->numeroCasa);
                getchar(); 
                break;
            case 5:
                printf("\tInforme o novo e-mail: ");
                fgets(funcionario->email, sizeof(funcionario->email), stdin);
                funcionario->email[strcspn(funcionario->email, "\n")] = 0; 
                break;
            case 6:
                printf("\tInforme o novo telefone (com DDD): ");
                fgets(funcionario->numeroTelefone, sizeof(funcionario->numeroTelefone), stdin);
                funcionario->numeroTelefone[strcspn(funcionario->numeroTelefone, "\n")] = 0; 
                break;
            case 7:
                printf("\tInforme a nova funcao: ");
                fgets(funcionario->funcao, sizeof(funcionario->funcao), stdin);
                funcionario->funcao[strcspn(funcionario->funcao, "\n")] = 0; 
                break;
            case 8:
                printf("\tInforme o novo Login: ");
                fgets(funcionario->login, sizeof(funcionario->login), stdin);
                funcionario->login[strcspn(funcionario->login, "\n")] = 0; 
                break;
            case 9:
                printf("\tInforme a nova senha: ");
                fgets(funcionario->senha, sizeof(funcionario->senha), stdin);
                funcionario->senha[strcspn(funcionario->senha, "\n")] = 0; 
                break;
            default:
                printf("\tOpcao invalida.\n");
                break;
        }

        system("cls");
        mostrarCadastro(*funcionario);
        printf("\n\tDeseja corrigir outro campo? (S/N): ");
        scanf(" %c", &opcao);
        getchar(); 
    }
}

void salvarDados(Cadastro *cadastros, int qtd) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("\tErro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        fprintf(file, "%s;%s;%s;%d;%s;%s;%s;%s, %s, %d\n", cadastros[i].nome, cadastros[i].cpf, cadastros[i].endereco, 
                cadastros[i].numeroCasa, cadastros[i].email, cadastros[i].numeroTelefone, cadastros[i].funcao, 
                cadastros[i].login, cadastros[i].senha, cadastros[i].matricula);
    }

    fclose(file);
    printf("\tDados salvos com sucesso.\n");
}

int carregarDados(Cadastro *cadastros) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("\tNenhum arquivo de dados encontrado, começando com lista vazia.\n");
        return 0;
    }

    const char *format = 
        " %49[^;];"  
        "%12[^;];"        
        "%99[^;];"   
        "%d;"        
        "%49[^;];"   
        "%12[^;];"        
        "%49[^;];"   
        "%29[^;];" 
        "%29[^;];" 
        "%d\n";      

    int qtd = 0;
    while (fscanf(file, format, 
                  cadastros[qtd].nome, cadastros[qtd].cpf, cadastros[qtd].endereco, &cadastros[qtd].numeroCasa, 
                  cadastros[qtd].email, cadastros[qtd].numeroTelefone, cadastros[qtd].funcao, 
                  &cadastros[qtd].matricula) != EOF) {
        qtd++;
    }

    fclose(file);
    printf("\tDados carregados com sucesso.\n");
    return qtd;
}

void cadastroFuncionarios(Cadastro *cadastroDeFuncionarios, int *quantidadeCadastros) {
    char resposta;

    do {
        system("cls");
        printf("\tInforme o nome do funcionario: ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].nome, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].nome), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].nome[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].nome, "\n")] = 0;
        
        printf("\n\tInforme o CPF do funcionario (somente numeros): ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].cpf, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].cpf), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].cpf[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].cpf, "\n")] = 0; 

        printf("\n\tInforme o endereco do funcionario: ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].endereco, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].endereco), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].endereco[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].endereco, "\n")] = 0; 

        printf("\n\tInforme o numero da casa: ");
        scanf("%d", &cadastroDeFuncionarios[*quantidadeCadastros].numeroCasa);
        getchar();

        printf("\n\tInforme o e-mail do funcionario: ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].email, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].email), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].email[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].email, "\n")] = 0; 

        printf("\n\tInforme o telefone do funcionario (com DDD): ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].numeroTelefone, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].numeroTelefone), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].numeroTelefone[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].numeroTelefone, "\n")] = 0; 

        printf("\n\tInforme a funcao do funcionario: ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].funcao, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].funcao), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].funcao[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].funcao, "\n")] = 0; 
        
        printf("\n\tCrie o login do funcionario: ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].login, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].login), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].login[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].login, "\n")] = 0; 
        
        printf("\n\tCrie a senha do funcionario: ");
        fgets(cadastroDeFuncionarios[*quantidadeCadastros].senha, sizeof(cadastroDeFuncionarios[*quantidadeCadastros].senha), stdin);
        cadastroDeFuncionarios[*quantidadeCadastros].senha[strcspn(cadastroDeFuncionarios[*quantidadeCadastros].senha, "\n")] = 0; 

        cadastroDeFuncionarios[*quantidadeCadastros].matricula = gerarMatricula(*quantidadeCadastros);
        
        system("cls");
        printf("\n\tFuncionario cadastrado com sucesso!\n");
        mostrarCadastro(cadastroDeFuncionarios[*quantidadeCadastros]);
        
        getchar();
        
        corrigirCadastro(&cadastroDeFuncionarios[*quantidadeCadastros]);

        (*quantidadeCadastros)++;

        printf("\n\tDeseja cadastrar outro funcionario? (S/N): ");
        scanf(" %c", &resposta);
        getchar(); 

    } while (resposta == 'S' || resposta == 's');

    salvarDados(cadastroDeFuncionarios, *quantidadeCadastros);
}

void acessarDados(Cadastro *cadastros, int quantidadeCadastros) {
    system("cls");
    int matricula;
    printf("\tInforme a matricula do funcionario: ");
    scanf("%d", &matricula);
    getchar(); 

    int encontrado = 0;
    for (int i = 0; i < quantidadeCadastros; i++) {
        if (cadastros[i].matricula == matricula) {
            mostrarCadastro(cadastros[i]);
            encontrado = 1;

            printf("\n\tPressione Enter para continuar...");
            getchar(); 
            
            corrigirCadastro(&cadastros[i]);
            salvarDados(cadastros, quantidadeCadastros);
            

            break;
        }
    }

    if (!encontrado) {
        printf("\tFuncionario nao encontrado.\n");
    }

    printf("\n\tPressione Enter para voltar ao menu principal...");
    getchar();
}