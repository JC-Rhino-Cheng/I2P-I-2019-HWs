#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning (disable: 4996)

#define Max_length 502//題目說最長500字元，如果考慮到結尾的\0，是501字元。可是因為等下用的是fgets，他會讀入\n，所以最少需要502。

void sentence_reversal(char *now, char* original_pos);

int main() {
	char input[Max_length];
	while (fgets(input, Max_length, stdin) != NULL) {
		//如果輸入abc，實際上的字串是: input[0、1、2、3、4]='a'、'b'、'c'、'\n'、'\0'。length=4。
		input[strlen(input) - 1] = '\0';//所以把input[length-1]改為'\0'。

		sentence_reversal(input, input);//進入遞迴，把所有詞都輸出完。
		puts("");//整串都已經reverse好後，進入下個字串的reverse前，先換行。
	}
	system("pause");
}

void sentence_reversal(char *now, char* original_pos) {
	if (now[0] == '\0') return;//Basis。如果已經檢查到句子的最尾端的'\0'了，不輸出，直接回到上個recursion。

	int now_word_length = 0;
	for (int i = 0;; i++) {
		if (now[i] == ' ' || now[i] == '\0') {//句中，詞間的空格是用' '來判斷。為了考量到最後一個詞，所以多加入now[i]=='\0'。
			now_word_length = i;//透過i來數目前所在的"詞"有多少字母。
			sentence_reversal(now + now_word_length + 1, original_pos);//直接跳到下一個"詞"。透過now+now_word_length+1來直接精準跳到下個"詞"
			break;
		}
	}//此時已經知道了目前所在的詞的長度

	char temp[Max_length];
	strncpy(temp, now, now_word_length); temp[now_word_length] = '\0';//把目前所在的詞複製到temp陣列裡。而最後端要記得補'\0'否則無法printf。//Notice1。

	if (now == original_pos) printf("%s", temp);//如果是輸出的最後一個詞(也就是使用者所輸入的第一個詞)，則後面不空格。
	else printf("%s ", temp);

	return;
}


//Notice1: 請藉由這個例子，來好好體會為何要有str"n"cpy，不是只要有strcpy就好。