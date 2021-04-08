#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int i = 0;

int main(int argc, char **argv){

    for (i=1;i<argc;i++){
        system(argv[i]);
    }
    
    return 0;
}