#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

#define BIGINT_WIDTH 4//每一組都有"4"個數字，則16個數字分為4組
#define BIGINT_BASE 10000//因為每組都是4個數字，所以要%"10000"才會出現4位數的餘數
#define DIGIT_NUM 16//輸入的是總共"16"位數的數
#define NUM_SIZE (DIGIT_NUM/BIGINT_WIDTH)//每一組都有4個數字，則16個數字分為"4"組
#define ANS_SIZE (NUM_SIZE*2)//經由分段處理過後，會變成總共有ANS_SIZE段相加(詳見OJ)

int main() {
	freopen("sample.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int num[NUM_SIZE] = { 0 }; // store input number (under base 10000)
	int ans[ANS_SIZE] = { 0 }; // store answer (under base 10000)
	char input[DIGIT_NUM];   // store input nunber (under base 10)

	for (int i = 0; i < DIGIT_NUM; i++) scanf("%c", &input[i]);//因為16位數已經超過long long的上限，而又不可能叫輸入者分段輸入，所以把輸入的16位數全部用char讀入。

	for (int d = 0; d < DIGIT_NUM; d++) {//把line18所讀入的char轉換成int才能運算，與此同時還得進行所輸入的數字的分組，否則會像使用者直接輸入16位數一樣爆掉。
		int num_idx = (DIGIT_NUM - d - 1) / BIGINT_WIDTH;
		num[ NUM_SIZE - num_idx - 1] *= 10;
		num[NUM_SIZE - num_idx - 1] += input[d] - '0';
	}//假設16位數字是1234567887654321，整個迴圈弄完後，數字也分組完畢，變成: num[0]=1234; num[1]=5678; num[2]=8765; num[3]=4321。

	// TODO: multiplication，欲理解此迴圈的想法，請列直式乘法，上排從左到右依序為up[0]、up[1]、up[2]、up[3]; 下排依序down[0]、down[1]、down[2]、down[3]。則: ans[6]=up[0]*d[0]。ans[5]= up[0]d[1]+up[1]d[0]。....etc。至於ans[7]=0，反正之後必進位。
	for (int up = 0; up < NUM_SIZE; up++)//up指直式乘法的被乘數的編號
		for (int down = 0; down < NUM_SIZE; down++)//down指直式乘法的乘數的編號
			ans[ANS_SIZE - up - down - 2] += num[up] * num[down];

	// TODO: deal with carry (處理進位)
	for (int d = 0; d < ANS_SIZE - 1; d++) {
		int jinwei = ans[d] / BIGINT_BASE;
		ans[d] %= BIGINT_BASE;
		ans[d + 1] += jinwei;
	}

	// print answer
	printf("%4d", ans[ANS_SIZE - 1]);
	for (int d = ANS_SIZE - 2; d >= 0; d--) printf("%04d", ans[d]);
	printf("\n");

	system("pause");
}

/*回去看https://acm.cs.nthu.edu.tw/problem/11112/ (20190917-Week2-No.2(11112)Big Number)
會很有成就感*/