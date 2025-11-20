/*
  Aim:
  Implement basic queue operations using arrays.
*/

#include <stdio.h>
#define MAX 5

int q[MAX];
int front = -1, rear = -1;

// Insert an element into the queue
void enqueue(int x) {
    if(rear == MAX - 1) {       // Queue full (no circular handling here)
        printf("Queue full\n");
        return;
    }

    if(front == -1) {           // First insertion
        front = 0;
    }

    q[++rear] = x;              // Add element at the end
    printf("%d added\n", x);
}

// Remove an element from the queue
void dequeue() {
    if(front == -1 || front > rear) {   // Empty condition
        printf("Queue empty\n");
        return;
    }

    printf("%d deleted\n", q[front++]);

    // If all elements removed, reset queue
    if(front > rear) {
        front = rear = -1;
    }
}

// Display current queue contents
void display() {
    if(front == -1) {
        printf("Queue empty\n");
        return;
    }

    printf("Queue: ");
    for(int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main() {
    int ch, val;

    // Simple menu-driven program
    while(1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\nChoice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid!\n");
        }
    }
}
