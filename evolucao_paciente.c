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
