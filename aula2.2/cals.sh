#!/bin/bash

# Cria as variaveis em zero
prd=0
imp=0

# Laço para qualquer entrada
for i in $*
do
    #condicao de separacao de dados entre mes e ano
    if [ $prd -eq 0 ]; then
        mes=$i
        prd=1
    else
        ano=$i
        prd=0
    fi

    imp=$((imp+1)) #Variavel condicional para impressao

    #condicao de imprecao (acada dois loops)
    if [ $imp -eq 2 ]; then
        data=$mes' '$ano
        cal $data
        imp=0
    fi
done


