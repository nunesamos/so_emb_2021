#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "find_txt.h"


void erro_fopen(FILE *fp){
    if(fp==NULL){
        printf("Erro na Abertura do arquivo.\n");
        printf("Fim de programa. :(\n");
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

void separa_frase(char *frase, char *palavra){
    int i=0, j=0, k=0;
    char palavras[50][30];
    int cont=0;
    char nulo[1] = "\0";
    for (i=0;i<50;i++){for(j=0;j<30;j++){palavras[i][j]=nulo[0];}}

    j=0;

    for (i=0;i<strlen(frase);i++){
        if (isspace(frase[i])){
            j=0;
            k=k+1;
        }else{
            palavras[k][j]=frase[i];
            j=j+1;
        }
    }

    for (i=0; i<50; i++){
        if (!strcmp(palavras[i], palavra)){
            cont=cont+1;
        }
    }
    printf("A palavra \"%s\" ocorre %d vezes ao longo do texto.\n", palavra, cont);
}

void busca_acha(char *palavra, char *arquivo){
    char linha[1024];
    int i=0;
    FILE *fp;
    fp = fopen(arquivo, "r");
    erro_fopen(fp);
    while(fgets(linha, sizeof(linha), fp) != NULL) {
        printf("\nO texto escrito no documento [%s] e:\n - %s\n", arquivo, linha);
    }
    separa_frase(linha, palavra);

}