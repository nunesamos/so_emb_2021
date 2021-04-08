#include <stdio.h>
#include <stdlib.h>
#include "escreve_txt.h"


int main(int argc, char **argv){
    if (argc!=3) {
        printf("Por favor digite 2 argumentos\n");
        return 0;
    }
    int idade = atoi(argv[2]);
    escreve_nome(argv[1], idade);
    return 0;
}