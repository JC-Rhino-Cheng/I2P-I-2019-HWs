#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning (disable: 4996)

int main() {
	int N, N_backup, M;//N: 總共多少組資料。M: 要當掉多少學生
	char S[1000][11]; int G[1000], A[1000];
	int Score[1000];
	char* namae[1000];

	scanf("%d%d", &N, &M); N_backup = N;
	while (N--) {
		scanf("%s %d %d", S[N], &G[N], &A[N]);
		Score[N] = G[N] * 300 + (100 - A[N]);
		namae[N] = S[N];
	}
	N = N_backup;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (Score[i] > Score[j]) {
				int temp = Score[i];
				Score[i] = Score[j];
				Score[j] = temp;
				char* temp_name = namae[i];
				namae[i] = namae[j];
				namae[j] = temp_name;
			}
			else if (Score[i] == Score[j]) {
				if (strcmp(namae[i], namae[j]) < 0) {
					char* temp_name = namae[i];
					namae[i] = namae[j];
					namae[j] = temp_name;
				}
			}
		}
	}




	for (int i = 0; i < M; i++) puts(namae[i]);
	system("pause");
}