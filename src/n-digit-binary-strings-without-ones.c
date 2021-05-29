#include <stdio.h>

int binary_strings_without_ones(int n){
    /*
    description:
    finds the number of binary strings
    of length n in which there are no adjacent ones

    input:
    n - length of strings

    output:
    number of strings
    */
    int counts[n][2];
    counts[0][0] = 1;
    counts[0][1] = 1;

    for(int i = 1; i < n; i++){
        counts[i][0] = counts[i - 1][0] + counts[i - 1][1];
        counts[i][1] = counts[i - 1][0];
    }
    return counts[n - 1][0] + counts[n - 1][1];
}

int main(void) {
    if(binary_strings_without_ones(5) == 13)
        printf("test 1 passed\n");
    else printf("test 1 failed\n");

    if(binary_strings_without_ones(15) == 1597)
        printf("test 2 passed\n");
    else printf("test 2 failed\n");

    if(binary_strings_without_ones(27) == 514229)
        printf("test 3 passed\n");
    else printf("test 3 failed\n");

	return 0;
}
