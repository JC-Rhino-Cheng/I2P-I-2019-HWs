#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable: 4996)

#define MAX_num_of_people 100001 //�̦h�O100000�H�A���Ҽ{��ڵ��U�|��1-based�p��A�ҥH�h�@�H

int P[MAX_num_of_people];
int count_num_of_envelops = 0;

void count_Direct_Blood_Relative(int y);
void count_Uncle_and_Aunt(int z);


int main() {
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &P[i]);//!!!!�`�N!!!!�O1-based!!!!

	count_Direct_Blood_Relative(N);
	count_Uncle_and_Aunt(N);
	count_num_of_envelops--;//�]���bcount_Direct_Blood_Relative�Mcount_Uncle_and_Aunt�o��Ө禡���ABob��parent���|�Q���A�ҥH�n�������ƪ�1���C

	printf("%d\n", count_num_of_envelops);

	system("pause");
}

void count_Direct_Blood_Relative(int y) {//�]���L��sample input�u-1 1 2 2 3 3 5 4 4 4 9 9 9�v���ƧǷ����A�ڭn��y��parent�C�]���ڲn��parent�s��x�A�ҥH�{�b�o�Ө�k���W�r�u��s��y�C
	int x = P[y];//x�Oy��parent�C
	if (x != -1) {
		count_num_of_envelops++;
		count_Direct_Blood_Relative(x);
	}
	else return;
}

void count_Uncle_and_Aunt(int z) {//���Wz���z�ѦP�W�C���L�]���o�����D�n�u���O�������A�]�N�Oz��parent��parent�C�ҥHz�o�Oz�Cz��parent�o�Oy�Cz��grandparent�A�]�N�Oz��parent��parent�A�]�N�Oy��parent�A�~��Ox�C
	int y = P[z]; int x = P[y];
	for (int i = 1; i <= z; i++) //�ڭn�}�l�ƣ������ƣ����� �F�C�Ӳz�������ӬO����P�}�C���Ƨ��A�ҥH���ӬOi<=N�~��A���L�]���ڳo�Ө禡�S��������N���T���A�ҥH���Ӧ��Ӳ~�V�~��ڡC��?????���L�A�A�|�o�{�A��nz�N�ON!!!(�D�س]�w��)�ҥH�N�ꥩ�������ӥΡC�`�N!!!!�]���O1-based�A�ҥHi�q1�}�l��C
		if (P[i] == x) count_num_of_envelops++;

	return;
}