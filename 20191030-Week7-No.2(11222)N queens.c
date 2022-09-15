#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable: 4996)

short q[2001];
int count;

int queens_permutation(int now_row, int N_of_Qs);
int validation(int row, int col);
void display_queens(int N_of_Qs);

int main() {
	int N_of_Qs = 0;
	int *ptr_N_of_Qs = &N_of_Qs;
	while (scanf("%d", ptr_N_of_Qs) != EOF) {
		count = 0;
		queens_permutation(0, N_of_Qs);
		printf("%d\n", count);
	}
	system("pause");
}



int queens_permutation(int now_row, int N_of_Qs) {
	if (now_row == N_of_Qs) {
		display_queens(N_of_Qs);
		return 0;
	}
	else {
		for (int j = 0; j < N_of_Qs; j++) {
			if (validation(now_row, j)) {
				q[now_row] = j;
				queens_permutation(now_row + 1, N_of_Qs);
			}
		}
	}

}

int validation(int row, int col) {
	for (int i = 0; i < row; i++) {
		if (q[i] == col || q[i] == col - row + i || q[i] == col + row - i) return 0;
	}
	return 1;
}

void display_queens(int N_of_Qs) {
	count++;
	return;
}

