#include "evolucao_paciente.h"
#include <stdio.h>
#include <stdlib.h> 

void documentoDeEvolucaoDoPaciente() {
    FILE *arquivoDaEvolucaoDoPaciente;
    char nomePaciente[100], nomeMedico[100], crm[20], diagnostico[1000], sexo[10], diaMesAno[10];

    arquivoDaEvolucaoDoPaciente = fopen("Evolucao_do_paciente.txt", "w");

    if (arquivoDaEvolucaoDoPaciente == NULL) {
        printf("\tErro ao abrir o arquivo de evoluao do paciente!\n");
        return;
    }
    
    printf("\tDigite o nome do paciente: ");
    fgets(nomePaciente, sizeof(nomePaciente), stdin);
    fflush(stdin);

    printf("\tDigite o genero do paciente: ");
    fgets(sexo, sizeof(sexo), stdin);
    fflush(stdin);

    printf("\tDigite o nome do medico responsavel: ");
    fgets(nomeMedico, sizeof(nomeMedico), stdin);
    fflush(stdin); 

    printf("\tDigite o CRM do medico: ");
    fgets(crm, sizeof(crm), stdin);
    fflush(stdin); 

    printf("\tEscreva o diagnostico do paciente: ");
    fgets(diagnostico, sizeof(diagnostico), stdin);
    fflush(stdin);

    printf("\tDigite a data da requisicao: ");
    fgets(diaMesAno, sizeof(diaMesAno), stdin);
    fflush(stdin);

    fprintf(arquivoDaEvolucaoDoPaciente, "--- Evolução do paciente ---\n");
    fprintf(arquivoDaEvolucaoDoPaciente, "Paciente: %sSexo: %s", nomePaciente, sexo);
    fprintf(arquivoDaEvolucaoDoPaciente, "Medico Responsavel: %sCRM: %sDiagnóstico: %sData da Requisicao: %s", nomeMedico, crm, diagnostico, diaMesAno);
    fprintf(arquivoDaEvolucaoDoPaciente, "--- Fim do Documento ---");

    fclose(arquivoDaEvolucaoDoPaciente);

    printf("\tDocumento de evolucao do paciente criado com sucesso!\n");
}

void documentoDeAltaDoPaciente() {
    FILE *arquivoDeAltaDoPaciente;
    char nomePaciente[100], nomeMedico[100], crm[20], data[10], horario[5], clinica[100];

    arquivoDeAltaDoPaciente = fopen("Alta_do_paciente.txt", "w");

    if (arquivoDeAltaDoPaciente == NULL) {
        printf("\tErro ao abrir o arquivo de alta do paciente!\n");
        return;
    }
    
    printf("\tDigite o nome do paciente: ");
    fgets(nomePaciente, sizeof(nomePaciente), stdin);
    fflush(stdin);

    printf("\tDigite o nome do medico responsavel: ");
    fgets(nomeMedico, sizeof(nomeMedico), stdin);
     fflush(stdin);

    printf("\tDigite o CRM do medico: ");
    fgets(crm, sizeof(crm), stdin);
    fflush(stdin);

    printf("\tDigite a data da requisicao: ");
    fgets(data, sizeof(data), stdin);
    fflush(stdin);

    printf("\tDigite o horario do boletim: ");
    fgets(horario, sizeof(horario), stdin);
    fflush(stdin);

    printf("\tEscreva o nome da clinica: ");
    fgets(clinica, sizeof(clinica), stdin);
    fflush(stdin);

    fprintf(arquivoDeAltaDoPaciente, "--- Boletim medico ---\n\n");
    fprintf(arquivoDeAltaDoPaciente, "Data: %s\n", data);
    fprintf(arquivoDeAltaDoPaciente, "Horario: %s\n", horario);
    fprintf(arquivoDeAltaDoPaciente, "Paciente: %s", nomePaciente);
    fprintf(arquivoDeAltaDoPaciente, "O Hospital %s informa que o paciente recebeu alta da UTI nesta sexta-feira (28), pela manha. O paciente realizou nova ressonância magnetica de cranio com contraste, que resultou normal. Como diagnóstico final permanece Acidente Isquemico Transitorio (ATT).\n", clinica);
    fprintf(arquivoDeAltaDoPaciente, "Medico Responsavel: %s CRM: %s", nomeMedico, crm);

    fclose(arquivoDeAltaDoPaciente);

    printf("\tDocumento de alta do paciente criado com sucesso!\n");
}

void requisicaoDeExames() {
    FILE *arquivo;
    char nomePaciente[100], dataNascimento[20], genero[20], nomeMedico[100], crm[20], observacoes[500], dataRequisicao[20];

    arquivo = fopen("requisicao_exames.txt", "w");

    if (arquivo == NULL) {
        printf("\tErro ao abrir o arquivo de requisicao de exames!\n");
        return;
    }

    printf("\tDigite o nome do paciente: ");
    fgets(nomePaciente, sizeof(nomePaciente), stdin);
    fflush(stdin);

    printf("\tDigite a data de nascimento do paciente: ");
    fgets(dataNascimento, sizeof(dataNascimento), stdin);
    fflush(stdin);

    printf("\tDigite o genero do paciente: ");
    fgets(genero, sizeof(genero), stdin);
    fflush(stdin);

    printf("\tDigite o nome do medico responsavel: ");
    fgets(nomeMedico, sizeof(nomeMedico), stdin);
    fflush(stdin);

    printf("\tDigite o CRM do medico: ");
    fgets(crm, sizeof(crm), stdin);
    fflush(stdin);

    printf("\tDigite observacoes (se houver): ");
    fgets(observacoes, sizeof(observacoes), stdin);
    fflush(stdin);

    printf("\tDigite a data da requisicao: ");
    fgets(dataRequisicao, sizeof(dataRequisicao), stdin);
   fflush(stdin);
   
	fprintf(arquivo, "--- Requisicao de Exames ---\n");
    fprintf(arquivo, "Paciente: %s", nomePaciente);
    fprintf(arquivo, "Data de Nascimento: %s", dataNascimento);
    fprintf(arquivo, "Genero: %s", genero);
    fprintf(arquivo, "Medico Responsavel: %s", nomeMedico);
    fprintf(arquivo, "CRM: %s", crm);
    fprintf(arquivo, "Observacoes: %s", observacoes);
    fprintf(arquivo, "Data da Requisicao: %s", dataRequisicao);
    fprintf(arquivo, "--- Fim do Documento ---");

    fclose(arquivo);

    printf("\tDocumento de requisicao de exames criado com sucesso!\n");
}