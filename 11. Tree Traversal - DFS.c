/*
  Aim:
  Implement a Binary Tree and perform DFS traversals:
  Preorder, Inorder, and Postorder.
*/


#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(struct node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {


    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("DFS - Preorder: ");
    preorder(root);

    printf("\nDFS - Inorder : ");
    inorder(root);

    printf("\nDFS - Postorder: ");
    postorder(root);

    return 0;
}
