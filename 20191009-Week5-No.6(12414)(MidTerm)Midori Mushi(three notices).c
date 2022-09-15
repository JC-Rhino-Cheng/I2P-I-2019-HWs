#include <stdlib.h>
#include <stdio.h>
#define speed 10
#pragma warning (disable: 4996)

int main() {
	freopen("sample.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int time_initial = 0, time_last, time_span;
	short option;//0: 右轉; 1:左轉; 2:停止
	short direction = 1;//1: northbound; 2: eastbound; 3: southbound; 0: westbound. 當右轉時，direction++(記得%4)。當左轉時，direction--(但因為可能為負，所以當direction<0時要direction+=4)
	short dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };//Notice1見下面
	int x_now = 0, y_now = 0;
	scanf("%d%hd", &time_last, &option);//Notice2見下面
	
	while (option != 2) {
		time_span = time_last - time_initial;
		x_now += (dx[direction] * time_span * speed); y_now += (dy[direction] * time_span * speed);//Notice3見下面
		if (option == 0) direction = (direction + 1) % 4;//因為我只設定direction範圍在0~3閉區間，所以當direction++>=4時，就必須%4
		else if (option == 1) {
			direction--;
			if (direction < 0) direction += 4;//因為我只設定direction範圍在0~3閉區間，所以當direction--<0時(即direction==-1時，因為不可能direction<=-2，主要因為早就在direction==-1時就處理掉了)讓direction+=4
		}
		time_initial = time_last;
		scanf("%d%hd", &time_last, &option);
	}
	time_span = time_last - time_initial;//當option=2時，就跳出迴圈了，但是還沒有計算最後一次的移動，所以用line26~27補足
	x_now += (dx[direction] * time_span * speed); y_now += (dy[direction] * time_span * speed);
	printf("%d %d\n", x_now, y_now);

	system("pause");
}
/*
Notice1: 自己要注意啊!direction最開始是1，所以要寫在dx['1']、dy['1']的位置!!!一開始沒注意到，
所以按照順序把direction=1、2、3、0寫在dx['0']dy['0']、dx['1']dy['1']、dx['2']dy['2']、dx['3']dy['3']，就一定錯
Notice2: 自己弄了不同種的type，就要記得寫與之對應的%d%hd%ld%lld%u%hu%lu%llu阿!!!不然一樣會計算錯誤
Notice3: 要注意，當是array時，是[]，而不是()!!!()是function呼叫!!!莫搞錯!!!

註: 不管是助教版本還是CSST的https://hackmd.io/PwydSrcjSQ-sCPNqJrQU0A?view，寫法都比我精簡，但是想法一模一樣，所以可以模仿學習。
*/