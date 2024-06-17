#include "evolucao_paciente.h"
#include <stdio.h>
#include <stdlib.h> 



void documentoDeEvolucaoDoPaciente() {
    FILE *arquivoDaEvolucaoDoPaciente;
    char nomePaciente[100], nomeMedico[100], crm[20], diagnostico[1000], sexo[10], diaMesAno[10];

    arquivoDaEvolucaoDoPaciente = fopen("Evolucao_do_paciente.txt", "w");

    if (arquivoDaEvolucaoDoPaciente == NULL) {
        printf("Erro ao abrir o arquivo de evolução do paciente!\n");
        return;
    }

    
    printf("Digite o nome do paciente: ");
    fgets(nomePaciente, sizeof(nomePaciente), stdin);
    fflush(stdin);

    printf("Digite o gênero do paciente: ");
    fgets(sexo, sizeof(sexo), stdin);
    fflush(stdin);

    printf("Digite o nome do médico responsável: ");
    fgets(nomeMedico, sizeof(nomeMedico), stdin);
    fflush(stdin); 

    printf("Digite o CRM do médico: ");
    fgets(crm, sizeof(crm), stdin);
    fflush(stdin); 

    printf("Escreva o diagnóstico do paciente: ");
    fgets(diagnostico, sizeof(diagnostico), stdin);
    fflush(stdin);

    printf("Digite a data da requisição: ");
    fgets(diaMesAno, sizeof(diaMesAno), stdin);
    fflush(stdin);

    fprintf(arquivoDaEvolucaoDoPaciente, "--- Evolução do paciente ---\n");
    fprintf(arquivoDaEvolucaoDoPaciente, "Paciente: %sSexo: %s", nomePaciente, sexo);
    fprintf(arquivoDaEvolucaoDoPaciente, "Médico Responsável: %sCRM: %sDiagnóstico: %sData da Requisição: %s", nomeMedico, crm, diagnostico, diaMesAno);
    fprintf(arquivoDaEvolucaoDoPaciente, "--- Fim do Documento ---");

    fclose(arquivoDaEvolucaoDoPaciente);

    printf("Documento de evolução do paciente criado com sucesso!\n");
}

void documentoDeAltaDoPaciente() {
    FILE *arquivoDeAltaDoPaciente;
    char nomePaciente[100], nomeMedico[100], crm[20], data[10], horario[5], clinica[100];

    arquivoDeAltaDoPaciente = fopen("Alta_do_paciente.txt", "w");

    if (arquivoDeAltaDoPaciente == NULL) {
        printf("Erro ao abrir o arquivo de alta do paciente!\n");
        return;
    }

    
    printf("Digite o nome do paciente: ");
    fgets(nomePaciente, sizeof(nomePaciente), stdin);
    fflush(stdin);

    printf("Digite o nome do médico responsável: ");
    fgets(nomeMedico, sizeof(nomeMedico), stdin);
     fflush(stdin);

    printf("Digite o CRM do médico: ");
    fgets(crm, sizeof(crm), stdin);
    fflush(stdin);

    printf("Digite a data da requisição: ");
    fgets(data, sizeof(data), stdin);
    fflush(stdin);

    printf("Digite o horário do boletim: ");
    fgets(horario, sizeof(horario), stdin);
    fflush(stdin);

    printf("Escreva o nome da clínica: ");
    fgets(clinica, sizeof(clinica), stdin);
    fflush(stdin);

    fprintf(arquivoDeAltaDoPaciente, "--- Boletim médico ---\n\n");
    fprintf(arquivoDeAltaDoPaciente, "Data: %s\n", data);
    fprintf(arquivoDeAltaDoPaciente, "Horário: %s\n", horario);
    fprintf(arquivoDeAltaDoPaciente, "Paciente: %s", nomePaciente);
    fprintf(arquivoDeAltaDoPaciente, "O Hospital %s informa que o paciente recebeu alta da UTI nesta sexta-feira (28), pela manhã. O paciente realizou nova ressonância magnética de crânio com contraste, que resultou normal. Como diagnóstico final permanece Acidente Isquêmico Transitório (ATT).\n", clinica);
    fprintf(arquivoDeAltaDoPaciente, "Médico Responsável: %s CRM: %s", nomeMedico, crm);

    fclose(arquivoDeAltaDoPaciente);

    printf("Documento de alta do paciente criado com sucesso!\n");
}

void requisicaoDeExames() {
    FILE *arquivo;
    char nomePaciente[100], dataNascimento[20], genero[20], nomeMedico[100], crm[20], observacoes[500], dataRequisicao[20];

    arquivo = fopen("requisicao_exames.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de requisição de exames!\n");
        return;
    }

    // Solicitando informações ao usuário
    printf("Digite o nome do paciente: ");
    fgets(nomePaciente, sizeof(nomePaciente), stdin);
    fflush(stdin);

    printf("Digite a data de nascimento do paciente: ");
    fgets(dataNascimento, sizeof(dataNascimento), stdin);
    fflush(stdin);

    printf("Digite o gênero do paciente: ");
    fgets(genero, sizeof(genero), stdin);
    fflush(stdin);

    printf("Digite o nome do médico responsável: ");
    fgets(nomeMedico, sizeof(nomeMedico), stdin);
    fflush(stdin);

    printf("Digite o CRM do médico: ");
    fgets(crm, sizeof(crm), stdin);
    fflush(stdin);

    printf("Digite observações (se houver): ");
    fgets(observacoes, sizeof(observacoes), stdin);
    fflush(stdin);

    printf("Digite a data da requisição: ");
    fgets(dataRequisicao, sizeof(dataRequisicao), stdin);
   fflush(stdin);
   
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

    printf("Documento de requisição de exames criado com sucesso!\n");
}

