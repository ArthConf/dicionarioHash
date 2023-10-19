#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void initHash(HashStruct *hashStruct){
    for(int i = 0; i<=MAX; i++){
        init(&(hashStruct ->hashes[i]));
    }
    hashStruct -> size = 0;
}

int hash(char *key){
    int sum = 0;

    for(int i = 0; key[i]!= 0 ; i++){
        sum += key[i]*(i+1);
    }
    return sum%MAX;
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal){
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct ->hashes[hashValue], key, equal);
    return (pos!=-1)?true:false;
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal){
    if(!containsKey(hashStruct, key, equal)){

        int res = enqueue(&hashStruct->hashes[hash(key)], data);
        hashStruct->size+=res;
        return res;
}
    return 0;
}

void* get(HashStruct *hashStruct, char *key, compare equal){
    int hashValue = hash(key);

    Node *aux = hashStruct->hashes[hashValue].first->next;

    while(aux!=hashStruct->hashes[hashValue].first->next && !equal(aux->data, key))
        aux=aux->next;
    return aux->data;
}

void* removeKey(HashStruct *hashStruct, char *key, compare equal){
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct -> hashes[hashValue], key, equal);
    void* result= removePos(&hashStruct -> hashes[hashValue], pos);

    if(result!=NULL) hashStruct->size--;
    return result;
}

