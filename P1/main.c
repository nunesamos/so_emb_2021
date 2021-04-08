#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define N 20 // 50000 | Funciona para qualquer multiplo de 4. Foi atribuido 20 para a vizualizacao do resultado no printf. :)

double v[N] = {0.0}, X = 2.0; // Criando variaveis tipo double

struct quad  // Struct para argumento dos 4 threads
{
    int position; // Posicao no vetor
    int num; // Quantidade de valores a serem processados
    double v_int[N/4]; // Buffer da struct
};


void* multByX(void* args){
    struct quad* p = (struct quad*)args;
    int init_pos = p->position; // Posicao Inicial
    int max_pos = p->num; // Maxima posicao para o laco

    int var=0;
    
    // For para multiplicacao
    for (int i=0; i<max_pos; i++){
        var = init_pos+i; 
        p->v_int[i] = v[var]*X;
    }

    return NULL;
}

int main(void){

    struct quad thread_args[4]; // Cria 4 variaveis do tipo quad como argumentos do thread
    pthread_t thread_id[4]; // 4 ids para o thread

    // Cria valores double aleatorios de 0 a 10
    srandom(time(NULL));

    printf("Vetor original:"); printf("{");
    for(int i = 0; i<N; i++){
        v[i] = ((double)(random() % 10000))/1000; // Atribui valores aleatorios para v
        printf("%.2f ", v[i]);
    } printf("}\n\n");

    double v_main[N], v_thr[N];
    printf("Vetor da Main:"); printf("{");
    for (int i=0; i<N; i++){
        v_main[i]=v[i]*X; // Atribui valores aleatorios para comparacao
        printf("%.2f ", v_main[i]);
    } printf("}\n\n");

    for (int i=0; i<4; i++){
        thread_args[i].position = i*N/4;
        thread_args[i].num = N/4;
        pthread_create(&thread_id[i], NULL, &multByX, &thread_args[i]);
    }

    int var=0;

    for (int i=0; i<4; i++){
        pthread_join(thread_id[i], NULL);
        for (int j=0; j < N/4; j++){
            var = i*N/4+j;
            v_thr[var]=thread_args[i].v_int[j];
        }
    }

    printf("Vetor do Thread:"); printf("{");
    for (int i=0; i<N; i++){
        printf("%.2f ", v_thr[i]);
    }
    printf("}\n\n");

    return 0;
}
