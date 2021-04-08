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
    printf("O pai ira perguntar a tabuada do 2 para seus 3 filhos.\n\n");
    int pid_Pai = getpid();
    int A=7, B=8, C=5;
    pid_t pid_filhoA = 0, pid_filhoB = 0, pid_filhoC = 0;
    pid_filhoA = fork();
    if (pid_filhoA==0){
        pid_filhoB = fork();
        if (pid_filhoB == 0){
            pid_filhoC = fork();
        }
    }

    if(getpid()==pid_Pai+1){
        printf("Filho %d quanto e 2 vezes %d?\n",getpid(), A);
        if(mult2int(2, A)==14){
            printf("Parabens filho, voce acertou!\n\n");
        }else{printf("Voce precisa estudar mais!\n\n");}
    }else if(getpid()==pid_Pai+2){
        sleep(1);
        printf("Filho %d quanto e 2 vezes %d?\n",getpid(), B);
        if(mult2int(2, B)==16){
            printf("Parabens filho, voce acertou!\n\n");
        }else{printf("Voce precisa estudar mais!\n\n");}      
    }else if(getpid()==pid_Pai+3){
        sleep(2);
        printf("Filho %d quanto e 2 vezes %d?\n",getpid(), C);
        if(mult2int(2, C)==10){
            printf("Parabens filho, voce acertou!\n\n");
        }else{printf("Voce precisa estudar mais!\n\n");}
    }else{
        sleep(3);  
        printf("O pai satisfeito disse:\n");
        printf("Fim do teste! :)\n");
        return(0);
    }
}
