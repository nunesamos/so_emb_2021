#include <stdio.h>
#include "escreve_txt.h"

char nome[100];
int idade=0;

int main(void){
    printf("Digite o seu nome: ");
    scanf("%s",nome);
    printf("Digite a sua idade: ");
    scanf("%d",&idade);
    escreve_nome(nome, idade);
    return 0;
}
