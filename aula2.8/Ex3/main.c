#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define N 500

long int v[N] = {0};

struct quad  
{
    int position;
    int num;
    long int v_max_int;
};


void* max(void* args){
    struct quad* p = (struct quad*)args;
    int init_pos = p->position;
    int max_pos = init_pos+p->num;
    long int v_max = v[init_pos];
    for (int i=init_pos; i<max_pos; i++){
        if (v_max < v[i]){v_max=v[i];}
    }
    p->v_max_int = v_max;
    return NULL;
}

int main(void){

    struct quad thread_args[4];
    pthread_t thread_id[4];

    srandom(time(NULL));
    for(int i = 0; i<N; i++){
        v[i] = random();
    }
    long int v_max = v[0], v_max_t;
    for (int i=0; i<N; i++){
        if (v_max < v[i]){v_max=v[i];}
    }

    for (int i=0; i<4; i++){
        thread_args[i].position = i*N/4;
        thread_args[i].num = N/4;
        pthread_create(&thread_id[i], NULL, &max, &thread_args[i]);
        pthread_join(thread_id[i], NULL);
    }

    v_max_t = thread_args[0].v_max_int;
    for (int i = 1; i < 4; i++){
        if(v_max_t<thread_args[i].v_max_int){v_max_t = thread_args[i].v_max_int;}
    }
    
    printf("Max = %d;\nMax Thread = %d;\n",v_max,v_max_t);

    return 0;
}
