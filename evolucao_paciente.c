#include "evolucao_paciente.h"
#include <stdio.h>

void documentoDeEvolucaoDoPaciente() {
    FILE *arquivoDaEvolucaoDoPaciente; // Declaração de ponteiro de arquivo
    char nomePaciente[100], nomeMedico[100], idade[20], crm[20], diagnostico[1000], leito[5], sexo[10], diaMesAno[10];
    
    arquivoDaEvolucaoDoPaciente = fopen("Evolucao_do_paciente.txt", "w");

    if (arquivoDaEvolucaoDoPaciente == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    } else {
        // Solicitando informações ao usuário
        printf("Digite o nome do paciente: ");
        fgets(nomePaciente, sizeof(nomePaciente), stdin);

        printf("Digite o gênero do paciente: ");
        fgets(sexo, sizeof(sexo), stdin);

        printf("Digite o nome do médico responsável: ");
        fgets(nomeMedico, sizeof(nomeMedico), stdin);

        fflush(stdin);

        printf("Digite o CRM do médico: ");
        fgets(crm, sizeof(crm), stdin);

        printf("Escreva o diagnostico do paciente: ");
        fgets(diagnostico, sizeof(diagnostico), stdin);

        printf("Digite a data da requisição: ");
        fgets(diaMesAno, sizeof(diaMesAno), stdin);

        fprintf(arquivoDaEvolucaoDoPaciente, "--- Evolução do paciente ---\n");

        fprintf(arquivoDaEvolucaoDoPaciente, "Paciente: %sIdade: %sLeito: %sSexo: %s", nomePaciente, idade, leito, sexo);

        fprintf(arquivoDaEvolucaoDoPaciente, "Médico Responsável: %sCRM: %sDiagnostico: %sData da Requisição: %s", nomeMedico, crm, diagnostico, diaMesAno);

        fprintf(arquivoDaEvolucaoDoPaciente, "--- Fim do Documento ---");

        fclose(arquivoDaEvolucaoDoPaciente);

        printf("Documento de evolução do paciente criado com sucesso!\n");
    }
}

void documentoDeAltaDoPaciente() {
    FILE *arquivoDeAltaDoPaciente; 
    char nomePaciente[100], nomeMedico[100], crm[20], data[10], horario[5], clinica[100];

    arquivoDeAltaDoPaciente = fopen("Alta_do_paciente.txt", "w");

    if (arquivoDeAltaDoPaciente == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    } else {
        printf("Digite o nome do paciente: ");
        fgets(nomePaciente, sizeof(nomePaciente), stdin);
        
        printf("Digite o nome do médico responsável: ");
        fgets(nomeMedico, sizeof(nomeMedico), stdin);

        fflush(stdin);
        
        printf("Digite o CRM do médico: ");
        fgets(crm, sizeof(crm), stdin);
       
        printf("Digite a data da requisição: ");
        fgets(data, sizeof(data), stdin);

        printf("Digite o horário do boletim: ");
        fgets(horario, sizeof(horario), stdin);
         
        printf("Escreva o nome da clínica: ");
        fgets(clinica, sizeof(clinica), stdin);

        fprintf(arquivoDeAltaDoPaciente, "--- Boletim médico ---\n\n");       

        fprintf(arquivoDeAltaDoPaciente, "Data: %s\n", data);

        fprintf(arquivoDeAltaDoPaciente, "Horário: %s\n", horario);

        fprintf(arquivoDeAltaDoPaciente, "Paciente: %s", nomePaciente);

        fprintf(arquivoDeAltaDoPaciente, "O Hospital %s informa que o paciente Eunicio Lopes de Oliveira recebeu alta da unidade de tratamento intensivo (UTI) nesta sexta-feira (28), pela manhã. O paciente realizou nova ressonância magnética de crânio com contraste, que resultou normal. Como diagnóstico final permanece Acidente Isquêmico Transitório (ATT).", clinica);

        fprintf(arquivoDeAltaDoPaciente, "Médico Responsável: %s CRM: %s", nomeMedico, crm);
    
        fclose(arquivoDeAltaDoPaciente);
    
        printf("Documento de alta do paciente criado com sucesso!\n");
    }
}

