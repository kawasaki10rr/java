#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int low, int high) {
    int mid = (low + high) / 2;
    int i = low;
    int j = mid + 1;
    int k = 0;
    int size = high - low + 1;
    int *b=(int *)malloc(size *sizeof(int));

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while (i <= mid) {
        b[k++] = a[i++];
    }

    while (j <= high) {
        b[k++] = a[j++];
    }

    for (int l = 0; l < size; l++) {
        a[low + l] = b[l];
    }
}

void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, high);
    }
}

int main() {
    int a[10000], n;
    printf("Enter the number of elements (max 20): ");
    scanf("%d", &n);

    srand(time(0));  // seed for random number generation
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;  // values between 0 and 99
    }

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    mergesort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
