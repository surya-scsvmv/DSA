/*
Aim:
To implement basic queue operations using arrays.
*/

#include <stdio.h>
#define MAX 5

int q[MAX];
int front=-1, rear=-1;

void enqueue(int x) {
    if(rear == MAX-1) {
        printf("Queue full\n");
        return;
    }
    if(front == -1) front = 0;
    q[++rear] = x;
    printf("%d added\n", x);
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue empty\n");
        return;
    }
    printf("%d deleted\n", q[front++]);
    if(front > rear)
        front = rear = -1;
}

void display() {
    if(front == -1) {
        printf("Queue empty\n");
        return;
    }
    printf("Queue: ");
    for(int i=front;i<=rear;i++)
        printf("%d ", q[i]);
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
                printf("Invalid!\n");
        }
    }
}
