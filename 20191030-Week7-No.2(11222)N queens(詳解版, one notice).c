#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable: 4996)

short q[2001];
int count;

void queens_permutation(int now_row, int N_of_Qs);
int validation(int row, int col);
void display_queens(int N_of_Qs);

int main() {
	int N_of_Qs = 0;
	int *ptr_N_of_Qs = &N_of_Qs;
	while (scanf("%d", ptr_N_of_Qs) != EOF) {
		count = 0;
		queens_permutation(0, N_of_Qs);
		printf("\nThere's %d valid arrays.\n\n", count);
	}
	system("pause");
}



void queens_permutation(int now_row, int N_of_Qs) {
	if (now_row == N_of_Qs) {
		display_queens(N_of_Qs);
		return ;
	}
	else {
		for (int j = 0; j < N_of_Qs; j++) {
			if (validation(now_row, j)) {
				q[now_row] = j;
				queens_permutation(now_row + 1, N_of_Qs);
			}
		}
	}/*Q2解答: !!若一整排都invalid，依照此code，會自動跳回上一個row去找下一個valid的格子嗎?
	Ans: 是。假設目前在第2row是第一次找到valid，	則在line30會進入，之後到line32時會往下跳到第3row。
	如果整個第3row都invalid，則line31~33在該row都完全沒有執行過。
	等到這個row的for-loop都已經完成以後，程式發現，嗯???這個row都找遍了都沒找到，就要自動return了，所以剛好，
	return後就會回到line36所寫的line32所跳的第3row的上一層，也就是第2row，去執行第2row都還沒進行過的接下來的j。
	*/
	/*
	Q1解答: !!假設有3層，遞迴先進入now_row=0層。line30已經valid後，到line32呼叫一次now_row=1遞迴，!!!!!注意now_row=0
	這層遞迴卡在line32已經運行，但，擱置中，準備進行line33!!now_row=1層已經line30valid後，到line32呼叫一次now_row=2遞迴
	!!!注意now_row=1這一層遞迴卡在line32已經運行，但，擱置中，準備進行line33!!!!now_row=2層已經line30valid後，
	到line32呼叫一次now_row=3遞迴!!!注意now_row=2這一層遞迴卡在line32已經運行，但，擱置中，準備進行line33!!!!
	now_row=3層，進入line24的if，display返回line24的末端後，進入line25返回。所以!!!此時!!返回到now_row3未進行的line33，
	由於已經是區段最末端，但都未見return字樣，所以自動執行return。return後馬上回到now_row2所未進行的line33，
	由於已經是區段最末端，但都未見return字樣，所以自動執行return。return後馬上回到now_row1未進行的line33，
	由於已經是區段最末端，但都未見return字樣，所以自動執行return。return後馬上回到now_row0未進行的line33「。」
	至此，now_row="0"底下，j=0的合法棋盤已經被地毯式搜索一遍。之後進行進入now_row="0"底下的j=1，
	完了之後再進入now_row="0"底下的j=2，
	完了之後再進入now_row="0"底下的j=3，
	完了之後再進入now_row="0"底下的j=4，
	完了之後再進入now_row="0"底下的j=5，
	完了之後再進入now_row="0"底下的j=6，
	......
	等到now_row="0"來到 "j=最末端點"，並地毯式搜索過合法的棋盤後，才真正結束line15的總計line23~35的呼叫。
	*/
}

int validation(int row, int col) {
	for (int i = 0; i < row; i++) {
		if (q[i] == col || q[i] == col - row + i || q[i] == col + row - i) return 0;
	}
	return 1;
}

void display_queens(int N_of_Qs) {
	for (int i = 0; i < N_of_Qs; i++) {
		for (int j = 0; j < N_of_Qs; j++) {
			if (q[i] == j) printf("O");
			else printf("X");
		}
		putchar('\n');
	}
	putchar('\n');
	count++;
	return;
}


/*
1.為什麼在place(int row)裡面當row==NQ之後，函數不會結束，而是繼續找下一組放法
2.還有請問(一樣是在place函數裡面)為甚麼當程式發現j==Q的時候會自己跑回上一個row再找一次，而不是跳出for-loop

ANS:
Q1: row==NQ 時，if 中，執行display將找到的一組答案印出，之後就return，所以以place(row)這層而言確實會結束，
但是 return 回上一層 place(row-1)會繼續該層 for loop 後續的 j 擺放，所以以 place(row-1)這一層是繼續找下一組放法。

Q2: 這邊不要混淆，place(row-1) 呼叫 place(row)，以 place(row) 這層的 function 執行，for-loop執行至 j==NQ，
確實會跳出 loop，但是跳出 for-loop 後，後面也沒有程式碼可執行, 因此自然而然 return 回去上一層 place(row-1) 的 for-loop，
由那層後續的 j 繼續往下試看看可以擺放的方法。//直接在那邊寫註解好了==

所以總結，要區分是在 place(row-1) 或 place(row) 哪一層。

我自己的更精確總結，要很清楚地知道每一層呼叫下一層之後，那個暫時被擱置的未完的function卡在哪裡。//Notice1

Notice2: 如果實在看不懂上面所有敘述所表達的意義，請用2x2的陣列去想!!!!
記住!!!!!!凡是都要從能看出規律的最簡單的例子著手!!!!不要想著一步登天!!
*/