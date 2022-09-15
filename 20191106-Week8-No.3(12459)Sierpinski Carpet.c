#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)
#define multiple 9

unsigned long long black_blocks(int Now, int goal);
unsigned long long power(int base, int index);

int main() {
	int k;
	scanf("%d", &k);
	printf("%llu\n", black_blocks(k, 0));
	system("pause");
}

unsigned long long black_blocks(int Now, int goal) {
	if (Now == goal) return 0;
	else {
		unsigned long long temp;
		temp = black_blocks(Now - 1, 0) + power(multiple - 1, Now - 1);
		return temp;
	}
}//因為此題比較簡單，可以用數學的遞迴關係來想，所以我列a0 = 0; [a(n)] = [a(n-1)] + [(9-1)^(n-1)]來計算


unsigned long long power(int base, int index) {
	if (index == 0) return 1;
	else if (index & 1) {
		unsigned long long temp = power(base, index / 2);
		return temp * temp*base;
	}
	else {
		unsigned long long temp = power(base, index / 2);
		return temp * temp;
	}
}