#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

short dx[] = { 0,1,0,-1 };
short dy[] = { 1,0,-1,0 };//Direction0、1、2、3分別是: 往右、往下、往左、往上

unsigned int N, M;//一個地圖，總共是N*M個座標位置。
char map[1001][1001];//N、M極值都是1000。

unsigned short visited[1001][1001];//已經全都初始化為0了。
unsigned short flag_reached_Teleport;

void go_maze(int, int);

int main() {
	unsigned int T; scanf("%u", &T);//總共會有T個地圖

	while (T--) {
		scanf("%u%u", &N, &M);//一個地圖內，總共有N*M個座標位置。
		memset(visited, 0, sizeof(visited));;//初始化為0，也就是每一次新的迷宮，每個格子都要重設為沒走過
		flag_reached_Teleport = 0;//初始化為0，也就是回到沒有遇過Teleport的狀態

		for (int i = 0; i < N; i++) scanf("%s", map[i]);//讀入地圖

		go_maze(0, 0);
		if (flag_reached_Teleport) {
			for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
				if (map[i][j] == 'T') go_maze(i, j);
		}//line27~30的if: 如果有遇過T，代表他是可以瞬間移動到任何另一個T的，所以我只要掃過整個地圖，找到所有T所在的位置，並根據掃到的T，都再掃過所有以T為起點路徑即可。

		printf("%s\n", visited[N - 1][M - 1] ? "Yes" : "No");
	}

	system("pause");
}


void go_maze(int x_now, int y_now) {
	if (visited[x_now][y_now]) return;//如果這格已經來過了，就直接return
	
	//以下都是已經排查過，確定沒有來過的情形。
	visited[x_now][y_now] = 1;//因為沒有來過，所以先把狀態改成"來過"。
	if (map[x_now][y_now] == 'T') flag_reached_Teleport = 1;//如果這格是T，就把"有遇到T"的標籤改成true
	for (int i = 0; i < 4; i++) {//在這格，開始判定上下左右四個方位的「可到性」
		int x_next = x_now + dx[i]; int y_next = y_now + dy[i];

		if (x_next < 0 || y_next < 0 || x_next >= N || y_next >= M) continue;//如果目前預定前往的下一格在邊界外，是「不可到」，所以直接continue來換方向。
		if (map[x_next][y_next] == '#') continue;//如果目前預定前往的下一格是wall，是「不可到」，所以直接continue來換方向。
		go_maze(x_next, y_next);//已經確定是可到的了，所以就往這裡走。
	}
	return;
}