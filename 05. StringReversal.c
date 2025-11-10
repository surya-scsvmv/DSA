/*
Aim:
To reverse a string using stack.
*/

#include <stdio.h>
#include <stdlib.h>

int top = -1, size;
char *stack;

void push(char c) {
    if(top == size-1)
        printf("Stack full\n");
    else
        stack[++top] = c;
}

char pop() {
    if(top == -1)
        return '\0';
    return stack[top--];
}

int main() {
    printf("Enter max string size: ");
    scanf("%d", &size);
    stack = malloc(size * sizeof(char));

    char str[size];
    printf("Enter a string: ");
    scanf("%s", str);

    for(int i=0; str[i]!='\0'; i++)
        push(str[i]);

    printf("Reversed: ");
    char c;
    while((c=pop())!='\0')
        printf("%c", c);
    printf("\n");

    free(stack);
    return 0;
}
