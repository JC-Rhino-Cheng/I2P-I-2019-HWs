#include <stdio.h>
#include <stdlib.h>
#include <string.h>//strlen(a variable in string type)這個函式的調用
#pragma warning (disable:4996)
int main() {
	char input[100000];
	int length;
	int isPalindrome = 1;//flag，如果被判斷出來不對稱，再改成0
	while ((scanf("%s", input)) != EOF) {//如果"使用者"輸入"  abcba"，scanf會自動跳過最前面的兩個空隔
		isPalindrome = 1;//因為是在同一個迴圈內，所以如果上一次在這個迴圈的尾端已經把isPalindrome改成0，那就不符合我的程式設計邏輯，所以我一定要改回1
		length = strlen(input);//紀錄input字串有多少字元，如果是"使用者"輸入"  abcba"，則回傳5。主要是因為scanf會自動跳過最前面的空格，所以不是strlen函式特別聰明
		for (int i = 0; i < length; i++) {
			if (input[i] != input[length - i - 1]) {
				isPalindrome = 0;
				break;
			}//line13~16，當出現任何第一組不對稱，就把isPalindrome標記成0，而且可以直接跳出迴圈，不再找尋不對稱的地方
		}//其實condition statement那邊可以不用是i<length，而可以是i < (length/2)之類的概念，因為根本前面就已經判斷過了所以不用再搞剛一次
		if (isPalindrome) printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
}
/*
Notice1: 如果前面幾次的迴圈所輸入的字串比之後的迴圈所輸入的字串還長，會不會導致判斷出不對稱?
ex: 第一次迴圈輸入abcdedcba
第二次迴圈輸入OAO
那這樣會不會在第二次輸入過後，整個input[100000]是: OAOdedcba，導致程式判斷為不對稱?
Ans1: 其實不會的! 主要是因為程式會在scanf完之後再多寫入"\0"! 所以在strlen時就已經正確
知道第二次迴圈所輸入的字串的長度為何，所以在之後line12~16的迴圈內就完美迴避掉可能導致
程式判讀為不對稱的情況發生。
*/
