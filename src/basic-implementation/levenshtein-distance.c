#include <stdio.h>
#include <string.h>


int min(int x, int y) {
	return x > y ? y : x;
}


int levenshtein_distance_rec(char * x_string, int m, char * y_string, int n) {

	if(m == 0)
		return n;

	if(n == 0)
		return m;

	int cost;
	if(x_string[m - 1] == y_string[n - 1]) {
		cost = 0;
	} else {
		cost = 1;
	}
	return min(min(levenshtein_distance_rec(x_string, m - 1, y_string, n) + 1,
					levenshtein_distance_rec(x_string, m, y_string, n - 1)),
					levenshtein_distance_rec(x_string, m - 1, y_string, n - 1) + cost);
}


int levenshtein_distance_arr(char * x_string, int m, char * y_string, int n) {
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


int levenshtein_distance(char * x_string, char * y_string) {
	int m = strlen(x_string), n = strlen(y_string);
	return levenshtein_distance_arr(x_string, m, y_string, n);
}


int main(void) {
	printf("%d", levenshtein_distance("kitten", "sitting"));	/*3*/
}
