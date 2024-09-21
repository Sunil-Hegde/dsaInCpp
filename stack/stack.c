#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 10
int top = -1;

void push(int stack[], int number){
    stack[++top] = number;
    printf("%d pushed successfully into the stack.\n", number);
}

void pop(int stack[]){
    int i = stack[top--];
    printf("%d popped successfully from the stack.\n", i);
}

void display(int stack[]){
    printf("Elements of the stack are:\n");
    for(int i = top; i >= 0; i--){
        printf("\t%d\n", stack[i]);
    }
}

int main(){
    int stack[STACK_SIZE];
    while(1){
        int choice, number;
        printf("\nStack Operations:\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter the number to be pushed: ");
                scanf("%d", &number);
                push(stack, number);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                if(top == -1){
                    printf("Stack is Empty.\n");
                } else {
                    display(stack);
                }
                break;
            default: exit(0);
        }
    }
    return 0;
}