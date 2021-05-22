#include <stdio.h>

int binary_strings_without_ones(int n){ //task 23
    int counts[n][2];
    counts[0][0] = 1;
    counts[0][1] = 1;

    for (int i = 1; i < n; i++){
        counts[i][0] = counts[i - 1][0] + counts[i - 1][1];
        counts[i][1] = counts[i - 1][0];
    }
    return counts[n - 1][0] + counts[n - 1][1];
}

int main(void) {
    printf("%d\n", binary_strings_without_ones(5)); //13
	return 0;
}
