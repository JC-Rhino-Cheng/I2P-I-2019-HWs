#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable: 4996)

short N;//��JN�A��ܦ�NxN����}�C�̤j�Ȭ�10
unsigned int matrix[10][10];//�x�s�D�ةҴ��Ѫ��x�}
unsigned short count_spots_visited;//�����w�g��L�h�֦a��
unsigned short flag_spot_visited[10];//�O���C���I�O�_�h�L
//�H�W�ܼơA������l�ȳ��O0�A�]���Oglobal definition
unsigned int total_distance;//�x�s�ثe���j���`�Z��
unsigned int min_distance = 100000000;//�x�s�ثe�]�L���Ҧ�"�`""����"�Z�����A�̤p���@��

void find_for_min_distance(int Now_At);

int main() {
	scanf("%hd", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%u", &matrix[i][j]);

	count_spots_visited = 1;   	flag_spot_visited[0] = 1;
	//line18�A�]���_�I�@�w�Opost office�A�]�N�OA�I�A�ҥH�����]�w���y�X�LA�I�C
	find_for_min_distance(0);

	printf("%u\n", min_distance);
	system("pause");
}

void find_for_min_distance(int Now_At) {
	if (count_spots_visited == N) {
		if (total_distance + matrix[0][Now_At] < min_distance) min_distance = total_distance + matrix[0][Now_At];
		return;
	}
	for (int i = 1; i < N; i++) {
		if (!flag_spot_visited[i]) {
			flag_spot_visited[i] = 1;
			count_spots_visited++;
			total_distance += matrix[Now_At][i];
			find_for_min_distance(i);
			total_distance -= matrix[Now_At][i];
			count_spots_visited--;
			flag_spot_visited[i] = 0;
		}
	}
	return;
}


//�o�D�u�n�ݹLOJ���ԭz�A�~�[�����@�U�W����code�N�i�A�����A�h�y�z�쩳�ӳ����B�@�C�U�Ъ�ppt�򥻤W���ݭn�ݴN�i�H�����~�O�C�p�G�o�ݧU��ppt�~������W���b�F���A�N��A�Ӯz�C