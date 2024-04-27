#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}node;

void traversal(node* ptr){
    while(ptr != NULL){
        printf("%d\n", ptr->number);
        ptr = ptr->next;
    }
}

node *insertAtFirst(node *head, int data){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->next = head;
    ptr->number = data;
    return ptr;
}

node *insertInBetween(node *head, int data, int index){
    node *ptr = (node *)malloc(sizeof(node));
    node *p = head;
    int i = 0;
    while(i!= index-1){
        p = p->next;
        i++;
    }
    ptr->number = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

node *insertAtEnd(node *head, int data){
    node *ptr = (node *)malloc(sizeof(node));
    node *p = head;
    ptr->number = data;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

node *inserAfterNode(node *head, node *prevNode, int data){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

node *deleteFirstNode(node *head){
    node * ptr = (node *)malloc(sizeof(node));
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

node *deleteMidleNode(node *head, int index){
    node * ptr = (node *)malloc(sizeof(node));
    ptr = head;
    int i = 0;
    while(i != index-1){
        ptr = ptr->next;
        i++;
    }
    node * q = (node *)malloc(sizeof(node));
    q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
}

node *deleteLastNode(node *head){
    node *ptr = (node *)malloc(sizeof(node));
    node *q = (node *)malloc(sizeof(node));
    ptr = head;
    q = head->next;
    while(q->next != NULL){
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
}
 
node *deleteGivenNode(node *head, int value){
    node * ptr = (node *)malloc(sizeof(node));
    node * q = (node *)malloc(sizeof(node));
    ptr = head;
    q = head->next;
    while(q->number != value && q->next != NULL){
        ptr = ptr->next;
        q = q->next;
    }
    if(q->number == value){
        ptr->next = q->next;
        free(q);
    } else {
        printf("Element not found\n");
    }
    return head;
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
    four->next = NULL;
    
    traversal(deleteGivenNode(head, 3));
    return 0;
}