#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <math.h>
#include <wiringPi.h>


#define LED 7
#define BUTTON 12

void blink_duty(int pin, int duty){
    digitalWrite(pin, HIGH);
    usleep(duty);
    digitalWrite(pin, LOW);
}

void f_crash(){
    puts("O pai mandara o filho terminar e ira encerrar");
    exit(1);
}

int main(void){
    int fd[2];
    pipe(fd);
    int pid;
    pid = fork();

    if(pid == 0){
        wiringPiSetup();
        pinMode(LED, OUTPUT);
        char buffer_f[1];
        int duty=1024; // ~1Hz
        while(1){
            if(read(fd[0], buffer_f, 1) < 0){
                puts("Erro na leitura do Pipe"); 
                return 0;
            }
            if(buffer_f == "\n"){
                puts("Adeus!");
                return 0;
            }
            duty = (int) (1024 / (pow(2, buffer_f-"0")));
            blink_duty(LED, duty);
        }
    } else {
        signal(SIGINT, f_crash);
        wiringPiSetup();
        pinMode(BUTTON, INPUT);
        char buffer_p[1]="0";
        int cont=0;
        puts("Pressione Ctrl+C para encerrar");
        while (1){
            while(digitalRead(BUTTON));
            while(digitalRead(BUTTON)==0);
            if (cont==6) {
                cont=0;
            } else {
                cont++;
            }
            buffer_p[] = cont+"0";
            if(write(fd[1], buffer_p, 1)<0){
                puts("Erro na escrita do Pipe"); 
                return 0;
            }
        }
        buffer_p[] = "\n";
        write(fd[1], buffer_p, 1)<0;
    }
   
    return 0;
}
