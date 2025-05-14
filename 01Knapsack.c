#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n + 1], profit[n + 1];

    printf("Enter weights of items:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits of items:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &profit[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int v[n + 1][W + 1];

    // Build table v[][] in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (weight[i] > j)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], v[i - 1][j - weight[i]] + profit[i]);
        }
    }

    printf("Maximum profit: %d\n", v[n][W]);

    return 0;
}
