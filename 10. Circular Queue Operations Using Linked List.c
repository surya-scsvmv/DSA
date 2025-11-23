/*
  Aim:
  Implement a Circular Queue using a Linked List with operations:
  Enqueue, Dequeue, and Display, maintaining front–rear linkage circularly.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue() {
    int value;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (front == NULL) {     
        front = rear = newNode;
        rear->next = front; 
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("Element enqueued.\n");
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow.\n");
        return;
    }

    struct Node *temp = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }

    free(temp);
    printf("Element dequeued.\n");
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;

    printf("Circular Queue elements: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("(back to front)\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- CIRCULAR QUEUE USING LINKED LIST ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
