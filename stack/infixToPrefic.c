#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX_SIZE 20

char stack[MAX_SIZE];
int top = -1;
char postFix[MAX_SIZE];
int postTop = -1;

void push(char op){
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = op;
}

char pop(){
    if (top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return stack[top--];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPrefix(char infix[], int size) {
    printf("Prefix expression: ");
    for (int i = size - 1; i >= 0; i--) {
        if (!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')') {
            postFix[++postTop] = infix[i]; 
        } else if (infix[i] == ')') {
            push(infix[i]); 
        } else if (infix[i] == '(') {
            while (top != -1 && stack[top] != ')') {
                postFix[++postTop] = pop(); 
            }
            if (top != -1 && stack[top] == ')') {
                pop(); 
            } else {
                printf("\nInvalid expression: Unbalanced parentheses\n");
                return;
            }
        } else {
            int opPrec = precedence(infix[i]);
            while (top != -1 && precedence(stack[top]) > opPrec) {
                postFix[++postTop] = pop(); 
            }
            push(infix[i]); 
        }
    }
    while (top != -1) {
        if (stack[top] == '(' || stack[top] == ')') {
            printf("\nInvalid expression: Unbalanced parentheses\n");
            return;
        }
        postFix[++postTop] = pop();
    }
    while(postTop > -1){
        printf("%c", postFix[postTop--]);
    }
    printf("\n");
}

int main(){
    char infixExp[30];
    printf("Enter an infix expression: ");
    scanf("%s", infixExp);
    int size = strlen(infixExp);
    infixToPrefix(infixExp, size);
    return 0;
}
