#include "function.h"

void sortArray(int R, int(*array)[COLUMN]) {
	//�`�@��R��row�A�L�@���ǤJ�@�Ӥ@���}�C�A�Bcolumn�w�g�ߤ@�T�w
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