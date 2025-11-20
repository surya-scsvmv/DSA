/*
  Aim:
  Implement Circular Queue using arrays.
*/

#include <stdio.h>
#define MAX 5

int q[MAX];
int front = -1, rear = -1;

// Insert element into circular queue
void enqueue(int x) {
    // Full condition: next position of rear is front
    if((rear + 1) % MAX == front) {
        printf("Queue full!\n");
        return;
    }

    if(front == -1) {          // First insertion
        front = 0;
    }

    rear = (rear + 1) % MAX;   // Move rear circularly
    q[rear] = x;
    printf("%d added\n", x);
}

// Delete element from circular queue
void dequeue() {
    if(front == -1) {          // Empty queue
        printf("Queue empty!\n");
        return;
    }

    printf("%d removed\n", q[front]);

    if(front == rear) {        // Only one element was present
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;   // Move front circularly
    }
}

// Display queue contents from front to rear
void display() {
    if(front == -1) {
        printf("Queue empty\n");
        return;
    }

    printf("Queue: ");
    int i = front;

    while(1) {
        printf("%d ", q[i]);
        if(i == rear) break;           // Stop after printing last element
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int ch, val;

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
                printf("Invalid option!\n");
        }
    }
}
