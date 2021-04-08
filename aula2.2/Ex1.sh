#!/bin/bash
echo Exercicio 01 Aula 2.2
echo Criando vários arquivos .txt

mkdir test_from_Ex1

cd ./test_from_Ex1

for i in {1..3}
do
echo Numero do arquivo = $i > teste$i.txt
done

cd ../

echo Fim =D 