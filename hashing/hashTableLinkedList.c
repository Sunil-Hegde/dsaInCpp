#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person *next; 
} person;

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
            printf("\t%d\t-----\n", i); 
        } else {
            printf("\t%d\t", i);
            person *temp = hashTable[i];
            while (temp != NULL){
                printf("%s - ", temp->name);
                temp = temp->next;
            }
            printf("\n");
        }
    }
    printf("End\n\n");
}

bool hashTableInsert(person *p){
    if (p == NULL) return false;
    int index = hashFuntion(p->name);
    p->next = hashTable[index];
    hashTable[index] = p;
    return true;
}

void hashTableLookup(char *name){
    int index = hashFuntion(name);
    person *temp = hashTable[index];
    while(temp != NULL && strncmp(temp->name, name, MAX_NAME) != 0){
        temp = temp->next;
    }
    if (temp != NULL && strncmp(temp->name, name, MAX_NAME) == 0){
        printf("Found %s.\n", temp->name);
    } else {
        printf("%s not Found.\n", name);
    }
}

void hashTableDelete(char *name){
    int index = hashFuntion(name);
    person *temp = hashTable[index];
    person *prev = NULL;
    while(temp != NULL && strncmp(temp->name, name, MAX_NAME) != 0){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("%s not Found.\n", name);
        return; 
    }
    if (prev == NULL){
        printf("Deleted %s.\n", temp->name);
        hashTable[index] = temp->next;
    } else {
        printf("Deleted %s.\n", temp->name); 
        prev->next = temp->next;
    }
}

int main(){
    initialiseHashTable();
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
