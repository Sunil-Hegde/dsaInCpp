#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *right, *left;
}node;

node *getNode(){
    node *temp = (node *)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    return temp;
}

void insert(node *root, int number){
    node *prev = NULL;
    while(root != NULL){
        prev = root;
        if(root->data == number){
            return;
        } else if(root->data > number){
            root = root->left;
        } else {
            root = root->right;
        }
    }
    node *newNode = getNode();
    newNode->data = number;
    if(newNode->data < prev->data){
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }
}

node *inOrderPredecessor(node *root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

node *delete(node *root, int number){
    if (root == NULL){
        printf("Empty.");
        return NULL;
    } else if(root->left == NULL && root->right == NULL){
        printf("%d deleted successfully.", root->data);
        free(root);
        return NULL;
    }
    node *iPre;
    if(number < root->data){
        root->left = delete(root->left, number);
    } else if(number > root->data){
        root->right = delete(root->right, number);
    } else {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = delete(root->left, iPre->data);
    }
    return root;
}

void displayTree(node *root){
    if(root != NULL){
        displayTree(root->left);
        printf("%d ", root->data);
        displayTree(root->right);
    }
}

int main(){
    int choice, number;
    node *root = getNode(); 
    printf("Enter data for root node: ");
    scanf("%d", &root->data);
    while(1){
        printf("BST Operations:\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("Enter number to be inserted: ");
                scanf("%d", &number);
                insert(root, number);
                break;
            case 2: 
                printf("Enter number to be deleted: ");
                scanf("%d", &number);
                root = delete(root, number);
                break;
            case 3: 
                displayTree(root);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}