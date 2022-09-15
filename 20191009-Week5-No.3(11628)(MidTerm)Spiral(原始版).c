#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable: 4996)

char arr[5001][5001];//NxN is guaranteed to be no more than 5000x5000, but for the sake of convenience when programming, arr[0][0]~arr[0][N] & arr[0][0]~arr[N][0] would not be used.

int main() {
	freopen("sample.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	short T; //T表示總共會輸入T次數字
	short steps;//每次新進入一個迴圈(while(T--))，都要重新讀入steps，因為是新一輪的spiral。而在同一輪的spiral中，steps會持續--直到為0。成為0之後，輸出結果，再重新一次迴圈(while(T--))讀入steps。
	short direction = 1;//rightbound、southbound、westbound、northbound分別設定值為1、2、3、0。故意設計成這樣是因為每次都右轉，所以只要每次右轉，direction就+1即可。初始時是rightbound。
	short x_now = 1, y_now = 0;//arr[0][0]~arr[0][N] & arr[0][0]~arr[N][0]都不使用的原因在這裡。除了讓真正用到的array從0-based轉為1-based，更可以簡化之後迴圈設計上的麻煩。初始位置設定為(x, y)= (1, 0)就是為了迴圈設計上的方便。
	scanf("%hd", &T);
	while (T--) {
		direction = 1;//每次開啟新一輪的spiral，都要重設方向為1
		x_now = 1, y_now = 0;//每次開啟新一輪的spiral，都要重設初始位置為(1, 0)。
		scanf("%hd", &steps);
		for (int i = steps; i; i--) {//line19~51的for迴圈計算的是「變換方向'後'」的步數
			switch (direction % 4) {//switch 根據方向的不同，來計算目前游標走到的陣列位置。游標走到之後，才把arr[][]值賦予為'#'。
				case 1://rightbound
					for (int j = i; j; j--) {//line22~25、29~32、36~39、43~46的for迴圈，計算的是「'同'一次的'同'個方向內」的步數'倒數(count down 不是reciprocal)'，所以初始的j是i，而不是steps!!!
						y_now += 1;
						arr[x_now][y_now] = '#';
					}
					direction++;//同一次的同一個方向內「游標走到、賦值為'#'」的組合都已經完畢以後，右轉
					break;
				case 2://southbound
					for (int j = i; j; j--) {
						x_now += 1;
						arr[x_now][y_now] = '#';
					}
					direction++;
					break;
				case 3://westbound
					for (int j = i; j; j--) {
						y_now -= 1;
						arr[x_now][y_now] = '#';
					}
					direction++;
					break;
				case 0://northbound
					for (int j = i; j; j--) {
						x_now -= 1;
						arr[x_now][y_now] = '#';
					}
					direction++;
					break;
				default: ;//switch要記得寫defualt這一項，縱使裡面沒有要執行任何東西。阿要記得default後面也要跟一個冒號和一個semicolon
			}
		}
		for (int i = 1; i <= steps; i++) {//一列一列依序輸出陣列
			for (int j = 1; j <= steps; j++) {
				if (arr[i][j] != '#') printf(" ");//為了不要TLE，所以我只針對需要賦值為'#'的元素賦值，至於其他要print出空格的東西就沒有賦值。所以設計為if (arr[i][j] != '#')。
				else printf("#");
				arr[i][j] = '1';//其實一次的spiral到line55就結束了，根本不必加這一行。那為什麼我加了呢?因為會有T組spiral需要輸出，所以如果沒有把arr全部的值都改為「非#」的話，之後可能會發生明明要輸出空格卻輸出#的情況。而也因為多了這一行，所以line54中if(arr[i][j] != "#")的功效又更明顯了。
			}
			printf("\n");
		}
	}


	system("pause");
}