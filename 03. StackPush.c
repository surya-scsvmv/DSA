/*
Aim:
To implement stack push operation using arrays.
*/

#include <stdio.h>
#define MAX 5

int s[MAX], top = -1;

void push(int x) {
    if(top == MAX-1) {
        printf("Stack full!\n");
        return;
    }
    s[++top] = x;
    printf("Pushed %d\n", x);
}

int main() {
    int n, val;
    printf("How many items to push (max %d): ", MAX);
    scanf("%d", &n);
    if(n > MAX) n = MAX;

    for(int i=0;i<n;i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        push(val);
    }

    return 0;
}
