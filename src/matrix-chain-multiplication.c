#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int matrix_chain_multiplication(int* dims, int n) {
    /*
    description:
    finds the minimum number of operations
    required to multiply a chain of matrices

    input:
    dims - dimensions of matrices,
    that is, matrices have dimensions (dims[0], dims[1]),
    (dims[1], dims[2]) etc.
    n - number of matrices

    output:
    minimum number of operations
    */
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
    int dims_1[] = {10, 30, 5, 60};
    int dims_2[] = {20, 40, 15, 30, 6};

    if(matrix_chain_multiplication(dims_1, 4) == 4500)
        printf("test 1 passed\n");
    else printf("test 1 failed\n");

    if(matrix_chain_multiplication(dims_2, 5) == 11100)
        printf("test 2 passed\n");
    else printf("test 2 failed\n");

	return 0;
}
