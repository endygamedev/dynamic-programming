#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct knapsack {
	int w;
	int n;
	int* weights;
	int* values;
	int val;
	int* items;
} knapsack;


void knapsack_table(int w, int n, int weights[n], int values[n], int table[n+1][w+1]);
void knapsack_items(int w, int n, int weights[n], int values[n], int items[n]);


knapsack * init(int w, int n, int weights[n], int values[n]) {
	knapsack *knap = malloc(sizeof(knapsack));
	int table[n+1][w+1];
	int items[n];
	knapsack_table(w, n, weights, values, table);
	knapsack_items(w, n, weights, values, items);
	knap->w = w;
	knap->n = n;
	knap->weights = weights;
	knap->values = values;
	knap->val = table[n][w];
	knap->items = items;
	return knap;
}


void view(knapsack *knap) {
	printf("* Knapsack capacity: %d\n"
			"* Number of items in knapsack: %d\n",
			knap->w, knap->n);

	printf("* Weights for each item: [ ");
	for(int i = 0; i < knap->n; i++)
		printf("%d ", knap->weights[i]);
	printf("]\n");

	printf("* Values for each item: [ ");
	for(int i = 0; i < knap->n; i++)
		printf("%d ", knap->values[i]);
	printf("]\n");
	
	printf("* Optimal profit: %d\n", knap->val);

	printf("* Mask of items: [ ");
	for(int i = 0; i < knap->n; i++)
		printf("%d ", knap->items[i]);
	printf("]\n\n");
}


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


/* Test */
/* Took test datasets from: https://people.sc.fsu.edu/~jburkardt/datasets/knapsack_01/knapsack_01.html */

void test_p02();
void test_p04();
void test_p06();


int main(void) {
	test_p02();
	test_p04();
	test_p06();
}


void test_p02() {
	int w = 26;
	int weights[] = {12, 7, 11, 8, 9};
	int values[] = {24, 13, 23, 15, 16};
	int n = sizeof(weights)/sizeof(weights[0]);
	knapsack *knap = init(w, n, weights, values);
 	view(knap);
}


void test_p04() {
	int w = 190;
	int weights[] = {56, 59, 80, 64, 75, 17};
	int values[] = {50, 50, 64, 46, 50, 5};
	int n = sizeof(weights)/sizeof(weights[0]);
	knapsack *knap = init(w, n, weights, values);
 	view(knap);
}


void test_p06() {
	int w = 170;
	int weights[] = {41, 50, 49, 59, 55, 57, 60};
	int values[] = {442, 525, 511, 593, 546, 564, 617};
	int n = sizeof(weights)/sizeof(weights[0]);
	knapsack *knap = init(w, n, weights, values);
 	view(knap);
}
