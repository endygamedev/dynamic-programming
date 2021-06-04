#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int min(int x, int y) {
	return x > y ? y : x;
}


void change_making_table(int n, int coins[n], int amount, int table[n+1][amount+1]) {
	memset(table, 0, sizeof(table[0][0]) * (n+1) * (amount+1));

	for(int i = 0; i < amount+1; i++)
		table[0][i] = i;

	for(int i = 1; i < n+1; i++) {
		for(int j = 1; j < amount+1; j++) {
			if(coins[i-1] == j) {
				table[i][j] = 1;
			} else if(coins[i-1] > j) {
				table[i][j] = table[i-1][j];
			} else {
				table[i][j] = min(table[i-1][j], 1 + table[i][j-coins[i-1]]);
			}
		}
	}
}


void change_making_coins(int n, int coins[n], int amount, int change[n]) {
	memset(change, 0, sizeof(change[0]) * n);
	int table[n+1][amount+1];
	change_making_table(n, coins, amount, table);
	int i = n, j = amount;
	while(j > 0) {
		if(table[i][j-coins[i-1]] == table[i][j]-1) {
			change[i-1] += 1;
			j -= coins[i-1];
		} else {
			i--;
		}
	}
}
