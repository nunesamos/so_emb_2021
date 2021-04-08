#include <stdio.h>

int i=0;

int main(int argc, char **argv){
    if (argc<=1){
        printf("Voce nao digitou nenhum argumento!");
        return 0;
    } else{
        for(i=1; i<argc; i++){
        printf("Ola %s\n",argv[i]);
    }
    }
    return 0;
}