#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    int fd[2];
    char cambio[90]={0};

    pipe(fd);

    int pid = fork();

    if(pid == 0){
        if(read(fd[0], cambio, 90)<0){ 
            printf("Erro na leitura do pipe\n");
        } else {
            printf("FILHO: %s\n",cambio);
        }
        usleep(500);
        strcpy(cambio, "Não façais nada violento, praticai somente aquilo que é justo e equilibrado.");
        if(write(fd[1], cambio, 90)<0){ 
            printf("Erro na escrita do pipe\n");
        } 
        usleep(500);
        if(read(fd[0], cambio, 90)<0){ 
            printf("Erro na leitura do pipe\n");
        } else {
            printf("FILHO: %s\n",cambio);
        }
        usleep(500);
        strcpy(cambio, "Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...");
        if(write(fd[1], cambio, 90)<0){ 
            printf("Erro na escrita do pipe\n");
        } 
    } else {
        strcpy(cambio, "Pai, qual é a verdadeira essência da sabedoria?");
        if(write(fd[1], cambio, 90)<0){ 
            printf("Erro na escrita do pipe\n");
        } 
        usleep(500);
        if(read(fd[0], cambio, 90)<0){ 
            printf("Erro na leitura do pipe\n");
        } else {
            printf("PAI: %s\n",cambio);
        }
        usleep(500);
        strcpy(cambio, "Mas até uma criança de três anos sabe disso!");
        if(write(fd[1], cambio, 90)<0){ 
            printf("Erro na escrita do pipe\n");
        } 
        usleep(500);
        if(read(fd[0], cambio, 90)<0){ 
            printf("Erro na leitura do pipe\n");
        } else {
            printf("PAI: %s\n",cambio);
        }
    }
    return 0;
}
