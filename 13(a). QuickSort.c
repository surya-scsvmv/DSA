/*
  Aim:
  Implement Quick Sort using the divide-and-conquer strategy
  with partitioning to sort an array of integers.
*/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1, j = high;

    while (i <= j) {
        while (a[i] <= pivot && i <= high)
            i++;
        while (a[j] > pivot && j >= low)
            j--;

        if (i < j)
            swap(&a[i], &a[j]);
    }

    swap(&a[low], &a[j]);
    return j;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    int a[50], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
