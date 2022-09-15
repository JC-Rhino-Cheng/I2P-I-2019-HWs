#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable: 4996)

int whom_to_move[100005];//m is guaranteed to be less than 100000;
int flag_of_all_Nums[200005];//因為共有n個數字，所以我要儲存總共n個狀態。數字1的狀態，就對應到flag_of_all_Nums[1]。狀態0: 沒被移動; 1: 有被移動; 2: 已經被印出

int main() {
	//freopen("sample.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	//此行具有警醒意義
	int input;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {//編號0~m-1，總共m個數字是要被移動的
		scanf("%d", &whom_to_move[i]);//"依序"把m個數字讀入
		flag_of_all_Nums[whom_to_move[i]] = 1;//把被讀入的數字的狀態設為1
	}
	for (int i = m - 1; i >= 0; i--) {//從最晚被移動的數字開始。注意: 這個迴圈只探討有被移動的數字的輸出!!!!所以迴圈內會有if判斷。之後的另個迴圈會再處理沒被移動的數字
		if (flag_of_all_Nums[whom_to_move[i]] == 1) {//當想要移動的這些數字的序列裡面的狀態確定是1時，輸出這個狀態是1的值。(因為可能會有已經被輸出而被flag為2的數值，所以還是要確保下)
			printf("%d\n", whom_to_move[i]);
			flag_of_all_Nums[whom_to_move[i]] = 2;//在輸出完這個值以後，把flag改成2
		}
	}//有被移動的數字都已經被輸出完了
	for (int i = 1; i <= n; i++) {//現在換輸出沒被輸出過的數字
		if (flag_of_all_Nums[i] == 0) printf("%d\n", i);
	}

	system("pause");
}
/*
程式邏輯想法見: https://hackmd.io/Do4_mpPvTYGMsJgzCuzbcw?view
或參考ppt內容
*/
/*
Notice1: 注意: 原本line5~6的內容是寫在line12，結果OJ死都只有3/4，然後Visual Studio跳出: Stack Overflow。
哇! 驚天動地的提醒! 瞬間想起老師最新一次上課才提到，如果一個array元素過多，會有部分compiler不接受此變數被宣告在function內。
所以如果array元素很大的話，一律建議直接擺在include 後面，這樣就OK了。
*/