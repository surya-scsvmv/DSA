/*
Aim:
To perform Binary Search on a sorted array.
*/

#include <stdio.h>

int main() {
    int n, i, key, low, high, mid, found = 0;
    printf("Enter how many elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements (sorted): ", n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n-1;

    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("Element found at position %d\n", mid+1);
            found = 1;
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(found == 0)
        printf("Element not found!\n");

    return 0;
}
