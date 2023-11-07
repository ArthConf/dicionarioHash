#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "log.h"

void initHash1(HashStruct1 *hashStruct) {
    log_trace("Entrando em initHash");
    for (int i=0;i<MAX;i++) {
        //chamando init de DoublyLinkedList para inicializar cada lista do vetor
        log_debug("Inicializando Lista do Hash %d", i);
        init(&(hashStruct->hashes[i]));
    }
    hashStruct->size = 0;
    log_trace("Saindo de initHash");
}

void initHash2(HashStruct2 *hashStruct) {
    log_trace("Entrando em initHash");
    for (int i=0;i<MAX2;i++) {
        //chamando init de DoublyLinkedList para inicializar cada lista do vetor
        log_debug("Inicializando Lista do Hash %d", i);
        init(&(hashStruct->hashes[i]));
    }
    hashStruct->size = 0;
    log_trace("Saindo de initHash");
}

void initHash3(HashStruct3 *hashStruct) {
    log_trace("Entrando em initHash");
    for (int i=0;i<MAX3;i++) {
        //chamando init de DoublyLinkedList para inicializar cada lista do vetor
        log_debug("Inicializando Lista do Hash %d", i);
        init(&(hashStruct->hashes[i]));
    }
    hashStruct->size = 0;
    log_trace("Saindo de initHash");
}


bool comparador(void* data_1,void* data_2){
    if(strcmp (data_1,data_2)==0) return true;
    else return false;
}

int hash1_1(char *key) {
    log_trace("Entrando em hash");
    int sum = 0;
    // percorremos todos os caracteres da string passada
    for (int i = 0; key[i]!=0;i++) {
         //acumulamos os códigos ascii de cada letra com um peso
        sum+=key[i]*(i+1);
    }
    log_debug("key: %s", key);
    log_debug("sum: %d", sum);
    int hashvalue = sum%MAX;
    log_debug("Hash: %d", hashvalue);
    log_trace("Saindo de hash");
    return hashvalue; //retorna o resto da divisão
}
int hash1_2(char *key) {
    log_trace("Entrando em hash");
    int sum = 0;
    // percorremos todos os caracteres da string passada
    for (int i = 0; key[i]!=0;i++) {
         //acumulamos os códigos ascii de cada letra com um peso
        sum+=key[i]*(i+1);
    }
    log_debug("key: %s", key);
    log_debug("sum: %d", sum);
    int hashvalue = sum%MAX2;
    log_debug("Hash: %d", hashvalue);
    log_trace("Saindo de hash");
    return hashvalue; //retorna o resto da divisão
}

int hash1_3(char *key) {
    log_trace("Entrando em hash");
    int sum = 0;
    // percorremos todos os caracteres da string passada
    for (int i = 0; key[i]!=0;i++) {
         //acumulamos os códigos ascii de cada letra com um peso
        sum+=key[i]*(i+1);
    }
    log_debug("key: %s", key);
    log_debug("sum: %d", sum);
    int hashvalue = sum%MAX3;
    log_debug("Hash: %d", hashvalue);
    log_trace("Saindo de hash");
    return hashvalue; //retorna o resto da divisão
}

int put1_1(HashStruct1 *hashStruct, char *key, void *data, compare equal)  {
    log_trace("Entrando em put");
    log_info("Adicionando novo elemento no Hash");
    if (!containsKey1_1(hashStruct, key, equal)) {
        //adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash1_1(key)],data);
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }
    log_trace("Saindo de put");
    return 0;
}

int put1_2(HashStruct2 *hashStruct, char *key, void *data, compare equal)  {
    log_trace("Entrando em put");
    log_info("Adicionando novo elemento no Hash");
    if (!containsKey1_2(hashStruct, key, equal)) {
        //adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash1_2(key)],data);
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }
    log_trace("Saindo de put");
    return 0;
}

