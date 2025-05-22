#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int board[MAX], count = 0;

void printSolution(int n) {
    printf("Solution %d:\n", ++count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (board[j] == i || abs(board[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

void nQueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (isSafe(k, i)) {
            board[k] = i;
            if (k == n)
                printSolution(n);
            else
                nQueen(k + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    nQueen(1, n);
    if (count == 0)
        printf("No solutions exist for %d queens.\n", n);
    else
        printf("Total solutions: %d\n", count);
    return 0;
}