#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}

int main(int argc, char **argv){

    for (int i = 0; i<3; i++){
        pid_t pid_filho = fork();
        if(pid_filho == 0){
            printf("Filho %d vai executar seu processo\n", getpid());
            usleep(100);
            Incrementa_Variavel_Global(getpid());
            return 0;
        } else {
            printf("O pai ira esperar o filho %d para encerrar.\n", i+1);
            wait(NULL);
        }
    } 
    printf("Fim do processo pai\n");
    return 0;
}