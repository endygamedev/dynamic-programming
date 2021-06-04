#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int max(int x, int y) {
	return x > y ? x : y;
}


void knapsack_table(int w, int n, int weights[n], int values[n], int table[n+1][w+1]) {
	memset(table, 0, sizeof(table[0][0]) * (w+1) * (n+1));
	for(int i = 0; i < n+1; i++) {
		for(int j = 0; j < w+1; j++) {
			if(i == 0 || j == 0) {
				table[i][j] = 0;
			} else if(weights[i-1] <= j) {
				table[i][j] = max(values[i-1] + table[i-1][j-weights[i-1]], table[i-1][j]);
			} else {
				table[i][j] = table[i-1][j];
			}
		}
	}
}


void knapsack_items(int w, int n, int weights[n], int values[n], int items[n]) {
	memset(items, 0, sizeof(items[0])*n);
	int table[n+1][w+1];
	knapsack_table(w, n, weights, values, table);
	int val = table[n][w];
	for(int i = n; i > 0 && val > 0; i--) {
		if(val != table[i-1][w]) {
			items[i-1] = 1;
			val -= values[i-1];
			w -= weights[i-1];
		}
	}
}
