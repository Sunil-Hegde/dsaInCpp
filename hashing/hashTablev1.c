#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} node;

node **createHashTable(int size) {
    node **newHashTable = (node **)malloc(size * sizeof(node *));
    for(int i = 0; i < size; i++) {
        newHashTable[i] = NULL;
    }
    return newHashTable;
}

unsigned int hashFunction(int value, int size) {
    unsigned int hashValue = value % size;
    return hashValue;
}

void printHashTable(node **hashTable, int size) {
    printf("\nStart\n");
    for(int i = 0; i < size; i++) {
        if(hashTable[i] == NULL) {
            printf("\t%d\t-----\n", i);
        } else {
            printf("\t%d\t", i);
            node *temp = hashTable[i];
            while(temp != NULL) {
                printf("%d", temp->value);
                temp = temp->next;
                if(temp != NULL) {
                    printf(" -> ");
                }
            }
            printf("\n");
        }
    }
    printf("End\n\n");
}


void insert(node **hashTable, node *p, int size) {
    if (p == NULL) return;
    int index = hashFunction(p->value, size);
    p->next = hashTable[index];
    hashTable[index] = p;
}

void lookUp(node **hashTable, int value, int size) {
    int index = hashFunction(value, size);
    node *temp = hashTable[index];
    while(temp != NULL && temp->value != value) {
        temp = temp->next;
    }
    if(temp != NULL && temp->value == value) {
        printf("Found %d.\n", temp->value);
    } else {
        printf("%d not Found.\n", value);
    }
}

void deleteNode(node **hashTable, int value, int size) {
    int index = hashFunction(value, size);
    node *temp = hashTable[index];
    node *prev = NULL;
    while(temp != NULL && temp->value != value) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("%d not Found.\n", value);
        return;
    }
    if(prev == NULL) {
        printf("Deleted %d.\n", temp->value);
        hashTable[index] = temp->next;
    } else {
        printf("Deleted %d.\n", temp->value);
        prev->next = temp->next;
    }
    free(temp);
}

int main() {
    int n;
    printf("Enter the size of hash table: ");
    scanf("%d", &n);
    node **hashTable = createHashTable(n);
    while(1) {
        int option;
        printf("\n\nHash Table operations:\n");
        printf("\n1. Insert\n2. Lookup\n3. Delete\n4. Display\n5. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1: {
                printf("\nEnter element to insert in the Hash Table: ");
                node *temp = (node *)malloc(sizeof(node));
                scanf("%d", &temp->value);
                insert(hashTable, temp, n);
                break;
            }
            case 2: {
                int value;
                printf("\nEnter the element to lookup in the Hash Table: ");
                scanf("%d", &value);
                lookUp(hashTable, value, n);
                break;
            }
            case 3: {
                int value;
                printf("\nEnter the element to delete in the Hash Table: ");
                scanf("%d", &value);
                deleteNode(hashTable, value, n); // Renamed to deleteNode
                break;
            }
            case 4:
                printHashTable(hashTable, n);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }
    return 0;
}
