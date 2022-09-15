#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable: 4996)

#define minima(a, b) (a < b)? a: b//定義一個簡單的非正規函式。Notice1
#define maxima 1001
#define initialise -1//為了避免重複遞迴到已經早就遞迴過的地方，造成大量耗時耗記憶體等等狀況，所以開啟一個陣列(在line10)來紀錄所有已經計算過的(l,r)數對。經由line16，先把所有表格內的元素初始化為-1，即這行的define項目。之後即可藉由line30的if判斷，來避免資源的浪費。，

char input[maxima];
int table_used[maxima][maxima];

int how_many_at_least(int l, int r);

int main() {
	int n, k;
	scanf_s("%d%d", &n, &k);

	memset(table_used, initialise, sizeof(table_used));//語法意義: 針對table_used這個陣列裡面，從開頭到某個元素的區間A內，所有元素全都設定為initialise。而區間A的長度是sizeof(table_used)，也就是所有table_used陣列內的元素。

	scanf("%s", input);
	printf("%s", (how_many_at_least(0, n - 1) <= k) ? "Yes\n" : "No\n");//這個寫法是可行的!好用!

	system("pause");
}


int how_many_at_least(int l, int r) {
	if (l >= r) return table_used[l][r] = 0;
	else if (input[l] == input[r])
		if (table_used[l][r] < 0) return table_used[l][r] = how_many_at_least(l + 1, r - 1);
		else return table_used[l][r];
	else {
		if (table_used[l][r] < 0)
			table_used[l][r] = minima(how_many_at_least(l + 1, r) + 1, how_many_at_least(l, r - 1) + 1);
		return table_used[l][r];
	}
}

/*
Notice1: 要特別特別注意，如果用這種方式寫函式的話，要注意括弧有沒有刮對!!!!因為define的意思就完全等同word裡面的取代，所以一旦括弧
沒有設計好，很可能取代後缺少分號';'，或者更嚴重的情形發生。例如以下例子想要取絕對值:
define absolute(num) (num > 0) ? num : -num
當使用者輸入的num不是單一一個數字而是多個數字的運算的時候(ex: a-b)，此例底下若a< b， 則運行「-a-b」，而不是我們所預期的「b-a」!
也許你可能覺得，如果改成: define absolute(num) (num > 0) ? num : -(num) 就可以了，可是!!!!define在取代抵時候，只認得num這「一個」變數，
所以當他遇到a-b，總共a和b「兩個」變數、以及中間的符號"-"，他會認不得，導致取代的時候完全出錯!!!!
所以真正正確的寫法搭配正確用法應該是:
define absolute(a, b) (a-b > 0) ? (a-b) : (b-a)，然後後續的的code裡面不能寫absolute(a"-"b)，只能寫absolute(a"," b)!!!!(整段話如果要看懂，請見12481Frog Jumping)
*/
//本題請搭配助教ppt來理解，因為文字實在講不明白
//記得如果要判斷每個遞迴是否有沒有正確進入，可以用最簡單的方法判斷，那就是: 在遞迴函式的開頭位置寫一行: printf("%d%d%d%d", ..,..,..,..,......)
//記得，每個題目都要從最簡單測資的著手!!!!助教給的最簡單測資，可能也沒有到真的最簡單，所以可以自己造一個簡單測資!!!