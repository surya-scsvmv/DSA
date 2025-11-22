/*
  Aim:
  Implement a Binary Tree and perform BFS (Level Order Traversal)
  using a queue.
*/

#include <stdio.h>
#include <stdlib.h>

// Binary tree node structure
struct node {
    int data;
    struct node *left, *right;
};

// Queue structure for BFS
struct queue {
    int front, rear, size;
    struct node* arr[50];
};

struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = -1;
    q->size = 50;
    return q;
}

void enqueue(struct queue* q, struct node* temp) {
    if(q->rear == q->size - 1)
        return;
    if(q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = temp;
}

struct node* dequeue(struct queue* q) {
    if(q->front == -1)
        return NULL;
    struct node* temp = q->arr[q->front];
    if(q->front >= q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Create new tree node
struct node* newNode(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// BFS (Level Order Traversal)
void BFS(struct node* root) {
    struct queue* q = createQueue();
    enqueue(q, root);

    while(q->front != -1) {
        struct node* current = dequeue(q);
        printf("%d ", current->data);

        if(current->left != NULL)
            enqueue(q, current->left);

        if(current->right != NULL)
            enqueue(q, current->right);
    }
}

int main() {

    /* Sample Tree:
              1
            /   \
           2     3
          / \
         4   5
    */

    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("BFS (Level Order Traversal): ");
    BFS(root);
    return 0;
}
