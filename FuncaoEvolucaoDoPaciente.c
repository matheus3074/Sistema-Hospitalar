#include <stdio.h>

void documentoDeEvolucaoDoPaciente (){
    FILE *arquivoDaEvolucaoDoPaciente; // Declaração de ponteiro de arquivo
    char nomePaciente[100], nomeMedico[100], idade[20],crm[20], diagnostico[1000], leito[5], sexo[10], diaMesAno[10];
    

    arquivoDaEvolucaoDoPaciente = fopen("Evolucao_do_paciente.txt", "w");

    if (arquivoDaEvolucaoDoPaciente == NULL) {
        printf("Erro ao abrir o arquivo!");
        return 1;
    }else {
         // Solicitando informações ao usuário
        printf("Digite o nome do paciente: ");
        fgets(nomePaciente, sizeof(nomePaciente), stdin);

        printf("Digite o gênero do paciente: ");
        fgets(sexo, sizeof(sexo), stdin);

        fflush(stdin);
        
        printf("Digite o nome do médico responsável: ");
        fgets(nomeMedico, sizeof(nomeMedico), stdin);
        
        printf("Digite o CRM do médico: ");
        fgets(crm, sizeof(crm), stdin);
        
        printf("Escreva o diagnostico do paciente: ");
        fgets(diagnostico, sizeof(diagnostico), stdin);

        printf("Digite a data da requisição: ");
        fgets(diaMesAno, sizeof(diaMesAno), stdin);

        fprintf(arquivoDaEvolucaoDoPaciente, "--- Evolução do paciente ---\n");       

        fprintf(arquivoDaEvolucaoDoPaciente, "Paciente: %s Idade: %s Leito: %s Sexo: %s ", nomePaciente, idade, leito ,sexo);

        fprintf(arquivoDaEvolucaoDoPaciente, "Médico Responsável: %s CRM: %s Diagnostico: %s Data da Requisição: %s", nomeMedico, crm, diagnostico, diaMesAno);
    
        fprintf(arquivoDaEvolucaoDoPaciente, "--- Fim do Documento ---");
    
        fclose(arquivoDaEvolucaoDoPaciente);
    
        printf("Documento de evolução do paciente criado com sucesso!");
    
        return 0;
    }

}