/*
  Aim:
  To perform Binary Search on a sorted array.
*/

#include <stdio.h>

int main() {
    int n, i, key, low, high, mid, found = 0;

    // Take number of elements
    printf("Enter how many elements: ");
    scanf("%d", &n);

    int arr[n];

    // Read the sorted array
    printf("Enter %d elements (sorted): ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Binary search boundaries
    low = 0;
    high = n - 1;

    // Standard binary search loop
    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {           // Element found
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if(arr[mid] < key) {       // Search in right half
            low = mid + 1;
        }
        else {                          // Search in left half
            high = mid - 1;
        }
    }

    if(found == 0) {
        printf("Element not found!\n");
    }

    return 0;
}