void requisicaoDeExames () {
    FILE *arquivo; 
    char nomePaciente[100], dataNascimento[20], genero[20], nomeMedico[100], crm[20], observacoes[500], dataRequisicao[20];
   
    arquivo = fopen("requisicao_exames.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        return 1;
    }
   
    printf("Digite o nome do paciente: ");
    fgets(nomePaciente, sizeof(nomePaciente), stdin);
    printf("Digite a data de nascimento do paciente: ");
    fgets(dataNascimento, sizeof(dataNascimento), stdin);
    printf("Digite o gênero do paciente: ");
    fgets(genero, sizeof(genero), stdin);
    printf("Digite o nome do médico responsável: ");
    fgets(nomeMedico, sizeof(nomeMedico), stdin);
    printf("Digite o CRM do médico: ");
    fgets(crm, sizeof(crm), stdin);
    printf("Digite observações (se houver): ");
    fgets(observacoes, sizeof(observacoes), stdin);
    printf("Digite a data da requisição: ");
    fgets(dataRequisicao, sizeof(dataRequisicao), stdin);
   
    fprintf(arquivo, "--- Requisição de Exames ---\n");
    fprintf(arquivo, "Paciente: %s", nomePaciente);
    fprintf(arquivo, "Data de Nascimento: %s", dataNascimento);
    fprintf(arquivo, "Gênero: %s", genero);
    fprintf(arquivo, "Médico Responsável: %s", nomeMedico);
    fprintf(arquivo, "CRM: %s", crm);
    fprintf(arquivo, "Observações: %s", observacoes);
    fprintf(arquivo, "Data da Requisição: %s", dataRequisicao);
    fprintf(arquivo, "--- Fim do Documento ---");
   

    fclose(arquivo);
   
    printf("Documento de requisição de exames criado com sucesso!");
   
    return 0;

}

void acessarDocumentoEvolucao() {
    FILE *arquivoDaEvolucaoDoPaciente;
    char linha[500];

    arquivoDaEvolucaoDoPaciente = fopen("Evolucao_do_paciente.txt", "r");

    if (arquivoDaEvolucaoDoPaciente == NULL) {
        printf("Nenhum arquivo de evolução do paciente foi encontrado!\n");
        return;
    }

    printf("\n--- Evolução do Paciente ---\n");
    while (fgets(linha, sizeof(linha), arquivoDaEvolucaoDoPaciente)) {
        printf("%s", linha);
    }
    fclose(arquivoDaEvolucaoDoPaciente);
}

void acessarDocumentoAlta() {
    FILE *arquivoDeAltaDoPaciente;
    char linha[500];

    arquivoDeAltaDoPaciente = fopen("Alta_do_paciente.txt", "r");

    if (arquivoDeAltaDoPaciente == NULL) {
        printf("Nenhum arquivo de alta do paciente foi encontrado! \n");
        return;
    }

    printf("\n--- Boletim Médico de Alta ---\n");
    while (fgets(linha, sizeof(linha), arquivoDeAltaDoPaciente)) {
        printf("%s", linha);
    }
    fclose(arquivoDeAltaDoPaciente);
}

void acessarDocumentoRequisicaoExames() {
    FILE *arquivoDeRequisicaoDeExames;
    char linha[500];

    arquivoDeRequisicaoDeExames = fopen("requisicao_exames.txt", "r");

    if (arquivoDeRequisicaoDeExames == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("\n--- Requisição de Exames ---\n");
    while (fgets(linha, sizeof(linha), arquivoDeRequisicaoDeExames)) {
        printf("%s", linha);
    }
    fclose(arquivoDeRequisicaoDeExames);
}




