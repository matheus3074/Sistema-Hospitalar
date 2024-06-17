#include <stdio.h>

int main() {
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