#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *createNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node *insertAtFront(node *head, int data){
    node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        head->next = head;
    } else {
        node *temp = head;
        newNode->next = temp;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode;
    }
    return head;
}

node *insertAtEnd(node *head, int data){
    node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        head->next = head;
    } else {
        node *temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}

node *deleteFromFront(node *head){
    if (head == NULL) {
        return NULL; 
    }
    if (head->next == head) {
        printf("%d deleted successfully. List is empty.\n", head->data);
        free(head);
        return NULL; 
    }
    node *temp = head;
    while (temp->next != head){
        temp = temp->next;
    }
    node *newHead = head->next;
    temp->next = newHead;
    printf("%d deleted successfully.\n", head->data);
    free(head);
    return newHead;
}

node *deleteFromEnd(node *head){
    if (head == NULL) {
        return NULL; 
    }
    if (head->next == head) {
        free(head);
        return NULL; 
    }
    node *temp = head;
    while (temp->next->next != head){
        temp = temp->next;
    }
    printf("%d deleted successfully.\n", temp->next->data);
    free(temp->next);
    temp->next = head;
    return head;
}

void display(node *head){
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
    } else {
        node *temp = head;
        do {
            printf("%d => ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int main(){
    node *head = NULL;
    while(1){
        int choice, number;
        printf("Circular linked list operations:\n");
        printf("\t1.Insert at begining\n\t2. Insert at End\n\t3. Delete from front.\n\t4. Delete from end.\n\t5. Display\n\t6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the number to be inserted at front: ");
                scanf("%d", &number);
                head = insertAtFront(head, number);
                printf("%d inserted successfully.\n", head->data);
                break;
            case 2:
                printf("Enter the number to be inserted at the end: ");
                scanf("%d", &number);
                head = insertAtEnd(head, number);
                printf("%d inserted successfully.\n", number);
                break;
            case 3:
                head = deleteFromFront(head);
                break;
            case 4:
                head = deleteFromEnd(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice.");
                exit(0);
                break;
        }
    }
    return 0;
}