#include <stdio.h>
#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;
    int weight[MAX], value[MAX];
    int dp[MAX][MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &W);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    for(int i= 0; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(i ==0 || j==0)
                dp[i][j] = 0;
            else if(weight[i-1] <=j)
                dp[i][j] = max(value[i-1] + dp[i-1][j-weight[i-1]],dp[i-1][j]);
            else    
                dp[i][j] = dp[i-1][j];
        }
    }

    printf("Maximum value in knapsack: %d\n", dp[n][W]);
    return 0;
}