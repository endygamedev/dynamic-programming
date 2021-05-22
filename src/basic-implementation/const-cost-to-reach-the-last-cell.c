#include <stdio.h>


int const_cost_matrix_path_rec(int m, int n, int costs[m][n], int rest_cost) {	/*task 17*/
	/*maybe it is necessary use single linked list for dictionary*/
	/*moving in the opposite direction, from the last element to the first*/
	/*if there are no paths with incalculable cost*/
    if(rest_cost < 0)
        return 0;
	/*if the first cell is reached*/
    if (m == 0 && n == 0) {
        if(costs[0][0] - rest_cost == 0) {
            return 1;
        } else {
            return 0;
        }
    }
	/*if movement along the edge*/
    if(n == 0) {
        return const_cost_matrix_path_rec(m - 1, 0, costs, rest_cost - costs[m][n]);
    } else if(m == 0) {
        return const_cost_matrix_path_rec(0, n - 1, costs, rest_cost - costs[m][n]);
    } else {
        return const_cost_matrix_path_rec(m - 1, n, costs, rest_cost - costs[m][n]) +
                const_cost_matrix_path_rec(m, n - 1, costs, rest_cost - costs[m][n]);
    }
}


int main(void) {
    int cost[4][4] = {
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 }
    };
    printf("%d\n", const_cost_matrix_path_rec(3, 3, cost, 7));	/*20*/
}
