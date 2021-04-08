#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int mult2int(int x, int y){
    int mult=0;
    mult = x * y;
    printf("O valor da multiplicacao e:\n%d\n",mult);
    printf("Quem disse isso foi o filho %d.\n", getpid());
    return mult;
}


int main(void){
    int fd[2];
    int tubo[10]={0};

    pipe(fd);

    int pid = fork();
    if(pid == 0){
        printf("Filho ira ler o tubo:\n");
        for(int i=0; i<10; i++){
            if(read(fd[0], &tubo[i], 1)<0){ 
                printf("Erro na leitura do pipe\n");
            } else {
                printf("Filho leu: %d\n",tubo[i]);
            }
        }
        if(tubo[9]==10){return 0;}
    } else {
        for(int i=0; i<10; i++){
            tubo[i] = i+1;
            printf("Pai vai escrever %d no pipe\n",i+1);
            write(fd[1], &tubo[i], 1);
            sleep(1);
        }
    }
    return 0;
}
