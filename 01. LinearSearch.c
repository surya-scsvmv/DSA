/*
  Aim:
  Perform Linear Search on an array and locate a given element.
*/

#include <stdio.h>

int main() {
    int n, i, key;

    // Take array size from user
    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];  // Create array of given size

    // Read array elements
    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Read the element to search for
    printf("Enter element to find: ");
    scanf("%d", &key);

    // Linear search logic: scan from left to right
    for(i = 0; i < n; i++) {
        if(a[i] == key) {   // Found the element
            printf("Element found at position %d\n", i + 1);
            return 0;
        }
    }

    // If loop ends, element wasn’t found
    printf("Element not found\n");
    return 0;
}
