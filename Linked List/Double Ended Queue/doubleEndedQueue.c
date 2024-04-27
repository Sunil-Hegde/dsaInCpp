#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *createNode(int data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node *insertEnd(node *head, int data){
    node *temp = head;
    node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
    } else {
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d is inserted ", newNode->data);
    return head;
}

node *insertAtFront(node *head, int data){
    node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    printf("%d is inserted ", newNode->data);
    return head;
}

node *deleteFront(node *head){
    if(head ==  NULL){
        printf("List is empty\n");
        return head;
    }
    node *temp = head;
    head = temp->next;
    printf("\n%d is deleted.\n", temp->data);
    free(temp);
    return head;
}

node *deleteEnd(node *head){
    if(head ==  NULL){
        printf("List is empty\n");
        return head;
    }
    node *temp = head;
    node *q = head->next;
    while(q->next != NULL){
        temp = temp->next;
        q = q->next;
    }
    temp->next = NULL;
    printf("\n%d is deleted.\n", q->data);
    free(q);
    return head;
}

void display(node *head){
    printf("\n");
    if(head == NULL){
        printf("\nList is empty.\n");
    } else {
        while(head != NULL){
            printf("%d ", head->data);
            head = head->next;
        }
    }
    printf("\n");
}

int main(){
    int option, subOption, data;
    node *head = NULL;
    while(1){
        printf("\n\nDouble Ended queue operations:\n");
        printf("\n1.Entry restricted Queue\n2.Exit restricted Queue\n3.Display\n4.Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &option);
        switch(option){
            case 1 :
                printf("\nEntry restricted operations:\n");
                printf("\n1.Insert\n2.Delete Rear\n3.Delete Front\n");
                printf("\nEnter your choice: ");
                scanf("%d", &subOption);
                switch(subOption){
                    case 1:
                        printf("\nEnter the number to be entered: ");
                        scanf("%d", &data);
                        head = insertEnd(head, data);
                        break;
                    case 2:
                        head = deleteEnd(head);
                        break;
                    case 3:
                        head = deleteFront(head);
                        break;
                    default:
                        printf("\nInvalid Choice!\n");
                        break;
                }
                break;
            case 2 : 
                printf("\nExit restricted operations:\n");
                printf("\n1.Delete\n2.Insert Rear\n3.Insert Front\n");
                printf("\nEnter your choice: ");
                scanf("%d", &subOption);
                switch(subOption){
                    case 1:
                        head = deleteFront(head);
                        break;
                    case 2:
                        printf("\nEnter the number to be entered: ");
                        scanf("%d", &data);
                        head = insertEnd(head, data);
                        break;
                    case 3:
                        printf("\nEnter the number to be entered: ");
                        scanf("%d", &data);
                        head = insertAtFront(head, data);
                        break;
                    default:
                        printf("\nInvalid Choice!\n");
                        break;
                }
                break;
            case 3 :
                display(head);
                break;
            case 4 : exit(0);
            default : printf("\nInvalid Choice!\n"); break;
        }
    }
    return 0;
}
