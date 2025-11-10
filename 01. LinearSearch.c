/*
Aim:
To perform Linear Search on an array to find a given element.
*/

#include <stdio.h>

int main() {
    int n, i, key;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    printf("Enter element to find: ");
    scanf("%d", &key);

    for(i=0;i<n;i++) {
        if(a[i] == key) {
            printf("Element found at position %d\n", i+1);
            return 0;
        }
    }

    printf("Element not found :(\n");
    return 0;
}
