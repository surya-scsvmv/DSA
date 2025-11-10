/*
Aim:
To convert an infix expression to postfix using stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

char peek() {
    if(top == -1) return '\0';
    return stack[top];
}

int prec(char op) {
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

int main() {
    printf("Enter max size: ");
    scanf("%d", &size);
    stack = malloc(size * sizeof(char));

    char infix[size], postfix[size];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    int i=0, j=0;
    char c;
    while((c=infix[i++])!='\0') {
        if(isalnum(c))
            postfix[j++] = c;
        else if(c=='(')
            push(c);
        else if(c==')') {
            while(peek()!='(' && peek()!='\0')
                postfix[j++] = pop();
            pop();
        } else {
            while(prec(peek()) >= prec(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while(peek()!='\0')
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);

    free(stack);
    return 0;
}
