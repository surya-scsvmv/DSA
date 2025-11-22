/*
  Aim:
  Implement stack operations (Push, Pop, Display) using an array,
  allowing user-driven stack manipulation with overflow/underflow checks.
*/

#include<stdio.h>

int Top = -1, MAX;

void display(int stack[])
{
    printf("Current stack elements are-\n");
    for(int i=0; i<=Top; i++)
    {
        printf(">>%d", stack[i]);
    }
    printf("(Top)");
}

void push(int stack[])
{
    int item;
    if(Top == MAX - 1)
    {
        printf("Stack is Overflow");
    }
    else
    {
        printf("Enter the elements to push : ");
        scanf("%d", &item);
        Top = Top+1;
        stack[Top] = item;
    }
}

void pop(int stack[])
{
    int item;
    if(Top == -1)
    {
        printf("Stack is Underflow");
    }
    else
    {
        item = stack[Top];
        Top = Top-1;
    }
}

int main()
{
    int operation = 0, top = -1;
    printf("Enter the size of stack : ");
    scanf ("%d", &MAX);
    int stack[MAX];

    while(operation != 3)
    {
        printf("\n 1.Push \n 2.Pop \n 3.Exit \n");
        printf("\nPlease choose stack operation to perform : ");
        scanf("%d", &operation);

        switch(operation)
        {
            case 1:
                push(stack);
                display(stack);
                break;

            case 2:
                pop(stack);
                display(stack);
                break;

            case 3:
                return 0;

            default:
                printf("Incorrect operation");
                break;
        }
    }
    return 0;
}
