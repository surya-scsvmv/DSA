/*
  Aim:
  Implement stack push operation using arrays.
*/

#include <stdio.h>
#define MAX 5

int s[MAX];      // Stack array
int top = -1;    // Top starts at -1 (empty)

// Push function: inserts an element on top of the stack
void push(int x) {
    if(top == MAX - 1) {       // Check overflow
        printf("Stack full! Cannot push %d\n", x);
        return;
    }

    s[++top] = x;              // Increment top, then add value
    printf("Pushed %d\n", x);
}

int main() {
    int n, val;

    // Ask how many items user wants to push
    printf("How many items to push (max %d): ", MAX);
    scanf("%d", &n);

    // If user enters more than MAX, limit it
    if(n > MAX) {
        n = MAX;
    }

    // Read values and push them one by one
    for(int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        push(val);
    }

    return 0;
}
