#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define N 500

float v[N] = {0};

struct quad  
{
    int position;
    int num;
    float media_int;
};


void* media(void* args){
    struct quad* p = (struct quad*)args;
    int init_pos = p->position;
    int max_pos = init_pos+p->num;
    float media_fuc = 0;
    for (int i=init_pos; i<max_pos; i++){
        media_fuc+=v[i]/p->num;
    }
    p->media_int = media_fuc;
    return NULL;
}

int main(void){

    struct quad thread_args[4];
    pthread_t thread_id[4];

    srandom(time(NULL));
    for(int i = 0; i<N; i++){
        v[i] = ((float)random())/10000000;
    }
    float media_main = 0; float media_t = 0;
    for (int i=0; i<N; i++){
        media_main+=v[i]/N;
    }

    for (int i=0; i<4; i++){
        thread_args[i].position = i*N/4;
        thread_args[i].num = N/4;
        pthread_create(&thread_id[i], NULL, &media, &thread_args[i]);
        pthread_join(thread_id[i], NULL);
    }
    media_t = 0;
    for (int i = 0; i < 4; i++){
        media_t+=thread_args[i].media_int/4;
    }
    printf("Media = %f;\nMedia Thread = %f;\n",media_main,media_t);

    return 0;
}
