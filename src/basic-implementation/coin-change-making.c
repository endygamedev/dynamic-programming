#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct change_making {
	int n;
	int* coins;
	int amount;
	int val;
	int* change;
} change_making;


void change_making_table(int n, int coins[n], int amount, int table[n+1][amount+1]);
void change_making_coins(int n, int coins[n], int amount, int change[n]);


change_making * init(int n, int coins[n], int amount) {
	change_making *c = malloc(sizeof(change_making));
	int table[n+1][amount+1];
	int change[n];
	change_making_table(n, coins, amount, table);
	change_making_coins(n, coins, amount, change);
	c->n = n;
	c->coins = coins;
	c->amount = amount;
	c->change = change;
	return c;
}


void view(change_making *c) {
	printf("* Amount: %d\n"
			"* Number of coins: %d\n",
			c->amount, c->n);

	printf("* Type of coins: [ ");
	for(int i = 0; i < c->n; i++)
		printf("%d ", c->coins[i]);
	printf("]\n");

	printf("* Mask of coins: [ ");
	for(int i = 0; i < c->n; i++)
		printf("%d ", c->change[i]);
	printf("]\n\n");
}


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


void test_p01();
void test_p02();
void test_p03();


int main(void) {
	test_p01();
	test_p02();
	test_p03();
}



void test_p01() {
	int amount = 29;
	int coins[] = {1, 4, 5, 8, 11};
	int n = sizeof(coins)/sizeof(coins[0]);
	change_making *c = init(n, coins, amount);
	view(c);
}


void test_p02() {
	int amount = 96;
	int coins[] = {1, 5, 10, 25, 50, 100};
	int n = sizeof(coins)/sizeof(coins[0]);
	change_making *c = init(n, coins, amount);
	view(c);
}


void test_p03() {
	int amount = 96;
	int coins[] = {1, 2, 6, 12, 24, 48, 60};
	int n = sizeof(coins)/sizeof(coins[0]);
	change_making *c = init(n, coins, amount);
	view(c);
}
