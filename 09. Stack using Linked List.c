/*
  Aim:
  Implement Stack operations (Push, Pop, Display)
  using a Linked List where the top pointer represents the stack's top.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push() {
    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Element pushed.\n");
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow.\n");
        return;
    }

    struct Node *temp = top;
    top = top->next;
    free(temp);

    printf("Element popped.\n");
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *temp = top;
    printf("Stack elements (top to bottom): ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
