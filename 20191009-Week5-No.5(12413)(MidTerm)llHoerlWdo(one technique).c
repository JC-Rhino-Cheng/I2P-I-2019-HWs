#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable: 4996)

char input[1000][1000];//用以儲存MxN個字元
int swap[1000][2];//用以儲存將要互換位置的兩個不同編號的字元的位置

int main() {
	freopen("sample.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int M, N;//表示矩陣為MxN (M為x; N為y)，M、N極值為1000
	int T; //表示總共有T次swap，T極值為1000
	char temp_left;//在互換期間，做為一個temp用
	char c;//在輸入期間，因為getchar會記入空格也會記入\n，所以用以儲存getchar()返回的值，之後再用if判斷要不要真的儲存在input
	scanf("%d%d%d", &M, &N, &T);
	for (int i = 0; i < M; i++) {//整個迴圈讀入"真正"要swap的內容
		for (int j = 0; j < N; j++) {
			c = getchar();
			if (c == ' ' || c == '\n' ) j--;//我在讀入的時候根本就不想讀進\n或空格，因為如果讀進去，不管是要swap回去或者是要輸出的時候都很麻煩。所以就多了這一句。注意: 因為此時迴圈已經先幫我j++了，但是我讀進二維陣列當然希望j值是連續的，才不會造成日後swap或輸出時的麻煩，所以又手動j--。
			else input[i][j] = c;
		}
		//Notice1見下方
	}
	for (int i = 0; i < T; i++) //這個迴圈用來讀入所有的swap組合
		scanf("%d%d", &swap[i][0], &swap[i][1]);
		
	for (int i = T - 1; i >= 0; i--) {//依據上面的swap順序，反著swap回去。
		for (int j = 0; j < M; j++) {
			temp_left = input[j][swap[i][0] - 1];
			input[j][swap[i][0] - 1] = input[j][swap[i][1] - 1];
			input[j][swap[i][1] - 1] = temp_left;
		}
	}
	for (int i = 0; i < M; i++) 
		for (int j = 0; j < N; j++) printf("%c", input[i][j]);

	printf("\n");
	system("pause");
}
/*
Notice1: 
line17~24的for迴圈，我原本是想用scanf("%s", input[i])直接讀取分"行"讀取(而不是分"字")(註1)

	(註1)如果是char的二維陣列，可以一次性的輸入一列! 也就是雖然宣告為input[i][j](二維)，
但我可讀入input[i](一維)即可，不必一定要一個一個元素慢慢讀。
再來，此行可以用gets(input[i])來代替，但注意gets停抓點在\n但scanf停抓點在空格或\n(註2)

	(註2)gets這個函式就如同scanf，是很容易hack的，所以新版的編譯器會規定不能用gets。改由函式: 
fgets(要寫入的字串位置, 字串最長可能長度(如同scanf_s的概念), stdin(這五個字直接照抄))。
(Notice1還沒寫完)但是，照理來講fgets因為停抓點是\n才對，這樣到底為什麼還是會錯呢?
後來才(Oh!他媽的)發現讀入的第一個字元竟然就是\n!!!超級暈超級莫名其妙。為了對付這個\n字元，
我果然還是脫離不了一個一個字元慢慢讀入的命運...所以長相就演變成這樣。

2019.10.20更新: 「為了對付這個\n字元，
我果然還是脫離不了一個一個字元慢慢讀入的命運...所以長相就演變成這樣。」根本就是個屁話!
既然他第一個字元是\n，那你不會針對這個\n去 [法一]getchar() 或[法二]乾脆寫scanf("\n")就解決了嗎?
以上20191020的更新就是Technique1。
*/