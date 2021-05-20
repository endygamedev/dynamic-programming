#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int min(int x, int y) {
	return x > y ? y : x;
}


int find_min_matrix_path(int costs[5][5]) {
    int C[5][5];
    memset(C, 0, sizeof(C));
    C[0][0] = costs[0][0];

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i == 0 && j > 0) {
                C[0][j] = C[0][j - 1] + costs[0][j];
            } else if(j == 0 && i > 0) {
                C[i][0] += C[i - 1][0] + costs[i][0];
            } else if(i > 0 && j > 0) {
                C[i][j] += min(C[i - 1][j], C[i][j - 1]) + costs[i][j];
            }
        }
    }
    return C[4][4];
}

int main(void) {
	return 0;
}
