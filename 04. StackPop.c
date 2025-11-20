/*
  Aim:
  Implement stack pop operation using arrays.
*/

#include <stdio.h>
#define MAX 5

int s[MAX];     // Stack array
int top = -1;   // Top pointer

// Pop function: removes and returns the top element
int pop() {
    if(top == -1) {   // Underflow check
        printf("Stack underflow!\n");
        return -1;
    }

    int item = s[top--];   // Return current top, then decrease
    printf("Popped: %d\n", item);
    return item;
}

int main() {
    int n, i;

    // Take initial number of elements
    printf("How many items to initialize (max %d): ", MAX);
    scanf("%d", &n);
    if(n > MAX) {
        n = MAX;
    }

    // Read elements and fill stack from bottom to top
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &s[++top]);
    }

    // Pop twice to demonstrate operation
    pop();
    pop();

    return 0;
}
