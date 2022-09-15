#include <stdio.h>
#include <stdlib.h>
//#pragma warning (disable: 4996)

int main() {
	int n, m;
	int whom_to_move[100000];
	int where_the_one_to_move_is = -1;
	int temp_value_of_the_one_to_move;
	int arr[200000];
	scanf_s("%u%u", &n, &m);
	for (int i = 0; i < m; i++) scanf_s("%u", &whom_to_move[i]);
	for (int i = 0; i < n; i++) {
		arr[i] =  i + 1;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (whom_to_move[i] == arr[j]) {
				where_the_one_to_move_is = j;
				temp_value_of_the_one_to_move = arr[j];
				break;
			} 
		}
		for (int j = where_the_one_to_move_is; j >= 1; j--) {
			arr[j] = arr[j - 1];
		}
		arr[0] = temp_value_of_the_one_to_move;
	}
	for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
	system("pause");
}
