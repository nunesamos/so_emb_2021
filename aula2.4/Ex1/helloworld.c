#include <stdlib.h>
#include <string.h>
#include "helloworld.h"

void ola(void){
    FILE *fp;
    fp = fopen("ola_mundo.txt", "w");
    if(fp==NULL){
        printf("Erro na abertura do arquivo\n");
    }
    printf("Arquivo aberto com sucesso\n");
    fprintf(fp, "Ola mundo!\n");
    fclose(fp);
}