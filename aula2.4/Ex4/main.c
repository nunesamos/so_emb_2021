#include <stdio.h>
#include <stdlib.h>
#include "find_txt.h"


int main(int argc, char **argv){
    if (argc!=3) {
        printf("Por favor digite 2 argumentos\n");
        return 0;
    }
    
    busca_acha(argv[1], argv[2]);
    
    return 0;
}