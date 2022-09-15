#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#pragma warning (disable: 4996)

void DFS(int, int, int, int);

unsigned short N, X[10];//N: 總共有N張卡片。X[i]:第i張卡片上的數字是X[i]。
bool flag_card_used[10];
bool flag_solution_found;

int main() {
	unsigned short T; scanf("%hu", &T);//總共有T筆測資。
	while (T--) {
		memset(flag_card_used, sizeof(flag_card_used), false);//每一筆新的測資，都要重設所有卡片使用情況為: 未使用。
		flag_solution_found = false;//每一筆新的測資，都要重設狀態為: 還沒找到solution

		scanf("%hu", &N);//先讀入到底有多少張卡片?
		unsigned sum_of_all_cards = 0;
		for (int i = 0; i < N; i++) {
			scanf("%hu", &X[i]);
			sum_of_all_cards += X[i];
		}//再把所有卡片上的數字讀入，並計算加總。要注意!!!卡片上的數字加總，一定會等於所有column值的加總。而因為所有column又都各自是卡片堆的總和，所以，卡片上的所有數字總和就會等於每個column內部總和的總和。下面的「if (sum_of_all_cards%num_of_columns != 0) continue;」就是這個想法。

		//以下進入遞迴概念階段。因為如果有N張卡片，就最多有N個可行的column。
		unsigned short num_of_columns = N;
		for (; num_of_columns > 1; num_of_columns--) {
			if (sum_of_all_cards%num_of_columns != 0) continue;//如果每個column內部的總和不是整數，就不可能正確，不要浪費時空去遞迴。

			DFS(num_of_columns, 0, sum_of_all_cards / num_of_columns, 0);
			if (flag_solution_found) break;//如果每個column內部的總和是正確的，那就有可能有可行的組合。如果找到了可行的組合，那太棒了，因為這就是我要的答案，所以break後直接print出來。如果找不到可行的組合，那就column數-1，再去試試看能不能可行，並在新的column數底下成功找到組合。
		}//如果連column數=2都找不到可行組合，那就column數--，變成1。但是因為column==1一定能找到組合，所以乾脆就不遞迴了，所以for迴圈直接不進入iteration。
		printf("%hu\n", num_of_columns);
	}
	system("pause");
}

void DFS(int goal_of_num_of_columns, int now_num_of_columns, int goal_of_each_column, int total_IN_now_column) {
	if (now_num_of_columns == goal_of_num_of_columns) { flag_solution_found = true; return; }

	for (int i = 0; i < N && !flag_solution_found; i++) {
		if (flag_card_used[i])continue;

		flag_card_used[i] = true;
		if (total_IN_now_column + X[i] < goal_of_each_column) DFS(goal_of_num_of_columns, now_num_of_columns, goal_of_each_column, total_IN_now_column + X[i]);
		else if (total_IN_now_column + X[i] == goal_of_each_column) DFS(goal_of_num_of_columns, now_num_of_columns + 1, goal_of_each_column, 0);
		flag_card_used[i] = false;
	}
}