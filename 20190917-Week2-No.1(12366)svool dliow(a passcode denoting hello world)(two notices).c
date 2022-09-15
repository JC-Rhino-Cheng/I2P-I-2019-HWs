#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[5] = {'\0','\0','\0','\0','\0'};//char用%d表示確定是沒問題的! (by line 7)
	/*for( int i = 0 ; i < 5 ; i++)
		scanf("%c", str[i]); */ 
	scanf("%c %c %c %c %c", &str[0], &str[1], &str[2], &str[3], &str[4]); 
	int num[5] = {0};
	for( int i =0 ; i < 5 ; i++)
		num[i] = 219 - str[i];
	for( int i = 0 ; i < 5 ; i++)
		printf("%c", num[i]);
	printf("\n");
	system("pause");

}
/*
Note1: int 可以直接把char當成int運算
(因為電腦根本就是在scanf的時候就是儲存數字，之後才在printf用ASCII轉換!)。
Note2: 輸入一堆char(也就是字串)的時候，不能用for或者while迴圈! 一定要scanf("%c%c%c%c%c", &..., &..., &...)才可以
(或者也可以直接printf("%s", ......)就解決)
*/
