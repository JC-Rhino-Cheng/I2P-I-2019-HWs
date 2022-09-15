#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;//數到底有幾個數
	int input[1000] = { 0 };//輸入所有數
	int count = 0;//在mul or div裡面分別負責計算到底有多少個倍數or因數
	int mul[1000] = { 0 };//計算input陣列裡面各個元素的倍數數量
	int div[1000] = { 0 };//計算input陣列裡面各個元素的因數數量
	int beauty[1000] = { 0 };//beauty = mul - div
	int worst_beauty;//紀錄beauty陣列之中最小的值
	int min;//藉由此變數來找出"所有符合beauty最小值"的所有值中，最小的那一個值
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf_s("%d", &input[i]);
	for (int i = 0; i < N; i++) {
		count = 0;
		for (int j = 0; j < N; j++) 
			if (input[j] % input[i] == 0) count++;
		mul[i] = count;
	}//line16~21計算input陣列裡面各個元素的倍數數量
	for (int i = 0; i < N; i++) {
		count = 0;
		for (int j = 0; j < N; j++) 
			if (input[i] % input[j] == 0) count++;
		div[i] = count;
	}//line22~27計算input陣列裡面各個元素的因數數量
	for (int i = 0; i < N; i++)
		beauty[i] = mul[i] - div[i];//line28~29算出所有元素的beauty程度
	worst_beauty = beauty[0];
	for (int i = 1; i < N; i++)
		if (beauty[i] < worst_beauty) 	worst_beauty = beauty[i];//line31~32找出beauty陣列裡面的最小值
	for (int i = 0; i < N; i++) {
		if (beauty[i] == worst_beauty) {
			min = input[i];
			break;
		}
	}//line33~38先找出在存有最小beauty的眾多值當中的第一個值
	for (int i = 0; i < N ; i++)
		if (min > input[i] && beauty[i] == worst_beauty) min = input[i];
	//line39~40在所有input裡面，滿足具有最小beauty值的眾多input中，如果有值比之前的min更小的值的話，則min會被取代
	printf("%d\n", min);
	system("pause");
}
