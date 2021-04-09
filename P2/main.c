#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <math.h>
#include <wiringPi.h>

#define LED 7
#define BUTTON 12

void blink_duty(int pin, int duty, int freq){
    // Funcao gera PWM
    digitalWrite(pin, HIGH);
    usleep(freq-duty); // Meio Ciclo ligado
    digitalWrite(pin, LOW);
    usleep(duty); // Meio Ciclo desligado
}

void f_crash(){
    // Funcao para encerrar os processos
    puts("O pai mandara o filho terminar e ira encerrar");
    exit(1);
}

int main(void){
    // Pipe para comunicacao entre processos. O pai irá controlar a quantidade de vezes que o botao foi 
    // precionado e o filho ira controlar o PWM, semelhante ao exercicio 3 de GPIO.
    int fd[2];
    pipe(fd);
    int pid;
    pid = fork();

    if(pid == 0){
        // Processo filho
        wiringPiSetup();
        pinMode(LED, OUTPUT);
        char buffer_f[1];
        int duty, freq = 20; // ~5Hz
        while(1){
            // Void Loop
            if(read(fd[0], buffer_f, 1) < 0){
                puts("Erro na leitura do Pipe"); 
                return 0;
            }
            if(buffer_f == "\n"){
                puts("Adeus!");
                return 0;
            }
            duty = (int) (20 - 4 * (buffer_f-"0"))/2;
            blink_duty(LED, duty, (int) freq/2);
        }
    } else {
        // Processo pai
        signal(SIGINT, f_crash);
        wiringPiSetup();
        pinMode(BUTTON, INPUT);
        char buffer_p[1]="0";
        int cont=0;
        puts("Pressione Ctrl+C para encerrar");
        while (1){
            // void loop
            while(digitalRead(BUTTON));
            while(digitalRead(BUTTON)==0);
            if (cont>5) {
                cont=0;
            } else {
                cont++;
            }
            strcpy (buffer_p, cont+"0");
            if(write(fd[1], buffer_p, 1)<0){
                puts("Erro na escrita do Pipe"); 
                return 0;
            }
        }
        // Pai manda comando para encerrar o Filho e finaliza.
        strcpy (buffer_p, "\n");
        write(fd[1], buffer_p, 1)<0;
    }
   
    return 0;
}
