#include <stdio.h>
#include <stdlib.h>
int main() {
	int In, Reverse;
	int H, T, O;
	float ave;
	scanf_s("%d", &In);
	H = In / 100;
	T = (In - H * 100) / 10;
	O = In - H * 100 - T * 10;
	Reverse = 100 * O + 10 * T + H;
	ave = (float) (In + Reverse) / 2;
	printf("%5.1f", ave);
	system("pause");
}
//兩數平均可能有小數，所以要在等號右邊加入float註解給程式知道，至於等號左邊則本來就應該初始宣告為float


/*
Q1: 怎麼確定到底要不要在某數前面轉換宣告類型(ex: int -> float)? //line12
Q2: 我在VS裡面被糾正要使用scanf_s，但是OJ卻不給scanf_s過? 兩者差異在於? //line7
A2:  因為VS主要是cpp，而c的某些東西在cpp會莫名其妙不能用，會需要再額外安插library去調用函式庫才可以
*/