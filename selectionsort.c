#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionsort(int a[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(NULL));

    printf("\nUnsorted Numbers:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
        printf("%d ", arr[i]);
    }

    clock_t st, ed;
    double tt;

    st = clock();
    selectionsort(arr, n);
    ed = clock();

    tt = ((double)(ed - st)) / CLOCKS_PER_SEC;

    printf("\n\nSorted Numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime taken to sort: %f seconds\n", tt);

    return 0;
}