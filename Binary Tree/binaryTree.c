#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int number;
    struct node *left;
    struct node *right;
}node;

node *createNode(int data){
    node *p = (node *)malloc(sizeof(node));
    p->number = data;
    p->left =NULL; 
    p->right = NULL;

    return p;
}

node *linkNode(node *root, node *p1, node *p2){
    root->left = p1;
    root->right = p2;

    return root;
}

void inOrderTraversal(node *root){
    if(root!=NULL){
        inOrderTraversal(root->left);
        printf("%d\n",root->number);
        inOrderTraversal(root->right);
    }
}
void postOrderTraversal(node *root){
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d\n",root->number);
    }
}
void preOrderTraversal(node *root){
    if(root!=NULL){
        printf("%d\n",root->number);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
int main(){
    node *tree = linkNode(createNode(2), linkNode(createNode(1), createNode(11), createNode(12)), linkNode(createNode(4), createNode(0), createNode(3)));
    inOrderTraversal(tree);
    printf("\n");
    postOrderTraversal(tree);
    printf("\n");
    preOrderTraversal(tree);

    return 0;
}