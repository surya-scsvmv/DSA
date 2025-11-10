/*
Aim:
To implement stack pop operation using arrays.
*/

#include <stdio.h>
#define MAX 5

int s[MAX], top = -1;

int pop() {
    if(top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    int item = s[top--];
    printf("Popped: %d\n", item);
    return item;
}

int main() {
    int n, i;
    printf("How many items to initialize (max 5): ");
    scanf("%d", &n);
    if(n > MAX) n = MAX;

    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++) {
        scanf("%d", &s[++top]);
    }

    pop();
    pop();
    return 0;
}
