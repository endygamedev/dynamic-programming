#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>


int min(int x, int y) {
	return x > y ? y : x;
}


int max(int x, int y) {
	return x < y ? y : x;
}


int min_sum_partition1(long n, int s[n], int s1, int s2) {
	if(n < 0)
		return abs(s1-s2);
	int inc = min_sum_partition1(n-1, s, s1+s[n], s2);
	int exc = min_sum_partition1(n-1, s, s1, s2+s[n]);
	return min(inc, exc);
}


void coin_change_table(int n, int coins[n], int amount, int table[n+1][amount+1]) {
	memset(table, 0, sizeof(table[0][0]) * (n+1) * (amount+1));

	for(int i = 0; i < n+1; i++)
		table[i][0] = 1;

	for(int i = 1; i < n+1; i++)
		for(int j = 1; j < amount+1; j++)
			table[i][j] = coins[i-1] > j ? table[i-1][j] : table[i-1][j] + table[i][j-coins[i-1]];
}


int coin_change(int n, int coins[n], int amount) {
	int table[n+1][amount+1];
	coin_change_table(n, coins, amount, table);
	return table[n][amount];
}


int const_cost_matrix_path(int m, int n, int costs[m][n], int k){//done
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


int levenshtein_distance(char * x_string, char * y_string) {
    int m = strlen(x_string), n = strlen(y_string);
	char D[m + 1][n + 1];
	memset(D, 0, sizeof(D));
	int sub_cost;

	for(int i = 1; i <= m; i++)
		D[i][0] = i;

	for(int i = 1; i <= n; i++)
		D[0][i] = i;

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(x_string[i - 1] == y_string[j - 1]){
				sub_cost = 0;
			} else {
				sub_cost = 1;
			}
			D[i][j] = min(min(D[i - 1][j] + 1, D[i][j - 1] + 1),
								D[i - 1][j - 1] + sub_cost);
		}
	}
	return D[m][n];
}


int matrix_chain_multiplication(int n, int dims[n]) {//done
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


int min_matrix_path(int m, int n, int costs[m][n]) {//done
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


int binary_strings_without_ones(int n){//done
    int counts[n][2];
    counts[0][0] = 1;
    counts[0][1] = 1;

    for(int i = 1; i < n; i++){
        counts[i][0] = counts[i - 1][0] + counts[i - 1][1];
        counts[i][1] = counts[i - 1][0];
    }
    return counts[n - 1][0] + counts[n - 1][1];
}


int rod_cut(int costs[], int n){
    int C[n + 1];
    memset(C, 0, sizeof(C));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            C[i] = max(C[i], costs[j - 1] + C[i - j]);
        }
    }

    return C[n];
}
