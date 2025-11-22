/*
  Aim:
  Convert an infix expression to postfix using a stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int top = -1;
int size;
char *stack;

// Push a character onto stack
void push(char c) {
    if(top == size - 1) {     // Overflow check
        printf("Stack full\n");
        return;
    }
    stack[++top] = c;
}

// Pop a character from stack
char pop() {
    if(top == -1) {          // Underflow check
        return '\0';
    }
    return stack[top--];
}

// Peek top element
char peek() {
    if(top == -1) {
        return '\0';
    }
    return stack[top];
}

// Operator precedence
int prec(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^')              return 3;
    return 0;
}

int main() {
    printf("Enter max size: ");
    scanf("%d", &size);

    stack = malloc(size * sizeof(char));   // Allocate stack

    char infix[size], postfix[size];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    int i = 0, j = 0;
    char c;

    // Scan each symbol of infix expression
    while((c = infix[i++]) != '\0') {

        if(isalnum(c)) {
            // Directly add operands to postfix
            postfix[j++] = c;
        }
        else if(c == '(') {
            push(c);
        }
        else if(c == ')') {
            // Pop until matching '(' is found
            while(peek() != '(' && peek() != '\0') {
                postfix[j++] = pop();
            }
            pop();  // Remove '('
        }
        else {
            // For operators: pop higher/equal precedence ones
            while(prec(peek()) >= prec(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    // Pop all remaining operators
    while(peek() != '\0') {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';   // Null-terminate postfix string

    printf("Postfix: %s\n", postfix);

    free(stack);
    return 0;
}
