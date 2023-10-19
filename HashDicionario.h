#ifndef EstruturaDeDados_Hash_h
#define EstruturaDeDados_Hash_h
#include "LinkedList.h"
#define MAX 10

typedef struct HashStruct {
    LinkedList hashes[MAX];
    int size;
    int num;
}HashStruct;

void initHash(HashStruct *hashStruct);
bool isHashEmpty(HashStruct *hashStruct);
int hash(char *key);
int put(HashStruct *hashStruct, char *key, void *data, compare equal);
bool containsKey(HashStruct *hashStruct, char *key, compare equal);
void* get(HashStruct *hashStruct, char *key, compare equal);
void* removeKey(HashStruct *hashStruct, char *key, compare equal);
void showHashStruct(HashStruct *hashStruct);

#endif