#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int number;
    struct node *left, *right;
}node;

node *createNode(int number){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->number = number;
    newNode->left = newNode->right = NULL;

    return newNode;
}

void inOrderTraversal(node *root){
    if(root!=NULL){
        inOrderTraversal(root->left);
        printf("%d ",root->number);
        inOrderTraversal(root->right);
    }
}
void postOrderTraversal(node *root){
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ",root->number);
    }
}
void preOrderTraversal(node *root){
    if(root!=NULL){
        printf("%d ",root->number);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void takeInput(node* root) {
    int option;
    printf("Create left child of %d? (1 for YES, 0 for NO): ", root->number);
    scanf("%d", &option);
    if (option == 1) {
        int data;
        printf("Enter data for left child: ");
        scanf("%d", &data);
        root->left = createNode(data);
        takeInput(root->left);
    }

    printf("Create right child of %d? (1 for YES, 0 for NO): ", root->number);
    scanf("%d", &option);
    if (option == 1) {
        int data;
        printf("Enter data for right child: ");
        scanf("%d", &data);
        root->right = createNode(data);
        takeInput(root->right);
    }
}

void display(node *root){
    if(root->number == 0){
        printf("\nTree is empty.\n");
    } else {
        printf("Pre order: ");
        preOrderTraversal(root);
        printf("\nPost order: ");
        postOrderTraversal(root);
        printf("\nIn order: ");
        inOrderTraversal(root);
    }
}

int main(){
    int option;
    node *root = NULL;
    while(1){
        printf("\nBinary tree operations:\n");
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                if(root == NULL){
                    int number;
                    printf("\nEnter value for root node: ");
                    scanf("%d", &number);
                    root = createNode(number);
                    takeInput(root);
                } else {
                    takeInput(root);
                }
                break;
            case 2: 
                display(root);
                break;
            case 3:
                exit(0);
                break;
            default : printf("Invalid choice."); exit(1);
        }
    }

    return 0;
}