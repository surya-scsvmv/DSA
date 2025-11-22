Aim:
To implement Depth First Search (DFS) traversal for a binary tree and display the nodes using Preorder, Inorder, and Postorder traversals.
Algorithm:
Algorithm for DFS Traversals

Algorithm: Preorder Traversal

PREORDER(node)
1. If node is not NULL:
2.    Visit(node)
3.    PREORDER(node->left)
4.    PREORDER(node->right)

Algorithm: Inorder Traversal

INORDER(node)
1. If node is not NULL:
2.    INORDER(node->left)
3.    Visit(node)
4.    INORDER(node->right)

Algorithm: Postorder Traversal

POSTORDER(node)
1. If node is not NULL:
2.    POSTORDER(node->left)
3.    POSTORDER(node->right)
4.    Visit(node)
Program:
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
output:
DFS - Preorder: 1 2 4 5 3
DFS - Inorder : 4 2 5 1 3
DFS - Postorder: 4 5 2 3 1
Result:
hence the tree traversalof DFS is executed successfully 
