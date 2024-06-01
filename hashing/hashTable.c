#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 15

typedef struct person{
    char name[MAX_NAME];
    int age;
}person;

person *hashTable[TABLE_SIZE];

unsigned int hashFuntion(char *name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hashValue = 0;
    for(int i = 0; i < length; i++){
        hashValue += name[i];
        hashValue *= name[i];
        hashValue %= TABLE_SIZE;
    }
    return hashValue;
}

void initialiseHashTable(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashTable[i] = NULL;
    }
}

void printHashTable(){
    printf("\nStart\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hashTable[i] == NULL){
            printf("\t%d\t-----", i);
        } else {
            printf("\t%d\t%s",i,hashTable[i]->name);
        }
        printf("\n");
    }
    printf("End\n\n");
}

bool hashTableInsert(person *p){
    if (p == NULL) return false;
    int index = hashFuntion(p->name);
    for(int i = 0; i< TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if(hashTable[try] == NULL){
            hashTable[try] = p;
            return true;
        }
    }
    return false;
}

void hashTableLookup(char *name){
    int index = hashFuntion(name);
    bool flag = false;
    int foundIndex;
    for(int i = 0; i< TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if (hashTable[index] != NULL && strncmp(hashTable[index]->name, name, TABLE_SIZE) == 0){
            flag = true;
            foundIndex = try;
        } 
    } 
    if (flag){
        printf("Found %s.\n", hashTable[foundIndex]->name);
    } else {
        printf("%s not Found.\n", name);
    }
}

void hashTableDelete(char *name){
    int index = hashFuntion(name);
    bool flag = false;
    for(int i = 0; i< TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if (hashTable[index] != NULL && strncmp(hashTable[index]->name, name, TABLE_SIZE) == 0){
            printf("Deleted %s.\n", hashTable[try]->name);
            hashTable[try] = NULL;
            flag = true;
        }
    }
    if(!flag){
        printf("%s not Found.\n", name);
    }
}

int main(){
    initialiseHashTable();
    /*printf("Jacob => %u\n", hashFuntion("Jacob"));
    printf("Ronaldo => %u\n", hashFuntion("Ronaldo"));
    printf("sunil => %u\n", hashFuntion("sunil"));
    printf("Random => %u\n", hashFuntion("Random"));
    printf("home => %u\n", hashFuntion("home"));
    printf("ise => %u\n", hashFuntion("ise"));
    printf("laptop => %u\n", hashFuntion("laptop"));*/
    person jacob = {.name="jacob", .age=256};
    person Ronaldo = {.name="Ronaldo", .age=256};
    person sunil = {.name="sunil", .age=256};
    person Random = {.name="Random", .age=256};
    person home = {.name="home", .age=256};
    person ise = {.name="ise", .age=256};
    person laptop = {.name="laptop", .age=256};
    person range = {.name="range", .age=256};
    person shirt = {.name="shirt", .age=256};
    person earphones = {.name="earphones", .age=256};
    person school = {.name="school", .age=256};
    person omg = {.name="omg", .age=256};

    hashTableInsert(&jacob);
    hashTableInsert(&Ronaldo);
    hashTableInsert(&sunil);
    hashTableInsert(&Random);
    hashTableInsert(&home);
    hashTableInsert(&ise);
    hashTableInsert(&laptop);
    hashTableInsert(&range);
    hashTableInsert(&shirt);
    hashTableInsert(&earphones);
    hashTableInsert(&school);
    hashTableInsert(&omg);
    printHashTable();
    hashTableLookup("idk");
    hashTableLookup("sunil");
    hashTableDelete("sunil");
    printHashTable();
    return 0;
}