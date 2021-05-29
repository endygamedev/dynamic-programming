#include <stdio.h>


int min(int x, int y) {
	return x > y ? y : x;
}

int min_matrix_path(int m, int n, int costs[m][n]) {
    /*
    description: looking for a minimum cost path
    from the top-left element
    to the bottom-right element of the matrix

    input:
    m, n - size of cost matrix costs[m][n]

    output:
    minimum cost path length
    */
    int C[m][n];
    memset(C, 0, sizeof(C));
    C[0][0] = costs[0][0];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j > 0) {
                C[0][j] = C[0][j - 1] + costs[0][j];
            } else if(j == 0 && i > 0) {
                C[i][0] += C[i - 1][0] + costs[i][0];
            } else if(i > 0 && j > 0) {
                C[i][j] += min(C[i - 1][j], C[i][j - 1]) + costs[i][j];
            }
        }
    }
    return C[m - 1][n - 1];
}


int main(void) {

    int costs_1[5][5] = {
        { 4, 7, 8, 6, 4 },
        { 6, 7, 3, 9, 2 },
        { 3, 8, 1, 2, 4 },
        { 7, 1, 7, 3, 7 },
        { 2, 9, 8, 9, 3 }
    };

    int costs_2[4][4] = {
        { 4, 7, 1, 6 },
        { 5, 7, 3, 9 },
        { 3, 2, 1, 2 },
        { 7, 1, 6, 3 }
    };

    int costs_3[4][5] = {
        { 4, 7, 1, 6 ,5 },
        { 5, 7, 3, 9, 1 },
        { 3, 2, 1, 2, 1 },
        { 7, 1, 6, 3, 10 }
    };

    if(min_matrix_path(5, 5, costs_1) == 36)
        printf("test 1 passed\n");
    else printf("test 1 failed\n");

    if(min_matrix_path(4, 4, costs_2) == 20)
        printf("test 2 passed\n");
    else printf("test 2 failed\n");

    if(min_matrix_path(4, 5, costs_3) == 28)
        printf("test 3 passed\n");
    else printf("test 3 failed\n");

	return 0;
}
