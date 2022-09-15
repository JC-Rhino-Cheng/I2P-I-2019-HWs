#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

#define MAX_NUM_OF_PEOPLE 10000000
int comfort_level[MAX_NUM_OF_PEOPLE];//儲存隊列中，每個人的comfort level。
int matched[MAX_NUM_OF_PEOPLE];//儲存comfort level和X的數值相同的人的"位置"。
int Tall[MAX_NUM_OF_PEOPLE];
//以上三行，因為陣列過大，只能放在global

int main() {
	int N, X;//N表示有N個人。X儲存的則是Little Brick所在位置的comfort level。N和X的極值都是10^7。
	scanf("%d%d", &N, &X);

	int count = 0;//數ㄕㄨˇ數ㄕㄨˋ。數到底有多少人的comfort level和X相同。

	for (int i = 0; i < N; i++) {
		scanf("%d", &Tall[i]);

		int j = i - 1;
		while (j >= 0) {
			if (Tall[i] > Tall[j]) j -= comfort_level[j] + 1;
			else break;
		}
		comfort_level[i] = i - j - 1;
		if (comfort_level[i] == X) matched[count++] = i;//Notice1
	}
	/*line17~27主要思路:
	每次都先讀入某個人的身高，之後馬上就計算這個人的comfort_level。
	而這個人的comfort_level完全由前面那些人的身高決定。
	怎麼算會比較快呢?
	
	!!!重點!!!我們已知前面所有人的comfort_level!!!
	那假如我是i，我的comfort_level怎麼算呢???我是不是要找到「在我前面的第一個比我高的人」!!!
	如果在我前面的第一個比我高的人他的編號是j，那我的comfort_level不就是: i-j-1了嗎?
	(i是指: 從第"1"個人開始算，到我這個編號i的人，總共有i個人)
	(i是指: 從第"1"個人開始算，到我這個編號j的人，總共有j個人)
	(那我的comfort_level就是i-j-1，那個減一是因為要扣掉自己。)(請自行畫圖來了解)
	
	那我要怎麼找「在我前面的第一個比我高的人(X)」呢?
	很簡單啊!先去問在我前面的第一個人(A)，他的comfort_level是多少?
	我先去找「我所問的人(A)」的comfort_level，這樣就可以找到「我所問的人的前面的第一個比他高的人(B)」。
	找到這個人可以幹嘛?很簡單啊!因為只有這個人(B)比「在我前面的第一個人(A)」還高，所以在A和B之間，
	我可以確定除了B以外的所有人都比A還矮!
	那如果我已經比A還高了，而A和B之間的除了B以外的人都比A矮，那我只需要確認B到底比我高還比我矮就好了。
	
	循著這個思路，line22就此誕生。至於line21是要確保不能超出邊界。
	line26:如果找到了持有相同comfort_level的人，代表他是candidate，所以我就記錄他的位置，並且count++。
	*/
	if (count) {
		printf("%d", matched[0] + 1);
		for (int i = 1; i < count; i++) printf(" %d", matched[i] + 1);
		puts("");
	}
	else printf("ouo\n");

	system("pause");
}


//本題最好搭配助教的ppt比較容易懂

//Notice1: 這個用法超常用!!!!一定要很熟悉!!!!