#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int number;
    struct node *prev;
    struct node *next;
}node;

node *traverseNormal(node *head){
    while(head != NULL){
        printf("%d\n", head->number);
        head = head->next;
    }
    printf("\n");
    return head;
}
node *traverseReverse(node *head){
    node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    while(ptr != NULL){
        printf("%d\n", ptr->number);
        ptr = ptr->prev;
    }
    return ptr;
}

int main(){
    node * head = (node *)malloc(sizeof(node));
    node * second = (node *)malloc(sizeof(node));
    node * third = (node *)malloc(sizeof(node));
    node * four = (node *)malloc(sizeof(node));

    head->number = 1;
    head->prev = NULL;
    head->next = second;

    second->number = 2;
    second->prev = head;
    second->next = third;

    third->number = 3;
    third->prev = second;
    third->next = four;

    four->number = 4;
    four->prev = third;
    four->next = NULL;

    traverseNormal(head);
    traverseReverse(head);
    return 0;
}