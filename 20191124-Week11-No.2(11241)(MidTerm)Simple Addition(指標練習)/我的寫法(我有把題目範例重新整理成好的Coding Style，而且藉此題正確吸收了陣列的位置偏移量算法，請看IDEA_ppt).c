#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

int addition(int*[], int, int[], int);

int main(void) {
	int a[50][50], b[50][50], c[50][50], d[50][50];//�@��A�BB�BC�BD�|��array�x�s�ܦh�ܦhint�A�ݥ[�_��

	int m, n;	scanf("%d %d", &m, &n);//�C��array���Om*n
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
		scanf("%d", &a[i][j]);
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
		scanf("%d", &b[i][j]);
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
		scanf("%d", &c[i][j]);
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
		scanf("%d", &d[i][j]);

	int array_chosen;//array_chosen: B�BC�BD���O�s��0�B1�B2�A���ӳQ�D��F�O?
	int num_ind;//num_ind: A�}�C(�}�C�s��: 3)�M�t�@�ӳQ�D�諸�}�C�A�U�ۦ�num_ind�ӼƦr�ݥ[�`
	//���ڭ쥻�Q�nA�BB�BC�BD�s��0�B1�B2�B3���A���O�L�`�D�صw�ʳW�wB�O0�BC�O1�BD�O2......
	scanf("%d%d", &array_chosen, &num_ind);

	int index_to_add[20];
	for (int i = 0; i < num_ind * 2; i += 2)
		scanf("%d %d", &index_to_add[i], &index_to_add[i + 1]);

	int *entry[4];
	entry[3] = &a[0][0]; 	entry[0] = &b[0][0]; 	entry[1] = &c[0][0]; 	entry[2] = &d[0][0];//B�BC�BD���O�s��0�B1�B2(�D�سW�w)

	printf("%d\n", addition(entry, array_chosen, index_to_add, num_ind));

	system("pause");
}

int addition(int* entry[], int array_chosen, int index_to_add[], int num_ind) {
	//���A�p�G��VS��function�����ܡA�|�o�{VS���addtion�o�Ө禡����Ū�O: 
	//int addition(int  **entry, int array_chosen, int  *index_to_add, int num_ind);
	//���ߩ��T���A�`���O���w: �u�P�Pa       �N�O       a�Ū��خ�       �@���}�C�v
	int total = 0;
	for (int i = 0; i < num_ind; i++) {
		int weizhi_pianyiliang = index_to_add[2 * i] * 50 + index_to_add[2 * i + 1];//��m�����q
		//�ھ�line26�A���]�i�g��: for(int i = 0; i < num_ind * 2; i += 2){int weizhi_pianyiliang = index_to_add[i] * 50 + index_to_add[i+1]; }
		total += *(entry[3] + weizhi_pianyiliang) + *(entry[array_chosen] + weizhi_pianyiliang);
		//�W�@�y�]�i�g��: total += entry[3][weizhi_pianyiliang] + entry[array_chosen][weizhi_pianyiliang];�����A��compiler�Ө��Aarray[a][b][c]....[y][z]���L�N�Ocompiler�۰����ڭ̺�n��m�����q�}�F�C
	}
	return total;
}