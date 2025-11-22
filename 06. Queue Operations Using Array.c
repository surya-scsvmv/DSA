/*
  Aim:
  Implement Queue operations (Enqueue, Dequeue, Display)
  using an array with proper overflow and underflow handling.
*/

#include<stdio.h>

int front = -1, rear = -1, MAX;

void enqueue(int queue[])
{
    int item;
    if(rear == MAX - 1)
    {
        printf("Queue is Overflow\n");
    }
    else
    {
        printf("Enter element to enqueue : ");
        scanf("%d", &item);

        if(front == -1 && rear == -1)   // first element
        {
            front = rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
        queue[rear] = item;
    }
}

void dequeue(int queue[])
{
    if(front == -1 || front > rear)
    {
        printf("Queue is Underflow\n");
    }
    else
    {
        int item = queue[front];
        front = front + 1;

        // Reset queue if empty
        if(front > rear)
        {
            front = rear = -1;
        }
    }
}

void display(int queue[])
{
    if(front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Current Queue elements: ");
        for(int i = front; i <= rear; i++)
        {
            printf(" %d ", queue[i]);
        }
        printf(" <-rear\n");
    }
}

int main()
{
    int choice;

    printf("Enter the size of queue: ");
    scanf("%d", &MAX);

    int queue[MAX];

    while(1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Choose queue operation: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue(queue);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
