#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int low, int high) {
    int pivot = a[low];  // Choosing first element as pivot
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && a[i] <= pivot) i++;
        while (j >= low && a[j] > pivot) j--;

        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Swap pivot element with correct position
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j; // Return partition index
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(a, low, high);
        quicksort(a, low, pivotIndex - 1);
        quicksort(a, pivotIndex + 1, high);
    }
}

int main() {
    int a[10000], n;

    printf("Enter the number of elements (max 10000): ");
    scanf("%d", &n);
    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    quicksort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}