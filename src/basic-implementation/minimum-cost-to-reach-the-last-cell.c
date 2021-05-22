#include <string.h>


int min(int x, int y) {
	return x > y ? y : x;
}


int min_matrix_path(int m, int n, int costs[m][n]) {
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
	return 0;
}
