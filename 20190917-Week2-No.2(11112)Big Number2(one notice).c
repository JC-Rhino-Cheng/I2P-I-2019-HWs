#include <stdio.h>
#include <stdlib.h>
int first4(int x) {
	return x / 10000;
}
int last4(int x) {
	return x % 10000;
}
int first8(int x) {
	return x / 100000000;
}
int last8(int x) {
	return x % 100000000;
}
int shift4(int x) {
	return x * 10000;
}
int main(void) {
	int x;
	int a, b;
	int c1, c2, c3;
	/* Assume that the input is always an 8-digit positive integer. */
	scanf("%d", &x);
	a = first4(x);//1234
	b = last4(x);//5678
	c3 = last4((b * b));
	c2 = shift4(last4(a * a)) + 2 * a*b + first4((b * b));
	c1 = first4((a * a));
	//if (first8(c2) != 0) {
		int JinWei;
		JinWei = first8(c2);
		c2 = last8(c2);
		c1 += JinWei;
	//}
	printf("%4d%08d%04d", c1, c2, c3);
	return 0;
}

/*
Note1: 注意: printf的語法中，%4d和%04d是不一樣的!%4d是指如果不滿四位數則
補"空格"，而%04d是補"0"!!!!//line35
*/