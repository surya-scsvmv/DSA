/*
  Aim:
  Reverse a string using a stack.
*/

#include <stdio.h>
#include <stdlib.h>

int top = -1;
int size;
char *stack;

// Push a character onto the stack
void push(char c) {
    if(top == size - 1) {    // Overflow check
        printf("Stack full\n");
        return;
    }
    stack[++top] = c;
}

// Pop a character from the stack
char pop() {
    if(top == -1) {          // Underflow check
        return '\0';
    }
    return stack[top--];
}

int main() {
    // Read maximum size
    printf("Enter max string size: ");
    scanf("%d", &size);

    stack = malloc(size * sizeof(char));   // Allocate stack array

    char str[size];
    printf("Enter a string: ");
    scanf("%s", str);

    // Push all characters onto the stack
    for(int i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    // Pop characters and print reversed string
    printf("Reversed: ");
    char c;
    while((c = pop()) != '\0') {
        printf("%c", c);
    }
    printf("\n");

    free(stack);   // Free allocated memory
    return 0;
}
