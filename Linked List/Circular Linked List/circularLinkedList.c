#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}node;

void traversal(node* head){
    node *ptr = head;
    do{
        printf("%d\n", ptr->number);
        ptr = ptr->next;
    }while(ptr != head);
}

int main(){
    node * head = (node *)malloc(sizeof(node));
    node * second = (node *)malloc(sizeof(node));
    node * third = (node *)malloc(sizeof(node));
    node * four = (node *)malloc(sizeof(node));

    head->number = 1;
    head->next = second;

    second->number = 2;
    second->next = third;

    third->number = 3;
    third->next = four;

    four->number = 4;
    four->next = head;

    return 0;
}