#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#pragma warning (disable: 4996)


int main(){
	int N; scanf("%d", &N);//N代表總共會有N個二維陣列。
    int (*array)[COLUMN]; // array是個指標，他儲存的是某個「一維"陣列"」的位置。

	while (N--) {//剛好有N個陣列
		int R; scanf("%d", &R);//目前的這個二維陣列是: R個row、5個Column。(5是題目統一規定)
		array = (int(*) [COLUMN] ) malloc( sizeof(int) * COLUMN * R );//Notice1
		for (int i = 0; i < R; i++) for (int j = 0; j < COLUMN; j++)
			scanf("%d", &array[i][j]);

		sortArray(R, array);

		for (int i = 0; i < R; i++) {
			printf("%d", array[i][0]);
			for (int j = 1; j < COLUMN; j++) printf(" %d", array[i][j]);
			printf("\n");
		}

		if (N) printf("\n");//只有在最後一個陣列輸出完畢時，不用換行
		free(array);
	}


	system("pause");
}


//Notice1: 看他怎麼用malloc搭配「一個指標，且儲存的是某個『一維"陣列"』的位置」
//本題完全是在考會不會用bubblesort而已