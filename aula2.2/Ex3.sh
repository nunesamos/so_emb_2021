#!/bin/bash

while read linha; do
    wget "$linha"
done < "$1"

echo "Arquivos Baixados! :)"