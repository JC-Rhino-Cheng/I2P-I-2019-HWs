#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

int addition(int*[], int, int[], int);

int main(void) {
	int a[50][50], b[50][50], c[50][50], d[50][50];//共有A、B、C、D四個array儲存很多很多int，待加起來

	int m, n;	scanf("%d %d", &m, &n);//每個array都是m*n
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
		scanf("%d", &a[i][j]);
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
		scanf("%d", &b[i][j]);
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
		scanf("%d", &c[i][j]);
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
		scanf("%d", &d[i][j]);

	int array_chosen;//array_chosen: B、C、D分別編號0、1、2，哪個被挑選了呢?
	int num_ind;//num_ind: A陣列(陣列編號: 3)和另一個被挑選的陣列，各自有num_ind個數字待加總
	//其實我原本想要A、B、C、D編號0、1、2、3的，但是無奈題目硬性規定B是0、C是1、D是2......
	scanf("%d%d", &array_chosen, &num_ind);

	int index_to_add[20];
	for (int i = 0; i < num_ind * 2; i += 2)
		scanf("%d %d", &index_to_add[i], &index_to_add[i + 1]);

	int *entry[4];
	entry[3] = &a[0][0]; 	entry[0] = &b[0][0]; 	entry[1] = &c[0][0]; 	entry[2] = &d[0][0];//B、C、D分別編號0、1、2(題目規定)

	printf("%d\n", addition(entry, array_chosen, index_to_add, num_ind));

	system("pause");
}

int addition(int* entry[], int array_chosen, int index_to_add[], int num_ind) {
	//其實你如果用VS看function的提示，會發現VS對於addtion這個函式的解讀是: 
	//int addition(int  **entry, int array_chosen, int  *index_to_add, int num_ind);
	//早晚念三次，常念保平安: 「星星a       就是       a空的框框       一維陣列」
	int total = 0;
	for (int i = 0; i < num_ind; i++) {
		int weizhi_pianyiliang = index_to_add[2 * i] * 50 + index_to_add[2 * i + 1];//位置偏移量
		//根據line26，其實也可寫成: for(int i = 0; i < num_ind * 2; i += 2){int weizhi_pianyiliang = index_to_add[i] * 50 + index_to_add[i+1]; }
		total += *(entry[3] + weizhi_pianyiliang) + *(entry[array_chosen] + weizhi_pianyiliang);
		//上一句也可寫成: total += entry[3][weizhi_pianyiliang] + entry[array_chosen][weizhi_pianyiliang];畢竟，對compiler而言，array[a][b][c]....[y][z]不過就是compiler自動幫我們算好位置偏移量罷了。
	}
	return total;
}