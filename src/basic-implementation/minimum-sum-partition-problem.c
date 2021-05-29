#include <stdio.h>
#include <stdlib.h>


int min(int x, int y) {
	return x > y ? y : x;
}


int min_sum_partition(int n, int s[n], int s1, int s2) {
	if(n < 0)
		return abs(s1-s2);
	int inc = min_sum_partition(n-1, s, s1+s[n], s2);
	int exc = min_sum_partition(n-1, s, s1, s2+s[n]);
	return min(inc, exc);
}


void test_1();


int main(void) {
	test_1();
}


void test_1() {
	int s[] = {10, 20, 15, 5, 25};
	int n = sizeof(s)/sizeof(s[0]);
	printf("%d", min_sum_partition(n, s, 0, 0));
}
