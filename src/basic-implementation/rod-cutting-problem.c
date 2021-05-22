#include <stdio.h>


int rod_cut(int costs[], int n){	/*task 24*/
    int C[n + 1];
    memset(C, 0, sizeof(C));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            C[i] = max(C[i], costs[j - 1] + C[i - j]);
        }
    }
    return C[n];
}


int main(void) {
    int price[] = {1, 5 ,8, 9, 10, 17, 20};
    printf("%d", rod_cut(price, 4));	/*10*/
}