int put1_3(HashStruct3 *hashStruct, char *key, void *data, compare equal)  {
    log_trace("Entrando em put");
    log_info("Adicionando novo elemento no Hash");
    if (!containsKey1_3(hashStruct, key, equal)) {
        //adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash1_3(key)],data);
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }
    log_trace("Saindo de put");
    return 0;
}

bool containsKey1_1(HashStruct1 *hashStruct, char *key, compare equal) {
    log_trace("Entrando em containsKey");
    //calcula a posição
    int hashValue = hash1_1(key);
    //busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal); 
    log_trace("Saindo de containsKey");
    return (pos!=-1)?true:false;
}

bool containsKey1_2(HashStruct2 *hashStruct, char *key, compare equal) {
    log_trace("Entrando em containsKey");
    //calcula a posição
    int hashValue = hash1_2(key);
    //busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal); 
    log_trace("Saindo de containsKey");
    return (pos!=-1)?true:false;
}

bool containsKey1_3(HashStruct3 *hashStruct, char *key, compare equal) {
    log_trace("Entrando em containsKey");
    //calcula a posição
    int hashValue = hash1_3(key);
    //busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal); 
    log_trace("Saindo de containsKey");
    return (pos!=-1)?true:false;
}
//---------------------------------------------------------------------------

//Função Hash 2
int put2_1(HashStruct1 *hashStruct, char *key, void *data, compare equal)  {
    log_trace("Entrando em put_2");
    log_info("Adicionando novo elemento no Hash");
    if (!containsKey2_1(hashStruct, key, equal)) {
        //adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash2_1(key)],data);
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }
    log_trace("Saindo de put");
    return 0;
}

int put2_2(HashStruct2 *hashStruct, char *key, void *data, compare equal)  {
    log_trace("Entrando em put_2");
    log_info("Adicionando novo elemento no Hash");
    if (!containsKey2_2(hashStruct, key, equal)) {
        //adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash2_2(key)],data);
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }
    log_trace("Saindo de put");
    return 0;
}

int put2_3(HashStruct3 *hashStruct, char *key, void *data, compare equal)  {
    log_trace("Entrando em put_2");
    log_info("Adicionando novo elemento no Hash");
    if (!containsKey2_3(hashStruct, key, equal)) {
        //adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash2_3(key)],data);
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }
    log_trace("Saindo de put");
    return 0;
}

bool containsKey2_1(HashStruct1 *hashStruct, char *key, compare equal) {
    log_trace("Entrando em containsKey_2");
    //calcula a posição
    int hashValue = hash2_1(key);
    //busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal); 
    log_trace("Saindo de containsKey_2");
    return (pos!=-1)?true:false;
}

bool containsKey2_2(HashStruct2 *hashStruct, char *key, compare equal) {
    log_trace("Entrando em containsKey_2");
    //calcula a posição
    int hashValue = hash2_2(key);
    //busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal); 
    log_trace("Saindo de containsKey_2");
    return (pos!=-1)?true:false;
}

bool containsKey2_3(HashStruct3 *hashStruct, char *key, compare equal) {
    log_trace("Entrando em containsKey_2");
    //calcula a posição
    int hashValue = hash2_3(key);
    //busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal); 
    log_trace("Saindo de containsKey_2");
    return (pos!=-1)?true:false;
}

int hash2_1(char *key) {
    log_trace("Entrando em hash2_1");
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * 31) + key[i]; // Usamos um número primo (31) para espalhar os valores.
    }
    int hashvalue = hash % MAX;
    log_trace("Saindo de hash2_1");
    return hashvalue;
}

int hash2_2(char *key) {
    log_trace("Entrando em hash2_2");
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * 31) + key[i]; // Usamos um número primo (31) para espalhar os valores.
    }
    int hashvalue = hash % MAX2;
    log_trace("Saindo de hash2_2");
    return hashvalue;
}

