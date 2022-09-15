#include "function.h"

void sortArray(int R, int(*array)[COLUMN]) {
	//總共有R個row，他一次傳入一個一維陣列，且column已經唯一確定
	for (int k = 0; k < R; k++) {
		for (int i = 0; i < COLUMN - 1; i++) {
			for (int j = 0; j < COLUMN - i - 1; j++) {
				if (array[k][j] > array[k][j + 1]) {
					int temp = array[k][j];
					array[k][j] = array[k][j + 1];
					array[k][j + 1] = temp;
				}
			}
		}
	}
	return;
}