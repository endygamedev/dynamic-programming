#include <string.h>
#include <stdio.h>


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


void test_1();
void test_2();


int main(void) {
	test_1();
	test_2();
}


void test_1() {
	int coins[] = {1, 3, 5, 7};
	int amount = 8;
	int n = sizeof(coins)/sizeof(coins[0]);
	printf("%d\n", coin_change(n, coins, amount));
}


void test_2() {
	int coins[] = {1, 2, 3};
	int amount = 4;
	int n = sizeof(coins)/sizeof(coins[0]);
	printf("%d\n", coin_change(n, coins, amount));
}
