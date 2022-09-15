#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable: 4996)

long long sum_of_element_from_one_to_now[1000000];//N 已確認最大為1000000。Notice1見下方

int main(){
	freopen("sample.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;//N 已確認最大為1000000
	int M;//總共有M筆query，一筆query裡面包含left-bound和right-bound
	int element_input_now;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &element_input_now);
		sum_of_element_from_one_to_now[i] =sum_of_element_from_one_to_now[ i -1 ] + element_input_now;
	}
	scanf("%d", &M);
	while( M--  ){
		int leftbound, rightbound;
		scanf("%d%d", &leftbound, &rightbound);
		printf("%lld\n", sum_of_element_from_one_to_now[rightbound] - sum_of_element_from_one_to_now[leftbound - 1]);
	}
	system("pause");
}
/*
先來講本題概念。如果本題設計成先儲存所有array elements，之後再依照每個query去執行for迴圈加總的話，
一定會TLE。為改善此情形，便設計成:
S1 = a1 
S2 = S1 + a2
S3 = S2 + a3
S4 = S3 + a4
.....
SN = S[N-1] + aN
，之後每次要輸出的時候，再用兩個S去相減，即可得到區間的S。例如: a3 + .... + a7 = S7 - S2。
那為了之後計算第幾個的時候的方便性起見，從S1開始才存入數字。S0 則保持=0。
因此，S1又可改寫為: S1 = S0 + a1，在設計for迴圈時又更方便了。

Notice1: S5、S6、....、SN的數值可能非常大，所以採用long long。要注意: 相應的printf時要改成%lld
*/