int hash2_3(char *key) {
    log_trace("Entrando em hash2_3");
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * 31) + key[i]; // Usamos um número primo (31) para espalhar os valores.
    }
    int hashvalue = hash % MAX3;
    log_trace("Saindo de hash2_3");
    return hashvalue;
}


void graficoEspalhamento1(const HashStruct1 *hashStruct, const char *filename) {
    FILE *imageFile = fopen(filename, "w");
    if (imageFile) {
        int max_density = 0;

        // Encontra a densidade máxima na tabela
        for (int i = 0; i < MAX; i++) {
            int density = hashStruct->hashes[i].size;
            max_density = (density > max_density) ? density : max_density;
        }

        // Escreve o cabeçalho PPM no arquivo
        fprintf(imageFile, "P3\n");
        fprintf(imageFile, "32 32\n"); // Largura  x Altura 
        fprintf(imageFile, "255\n");   // Valor máximo de cor

        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                int density = hashStruct->hashes[i * 32 + j].size;

                // Calcule o valor de cor verde com base na densidade -> colisões
                int green = (int)((density / (double)max_density) * 255);
                int red = 0;
                int blue = 0;

                // Escreve o valor de cor no arquivo PPM
                fprintf(imageFile, "%d %d %d ", red, green, blue);
            }
        }

        fclose(imageFile);
        printf("Imagem da tabela Hash gerada: %s\n", filename);
    } else {
        printf("Erro ao criar o arquivo de imagem PPM.\n");
    }
}

void graficoEspalhamento2(const HashStruct2 *hashStruct, const char *filename) {
    FILE *imageFile = fopen(filename, "w");
    if (imageFile) {
        int max_density = 0;

        // Encontra a densidade máxima na tabela
        for (int i = 0; i < MAX2; i++) {
            int density = hashStruct->hashes[i].size;
            max_density = (density > max_density) ? density : max_density;
        }

        // Escreve o cabeçalho PPM no arquivo
        fprintf(imageFile, "P3\n");
        fprintf(imageFile, "32 32\n"); // Largura  x Altura 
        fprintf(imageFile, "255\n");   // Valor máximo de cor

        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                int density = hashStruct->hashes[i * 32 + j].size;

                // Calcule o valor de cor verde com base na densidade -> colisões
                int green = (int)((density / (double)max_density) * 255);
                int red = 0;
                int blue = 0;

                // Escreve o valor de cor no arquivo PPM
                fprintf(imageFile, "%d %d %d ", red, green, blue);
            }
        }

        fclose(imageFile);
        printf("Imagem da tabela Hash gerada: %s\n", filename);
    } else {
        printf("Erro ao criar o arquivo de imagem PPM.\n");
    }
}

void graficoEspalhamento3(const HashStruct3 *hashStruct, const char *filename) {
    FILE *imageFile = fopen(filename, "w");
    if (imageFile) {
        int max_density = 0;

        // Encontra a densidade máxima na tabela
        for (int i = 0; i < MAX3; i++) {
            int density = hashStruct->hashes[i].size;
            max_density = (density > max_density) ? density : max_density;
        }

        // Escreve o cabeçalho PPM no arquivo
        fprintf(imageFile, "P3\n");
        fprintf(imageFile, "32 32\n"); // Largura  x Altura 
        fprintf(imageFile, "255\n");   // Valor máximo de cor

        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                int density = hashStruct->hashes[i * 32 + j].size;

                // Calcule o valor de cor verde com base na densidade -> colisões
                int green = (int)((density / (double)max_density) * 255);
                int red = 0;
                int blue = 0;

                // Escreve o valor de cor no arquivo PPM
                fprintf(imageFile, "%d %d %d ", red, green, blue);
            }
        }

        fclose(imageFile);
        printf("Imagem da tabela Hash gerada: %s\n", filename);
    } else {
        printf("Erro ao criar o arquivo de imagem PPM.\n");
    }
}