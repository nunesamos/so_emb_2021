#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int numero[10] = {0};

void* cont_10 (void* num){
    for (int i=1; i<11; i++){
        printf("O secundario ira esperar 1 segundo e printar o valor armazenado na memoria em numero[%d]\n",i);
        usleep(900000);
        printf("O valor recebido e: %d\n",numero[i-1]);
    }
    return NULL;
}

int main(void){

    pthread_t thread1_id;
    pthread_create(&thread1_id, NULL, &cont_10, NULL);
    for (int i=1; i<11; i++){
        numero[i-1]=i; 
    printf("O principal ira mandar o numero %d e esperar 1 segundo\n", i);
    sleep(1);   
    }
    sleep(1);
    return 0;
}
