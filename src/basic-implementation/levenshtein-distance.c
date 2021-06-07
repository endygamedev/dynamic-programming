#include <stdio.h>
#include <string.h>


int min(int x, int y) {
	return x > y ? y : x;
}


int levenshtein_distance_arr(char * x_string, char * y_string) {
    /*
		Description:
		============
			calculates the Levenshtein distance between two strings

		Arguments:
		----------
			* x, y - given strings

		Output:
		-------
			the Levenshtein distance
    */

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
			sub_cost = x_string[i - 1] == y_string[j - 1] ? 0 : 1;
			D[i][j] = min(min(D[i - 1][j] + 1, D[i][j - 1] + 1),
								D[i - 1][j - 1] + sub_cost);
		}
	}
	return D[m][n];
}


int main(void) {
    if(levenshtein_distance_arr("kitten", "sitting") == 3)
        printf("test 1 passed\n");
    else printf("test 1 failed\n");

    if(levenshtein_distance_arr("roma", "fokar") == 3)
        printf("test 2 passed\n");
    else printf("test 2 failed\n");
}
