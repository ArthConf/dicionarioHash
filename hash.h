#ifndef EstruturaDeDados_Hash_h
#define EstruturaDeDados_Hash_h
#include "DoublyLinkedList.h"
#define MAX 1024
#define MAX2 512
#define MAX3 256

typedef struct HashStruct1{
    DoublyLinkedList hashes[MAX];
    int size;
}HashStruct1;

typedef struct HashStruct2{
    DoublyLinkedList hashes[MAX2];
    int size;
}HashStruct2;

typedef struct HashStruct3{
    DoublyLinkedList hashes[MAX3];
    int size;
}HashStruct3;
// Adicione protótipos de funções no início do arquivo hash.c

bool containsKey1_1(HashStruct1 *hashStruct, char *key, compare equal);
bool containsKey1_2(HashStruct2 *hashStruct, char *key, compare equal);
bool containsKey1_3(HashStruct3 *hashStruct, char *key, compare equal);
bool containsKey2_1(HashStruct1 *hashStruct, char *key, compare equal);
bool containsKey2_2(HashStruct2 *hashStruct, char *key, compare equal);
bool containsKey2_3(HashStruct3 *hashStruct, char *key, compare equal);
bool comparador(void* data_1,void* data_2);
void initHash1(HashStruct1 *hashStruct);
void initHash2(HashStruct2 *hashStruct);
void initHash3(HashStruct3 *hashStruct);
int hash1_1(char *key);
int hash1_2(char *key);
int hash1_3(char *key);
int put1_1(HashStruct1 *hashStruct, char *key, void *data, compare equal);
int put1_2(HashStruct2 *hashStruct, char *key, void *data, compare equal);
int put1_3(HashStruct3 *hashStruct, char *key, void *data, compare equal);
int hash2_1(char *key);
int hash2_2(char *key);
int hash2_3(char *key);
int put2_1(HashStruct1 *hashStruct, char *key, void *data, compare equal);
int put2_2(HashStruct2 *hashStruct, char *key, void *data, compare equal);
int put2_3(HashStruct3 *hashStruct, char *key, void *data, compare equal);
void graficoEspalhamento1(const HashStruct1 *hashStruct, const char *filename);
void graficoEspalhamento2(const HashStruct2 *hashStruct, const char *filename);
void graficoEspalhamento3(const HashStruct3 *hashStruct, const char *filename);
#endif