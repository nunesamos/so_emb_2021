#include <stdio.h>
#include "mostra.h"

void mostra_dado(int N, char **argv)
{
    int i = 0;
    // printf("teste2\n");
    for (i; i < N; i++){
        printf("%s\n",argv[i]);
       // printf("%d",i);
    }
}