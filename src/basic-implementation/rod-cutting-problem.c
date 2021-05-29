#include <stdio.h>

int max(int x, int y) {
	return x < y ? y : x;
}

int rod_cut(int costs[], int n){
    /*
    description:
    finds the optimal way to cut a rod of length n
    into rods of shorter length at a given cost

    input:
    n - length of rod
    costs - a list of values, where a rod of length i costs costs[i]

    output:
    maximum profit
    */
    int C[n + 1];
    memset(C, 0, sizeof(C));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            C[i] = max(C[i], costs[j - 1] + C[i - j]);
        }
    }

    return C[n];
}

int main(void) {
    int price[] = {1, 5 ,8, 9, 10, 17, 20};

    if(rod_cut(price, 6) == 17)
        printf("test 1 passed\n");
    else printf("test 1 failed\n");

    if(rod_cut(price, 4) == 10)
        printf("test 2 passed\n");
    else printf("test 2 failed\n");

    if(rod_cut(price, 3) == 8)
        printf("test 3 passed\n");
    else printf("test 3 failed\n");

    return 0;
}
