#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#pragma warning (disable: 4996)


int main(){
	int N; scanf("%d", &N);//N�N���`�@�|��N�ӤG���}�C�C
    int (*array)[COLUMN]; // array�O�ӫ��СA�L�x�s���O�Y�ӡu�@��"�}�C"�v����m�C

	while (N--) {//��n��N�Ӱ}�C
		int R; scanf("%d", &R);//�ثe���o�ӤG���}�C�O: R��row�B5��Column�C(5�O�D�زΤ@�W�w)
		array = (int(*) [COLUMN] ) malloc( sizeof(int) * COLUMN * R );//Notice1
		for (int i = 0; i < R; i++) for (int j = 0; j < COLUMN; j++)
			scanf("%d", &array[i][j]);

		sortArray(R, array);

		for (int i = 0; i < R; i++) {
			printf("%d", array[i][0]);
			for (int j = 1; j < COLUMN; j++) printf(" %d", array[i][j]);
			printf("\n");
		}

		if (N) printf("\n");//�u���b�̫�@�Ӱ}�C��X�����ɡA���δ���
		free(array);
	}


	system("pause");
}


//Notice1: �ݥL����malloc�f�t�u�@�ӫ��СA�B�x�s���O�Y�ӡy�@��"�}�C"�z����m�v
//���D�����O�b�ҷ|���|��bubblesort�Ӥw