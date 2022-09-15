#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

int main() {
	int Num_of_partici;//參賽的人數，題目設定最多2000人
	unsigned int money_spent[2000];//每個人各自的花費，最多2000筆資料
	int prize;//紀錄我所抓取的人到底第幾名
	scanf("%d", &Num_of_partici);
	for(int i = 0 ; i < Num_of_partici ; i++) scanf("%u", &money_spent[i]);
	for(int i = 0 ; i < Num_of_partici ; i++){
		prize = 1;//每個人都先記錄為第一名，現在這個人是固定的i，要跟一排的不同的j比較
		for(int j = 0 ; j < Num_of_partici ; j++){
			if(money_spent[j] < money_spent[i]) prize++;//固定的i，要跟一排的不同的j比較，如果有人所花的錢比i少，i就退後一名
		}
		printf("%d", prize);//比較完之後，輸出名次和空隔
		if( i != Num_of_partici - 1) printf(" ");
	}
	printf("\n");
	system("pause");
}
/*
Notice: line16~17和line19我一開始用
printf("%d ")，printf("\n")，不行(presentation)，好吧那我後面那個改成printf("\b\n")，結果還是不行(wrong ans)
那我又改成printf("%-2d")，printf("\n")，不行(presentation 和wrong ans都有)，好吧那我後面那個改成printf("\b\n")，結果還是不行(wrong ans)
所以可以推論: (1) OJ完全不支持使用\b
(2) %-2d這種型態最好不要用
(3) OJ對格式超級超級嚴格，同樣人眼看都是空格，OJ卻視為不同東西，所以最好一律仿照if(... != ...)printf(" ")來輸出空格
*/
