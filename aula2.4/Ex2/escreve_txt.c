#include <stdlib.h>
#include <string.h>
#include "escreve_txt.h"


void erro_fopen(FILE *fp){
    if(fp==NULL){
        printf("Erro na Abertura do arquivo.\n");
        printf("Fim de programa. :(");
        exit(-1);
    } else {
        printf("Arquivo aberto com sucesso\n");
    }
}

void escreve_nome(char *nome, int idade){
    char aux[100];
    strncpy(aux, nome, strlen(nome));
    FILE *fp;
    fp = fopen(strcat(nome, ".txt"), "w");
    erro_fopen(fp);
    fprintf(fp, "Seu nome e: %s\n", aux);
    fprintf(fp, "Sua idade e: %d anos\n", idade);
    fclose(fp);
}

void escreve_idade(int idade){

}