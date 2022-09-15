#include <stdio.h>
#include <stdlib.h>

int main() {
	int k;
	int a[5] = { 0, 1, 2, 3, 4 };
	int swap[24][2];
	int temp_a, temp_b;
	scanf_s("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf_s("%d%d", &swap[i][0], &swap[i][1]);
	}
	for (int i = 0; i < k; i++) {
		temp_a = a[swap[i][0]];
		temp_b = a[swap[i][1]];
		a[swap[i][1]] = temp_a;
		a[swap[i][0]] = temp_b;
	}
	for (int i = 0; i < 5; i++) {
		printf("%d", a[i]);
		if (i != 4)printf(" ");
	}//Notice1見下方
	system("pause");
}

/*
Notice1: 我原本for迴圈裡面是printf("%d ", a[i]);，之後在for迴圈外再多一行printf("\b");
來消除最後一個多餘的空格，但是不給過(回報:Presentation Error)。所以只好改寫為
printf("%d", a[i]);
if (i != 4)printf(" ");
所以以後還得注意OJ可能不接受\b呈現在程式最末端的指令。
*/