#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int matrix_chain_multiplication(int* dims, int n) {
    int C[n + 1][n + 1];

    for(int i = 1; i <= n; i++)
        C[i][i] = 0;

    for(int len = 2; len <= n; len++) {
        for(int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            C[i][j] = INT_MAX;

            for(int k = i; j < n && k <= j - 1; k++) {
                int cost = C[i][k] + C[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if(cost < C[i][j])
                    C[i][j] = cost;
            }
        }
    }
    return C[1][n - 1];
}


int main(void) {
    int dims[] = {10, 30, 5, 60};
    printf("%d\n", matrix_chain_multiplication(dims, 4)); //4500
	return 0;
}
