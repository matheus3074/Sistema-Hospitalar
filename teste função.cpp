#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int qtdFuncionarios = 50;

int matriculaFuncionario() {
    int matricula;
    matricula = rand() % qtdFuncionarios * 100;

    return matricula;
}
void cadastroFuncionarios() {

}
void recursosHumanos() {

}

int main() {
    int matricula;
    
	//matriculaFuncionario();
	
    matricula = matriculaFuncionario();

    printf("%d", matricula);
}