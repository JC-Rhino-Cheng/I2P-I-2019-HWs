#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable: 4996)

#define MAX_num_of_people 100001 //最多是100000人，但考慮到我等下會用1-based計算，所以多一人

int P[MAX_num_of_people];
int count_num_of_envelops = 0;

void count_Direct_Blood_Relative(int y);
void count_Uncle_and_Aunt(int z);


int main() {
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &P[i]);//!!!!注意!!!!是1-based!!!!

	count_Direct_Blood_Relative(N);
	count_Uncle_and_Aunt(N);
	count_num_of_envelops--;//因為在count_Direct_Blood_Relative和count_Uncle_and_Aunt這兩個函式中，Bob的parent都會被算到，所以要扣掉重複的1次。

	printf("%d\n", count_num_of_envelops);

	system("pause");
}

void count_Direct_Blood_Relative(int y) {//因應他的sample input「-1 1 2 2 3 3 5 4 4 4 9 9 9」的排序概念，我要找y的parent。因為我爽把parent叫做x，所以現在這個兒女的名字只能叫做y。
	int x = P[y];//x是y的parent。
	if (x != -1) {
		count_num_of_envelops++;
		count_Direct_Blood_Relative(x);
	}
	else return;
}

void count_Uncle_and_Aunt(int z) {//取名z的理由同上。不過因為這次的主要線索是祖父母，也就是z的parent的parent。所以z得是z。z的parent得是y。z的grandparent，也就是z的parent的parent，也就是y的parent，才能是x。
	int y = P[z]; int x = P[y];
	for (int i = 1; i <= z; i++) //我要開始數ㄕㄨˇ數ㄕㄨˋ 了。照理來講應該是把整個P陣列都數完，所以應該是i<=N才對，不過因為我這個函式沒有接收到N的訊息，所以應該有個瓶頸才對啊。嗯?????不過，你會發現，剛好z就是N!!!(題目設定的)所以就湊巧直接拿來用。注意!!!!因為是1-based，所以i從1開始算。
		if (P[i] == x) count_num_of_envelops++;

	return;
}