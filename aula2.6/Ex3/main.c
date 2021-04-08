#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int i = 0;

void cria_proc(char **lista_arg){
    execvp(lista_arg[0], lista_arg);
}

int main(int argc, char **argv){


    for (int i = 1; i<argc; i++){
        char * lista_arg[] = {argv[i], NULL};
        pid_t pid_filho = fork();
        if(pid_filho == 0){
            printf("Filho %d vai executar seu processo\n", getpid());
            usleep(100);
            cria_proc(lista_arg);
            return 0;
        } else {
            printf("O pai ira esperar o filho %d para encerrar.\n", i);
            wait(NULL);
        }
    } 
    printf("Fim do processo pai\n");
    return 0;
}