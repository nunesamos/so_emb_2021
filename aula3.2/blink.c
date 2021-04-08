#include <stdlib.h>
#include <string.h>
#include "blink.h"


void blink_duty(int pin, int duty){
    wiringPiSetup();
    pinMode(pin, HIGH);
    puts("Pressione Ctrl+C para encerrar");
    while (1){
        digitalWrite(pin, HIGH);
        usleep(duty);
        digitalWrite(pin, LOW);
    }
}

int main(void){

    blink_duty(7, 1000)

    return 0;
}