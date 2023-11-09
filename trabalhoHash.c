/*
IFMT - CAMPUS CUIABÁ - CEL. OCTAYDE JORGE DA SILVA
CUIABÁ, 07 DE NOVEMBRO DE  2023
PROFº João Preti
Alunos: Arthur Confessor e Nicolas Heemann
Curso e Período: Engenharia da Computação - 4º Semestre
Trabalho de Estrutura de dados II
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "log.h"

void main () {
    printf("Ola usuário!!\n\nEste programa lê arquivos do Dicionario Portugues e plota um arquivo no formato .ppm\n\nQuando este arquivo .ppm e convertido para .jpg, gera uma imagem que mostra os locais\ncom maiores colisoes(mais claro) e com menores colisoes(mais escuros)\n\n");
    log_set_level(5);

    //Tabela 1_1
    FILE * hash1_1;
    char *linha1_1;
    hash1_1 = fopen ("ListaDePalavrasPT.txt","r");
    HashStruct1 hashing1_1;
    initHash1(&hashing1_1);
    if (hash1_1){
        linha1_1 = (char*)malloc(sizeof(char) * 100);
        while (fscanf(hash1_1,"%s \n",linha1_1) !=EOF  ){
            put1_1 (&hashing1_1,linha1_1,linha1_1,comparador);
            linha1_1 = (char*)malloc(sizeof(char) * 100);
        }
    }
    fclose (hash1_1);
    

    //Tabela 1_2 
    FILE * hash1_2;
    char *linha1_2;
    hash1_2 = fopen ("ListaDePalavrasPT.txt","r");
    HashStruct2 hashing1_2;
    initHash2(&hashing1_2);
    if (hash1_2){
        linha1_2 = (char*)malloc(sizeof(char) * 100);
        while (fscanf(hash1_2,"%s \n",linha1_2 ) !=EOF  ){
            put1_2 (&hashing1_2,linha1_2,linha1_2,comparador);
            linha1_2 = (char*)malloc(sizeof(char) * 100);
        }
    }
    fclose (hash1_2);

    //Tabela 1_3
    FILE * hash1_3;
    char *linha1_3;
    hash1_3 = fopen ("ListaDePalavrasPT.txt","r");
    HashStruct3 hashing1_3;
    initHash3(&hashing1_3);
    if (hash1_3){
        linha1_3 = (char*)malloc(sizeof(char) * 100);
        while (fscanf(hash1_3,"%s \n",linha1_3 ) !=EOF  ){
            put1_3 (&hashing1_3,linha1_3,linha1_3,comparador);
            linha1_3 = (char*)malloc(sizeof(char) * 100);
        }
    }
    fclose (hash1_3);
    
//----------------------------------------------------------------------------------//

    //Tabela Hash 2_1
    FILE * hash2_1;
    char *linha2_1;
    hash2_1 = fopen ("ListaDePalavrasPT.txt","r");
    HashStruct1 hashing2_1;
    initHash1(&hashing2_1);
    if (hash2_1){
        linha2_1 = (char*)malloc(sizeof(char) * 100);
        while (fscanf(hash2_1,"%s \n",linha2_1 ) !=EOF  ){
            put2_1 (&hashing2_1,linha2_1,linha2_1,comparador);
            linha2_1 = (char*)malloc(sizeof(char) * 100);
        }
    }
    fclose (hash2_1);

    //Tabela Hash 2_2
    FILE * hash2_2;
    char *linha2_2;
    hash2_2 = fopen ("ListaDePalavrasPT.txt","r");
    HashStruct2 hashing2_2;
    initHash2(&hashing2_2);
    if (hash2_2){
        linha2_2 = (char*)malloc(sizeof(char) * 100);
        while (fscanf(hash2_2,"%s \n",linha2_2 ) !=EOF  ){
            put2_2 (&hashing2_2,linha2_2,linha2_2,comparador);
            linha2_2 = (char*)malloc(sizeof(char) * 100);
        }
    }
    fclose (hash2_2);

    //Tabela Hash 2_3
    FILE * hash2_3;
    char *linha2_3;
    hash2_3 = fopen ("ListaDePalavrasPT.txt","r");
    HashStruct3 hashing2_3;
    initHash3(&hashing2_3);
    if (hash2_3){
        linha2_3 = (char*)malloc(sizeof(char) * 100);
        while (fscanf(hash2_3,"%s \n",linha2_3 ) !=EOF  ){
            put2_3 (&hashing2_3,linha2_3,linha2_3,comparador);
            linha2_3 = (char*)malloc(sizeof(char) * 100);
        }
    }

    //Tabelas 1
    graficoEspalhamento1(&hashing1_1, "TabelaHash1_1024.ppm");//Plota o gráfico de espalhamento da Tabela Hash 1 de tamanho 1024
    graficoEspalhamento2(&hashing1_2, "TabelaHash1_512.ppm");//Plota o gráfico de espalhamento da Tabela Hash 1 de tamanho 512
    graficoEspalhamento3(&hashing1_3, "TabelaHash1_256.ppm");//Plota o gráfico de espalhamento da Tabela Hash 1 de tamanho 256

    //Tabelas 2
    graficoEspalhamento1(&hashing2_1, "TabelaHash2_1024.ppm");//Plota o gráfico de espalhamento da Tabela Hash 2 de tamanho 1024
    graficoEspalhamento2(&hashing2_2, "TabelaHash2_512.ppm");//Plota o gráfico de espalhamento da Tabela Hash 2 de tamanho 512
    graficoEspalhamento3(&hashing2_3, "TabelaHash2_256.ppm");//Plota o gráfico de espalhamento da Tabela Hash 2 de tamanho 256

    fclose (hash2_3);
}

//Anotação: Professor, o melhor Gráfico de espalhamento é o TabelaHash2_1.ppm, no qual o tamanho é de 1024 e o hash escolhido é o 2.