#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable: 4996)

short N;//輸入N，表示有NxN的方陣。最大值為10
unsigned int matrix[10][10];//儲存題目所提供的矩陣
unsigned short count_spots_visited;//紀錄已經到過多少地方
unsigned short flag_spot_visited[10];//記錄每個點是否去過
//以上變數，全部初始值都是0，因為是global definition
unsigned int total_distance;//儲存目前遞迴的總距離
unsigned int min_distance = 100000000;//儲存目前跑過的所有"總""完整"距離中，最小的一個

void find_for_min_distance(int Now_At);

int main() {
	scanf("%hd", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%u", &matrix[i][j]);

	count_spots_visited = 1;   	flag_spot_visited[0] = 1;
	//line18，因為起點一定是post office，也就是A點，所以直接設定有造訪過A點。
	find_for_min_distance(0);

	printf("%u\n", min_distance);
	system("pause");
}

void find_for_min_distance(int Now_At) {
	if (count_spots_visited == N) {
		if (total_distance + matrix[0][Now_At] < min_distance) min_distance = total_distance + matrix[0][Now_At];
		return;
	}
	for (int i = 1; i < N; i++) {
		if (!flag_spot_visited[i]) {
			flag_spot_visited[i] = 1;
			count_spots_visited++;
			total_distance += matrix[Now_At][i];
			find_for_min_distance(i);
			total_distance -= matrix[Now_At][i];
			count_spots_visited--;
			flag_spot_visited[i] = 0;
		}
	}
	return;
}


//這題只要看過OJ的敘述，外加看懂一下上面的code就可，很難再去描述到底細部怎麼運作。助教的ppt基本上不需要看就可以看懂才是。如果得看助教ppt才能看懂上面在幹嘛，代表你太弱。