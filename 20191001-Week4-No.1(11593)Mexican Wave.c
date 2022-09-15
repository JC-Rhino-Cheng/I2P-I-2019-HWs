#include <stdio.h>
#include <stdlib.h>

int main() {
	int T;//可提供輸入最多100組不同的(n, m, t)組合的資料
	int n[100], m[100], t[100];//第一組紀錄在(n0, m0, t0)，第100組紀錄在(n99, m99, t99)
	int start_prting_sym[100], end_prting_sym[100];//由數學計算出在這一組數據當中的第幾位觀眾開始(包含)要站、第幾位觀眾是最後一個站之後的第一位不站
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf_s("%d%d%d", &n[i], &m[i], &t[i]); //記錄第0組~第T-1組共T組數據
		start_prting_sym[i] = t[i] - m[i];//記錄第幾位觀眾開始(包含)要站
		end_prting_sym[i] = t[i];//記錄第幾位觀眾是最後一個站之後的第一位不站
	}
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < n[i]; j++) {//因為每一組的觀眾人數可能不同，所以我要給出j<n[i]的條件，控制一組之內輸出的符號數等於n[i]個
			if ( j >= start_prting_sym[i] && j < end_prting_sym[i] ) printf("^");
			else printf("-");
		}
		printf("\n");
	}//line14~20的大迴圈，執行一次就是"一組的輸出已經完成但未換行"之後"換行"
	system("pause");
}
