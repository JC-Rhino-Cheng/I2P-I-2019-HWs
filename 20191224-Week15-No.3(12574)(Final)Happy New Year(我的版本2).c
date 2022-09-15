#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable: 4996)

#define MAX_num_of_people (int)1e5

int DFS_Direct_Relatives(int y, int *P);
int DFS_Uncles_and_Aunts(int z, int *P);

int main() {
	int N; int P[MAX_num_of_people];
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &P[i]);

	int count_envelope = 0;
	count_envelope += DFS_Direct_Relatives(N, P);
	count_envelope += DFS_Uncles_and_Aunts(N, P);

	printf("%d\n", count_envelope);
	system("pause");
}


int DFS_Direct_Relatives(int y, int *P) {
	int x = P[y];
	if (x == -1) return 0;
	int count = 1;
	return count + DFS_Direct_Relatives(x, P);
}


int DFS_Uncles_and_Aunts(int z, int *P) {
	int count = 0;
	int y = P[z]; int x = P[y];
	for (int i = 1; i <= z; i++) if (P[i] == x) count++;

	return count - 1;
}
