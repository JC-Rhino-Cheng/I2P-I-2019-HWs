#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#pragma warning (disable: 4996)

void DFS(int, int, int, int);

unsigned short N, X[10];//N: �`�@��N�i�d���CX[i]:��i�i�d���W���Ʀr�OX[i]�C
bool flag_card_used[10];
bool flag_solution_found;

int main() {
	unsigned short T; scanf("%hu", &T);//�`�@��T������C
	while (T--) {
		memset(flag_card_used, sizeof(flag_card_used), false);//�C�@���s������A���n���]�Ҧ��d���ϥα��p��: ���ϥΡC
		flag_solution_found = false;//�C�@���s������A���n���]���A��: �٨S���solution

		scanf("%hu", &N);//��Ū�J�쩳���h�ֱi�d��?
		unsigned sum_of_all_cards = 0;
		for (int i = 0; i < N; i++) {
			scanf("%hu", &X[i]);
			sum_of_all_cards += X[i];
		}//�A��Ҧ��d���W���ƦrŪ�J�A�íp��[�`�C�n�`�N!!!�d���W���Ʀr�[�`�A�@�w�|����Ҧ�column�Ȫ��[�`�C�Ӧ]���Ҧ�column�S���U�۬O�d���諸�`�M�A�ҥH�A�d���W���Ҧ��Ʀr�`�M�N�|����C��column�����`�M���`�M�C�U�����uif (sum_of_all_cards%num_of_columns != 0) continue;�v�N�O�o�ӷQ�k�C

		//�H�U�i�J���j�������q�C�]���p�G��N�i�d���A�N�̦h��N�ӥi�檺column�C
		unsigned short num_of_columns = N;
		for (; num_of_columns > 1; num_of_columns--) {
			if (sum_of_all_cards%num_of_columns != 0) continue;//�p�G�C��column�������`�M���O��ơA�N���i�ॿ�T�A���n���O�ɪťh���j�C

			DFS(num_of_columns, 0, sum_of_all_cards / num_of_columns, 0);
			if (flag_solution_found) break;//�p�G�C��column�������`�M�O���T���A���N���i�঳�i�檺�զX�C�p�G���F�i�檺�զX�A���ӴΤF�A�]���o�N�O�ڭn�����סA�ҥHbreak�᪽��print�X�ӡC�p�G�䤣��i�檺�զX�A���Ncolumn��-1�A�A�h�ոլݯण��i��A�æb�s��column�Ʃ��U���\���զX�C
		}//�p�G�scolumn��=2���䤣��i��զX�A���Ncolumn��--�A�ܦ�1�C���O�]��column==1�@�w����զX�A�ҥH���ܴN�����j�F�A�ҥHfor�j�骽�����i�Jiteration�C
		printf("%hu\n", num_of_columns);
	}
	system("pause");
}

void DFS(int goal_of_num_of_columns, int now_num_of_columns, int goal_of_each_column, int total_IN_now_column) {
	if (now_num_of_columns == goal_of_num_of_columns) { flag_solution_found = true; return; }

	for (int i = 0; i < N && !flag_solution_found; i++) {
		if (flag_card_used[i])continue;

		flag_card_used[i] = true;
		if (total_IN_now_column + X[i] < goal_of_each_column) DFS(goal_of_num_of_columns, now_num_of_columns, goal_of_each_column, total_IN_now_column + X[i]);
		else if (total_IN_now_column + X[i] == goal_of_each_column) DFS(goal_of_num_of_columns, now_num_of_columns + 1, goal_of_each_column, 0);
		flag_card_used[i] = false;
	}
}