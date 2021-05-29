#include <stdio.h>


int const_cost_matrix_path(int m, int n, int costs[m][n], int k){
    /*
    description:
    searches the given matrix for the path
    of the given cost from the top-left element
    to the bottom-right element of the matrix

    input:
    m, n - size of cost matrix costs[m][n]
    k - cost of the sought routes

    output:
    number of paths of a given cost
    */
    int C[m][n][k+1];
    memset(C, 0, sizeof(C));
    for(int i=0; i < m; i++){
        for(int j=0; j < n; j++){

            int tmp = costs[i][j];

            if(i == 0 && j == 0){
                C[0][0][k - tmp] += 1;
            }
            else if(i == 0){
                for(int s=0; s <= k; s++)
                    if(s - tmp >= 0)
                        C[0][j][s - tmp] += C[0][j - 1][s];

            }
            else if(j == 0){
                for(int s=0; s <= k; s++)
                    if(s - tmp >= 0)
                        C[i][0][s - tmp] += C[i - 1][0][s];
            }
            else{
                for(int s=0; s <= k; s++)
                    if(s - tmp >= 0)
                        C[i][j][s - tmp] += C[i - 1][j][s] + C[i][j - 1][s];
            }
        }
    }
    return C[m-1][n-1][0];
}


int main(void) {
    int cost_1[4][4] = {
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 2 }
    };

    int cost_2[4][4] = {
        { 4, 7, 1, 6 },
        { 5, 7, 3, 9 },
        { 3, 2, 1, 2 },
        { 7, 1, 6, 3 }
    };

    if(const_cost_matrix_path(4, 4, cost_1, 8) == 20)
        printf("test 1 passed\n");
    else printf("test 1 failed\n");

    if(const_cost_matrix_path(4, 4, cost_2, 25) == 2)
        printf("test 2 passed\n");
    else printf("test 2 failed\n");

}

