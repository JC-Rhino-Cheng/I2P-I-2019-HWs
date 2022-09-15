#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

short dx[] = { 0,1,0,-1 };
short dy[] = { 1,0,-1,0 };//Direction0�B1�B2�B3���O�O: ���k�B���U�B�����B���W

unsigned int N, M;//�@�Ӧa�ϡA�`�@�ON*M�Ӯy�Ц�m�C
char map[1001][1001];//N�BM���ȳ��O1000�C

unsigned short visited[1001][1001];//�w�g������l�Ƭ�0�F�C
unsigned short flag_reached_Teleport;

void go_maze(int, int);

int main() {
	unsigned int T; scanf("%u", &T);//�`�@�|��T�Ӧa��

	while (T--) {
		scanf("%u%u", &N, &M);//�@�Ӧa�Ϥ��A�`�@��N*M�Ӯy�Ц�m�C
		memset(visited, 0, sizeof(visited));;//��l�Ƭ�0�A�]�N�O�C�@���s���g�c�A�C�Ӯ�l���n���]���S���L
		flag_reached_Teleport = 0;//��l�Ƭ�0�A�]�N�O�^��S���J�LTeleport�����A

		for (int i = 0; i < N; i++) scanf("%s", map[i]);//Ū�J�a��

		go_maze(0, 0);
		if (flag_reached_Teleport) {
			for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
				if (map[i][j] == 'T') go_maze(i, j);
		}//line27~30��if: �p�G���J�LT�A�N��L�O�i�H�������ʨ����t�@��T���A�ҥH�ڥu�n���L��Ӧa�ϡA���Ҧ�T�Ҧb����m�A�îھڱ��쪺T�A���A���L�Ҧ��HT���_�I���|�Y�i�C

		printf("%s\n", visited[N - 1][M - 1] ? "Yes" : "No");
	}

	system("pause");
}


void go_maze(int x_now, int y_now) {
	if (visited[x_now][y_now]) return;//�p�G�o��w�g�ӹL�F�A�N����return
	
	//�H�U���O�w�g�Ƭd�L�A�T�w�S���ӹL�����ΡC
	visited[x_now][y_now] = 1;//�]���S���ӹL�A�ҥH���⪬�A�令"�ӹL"�C
	if (map[x_now][y_now] == 'T') flag_reached_Teleport = 1;//�p�G�o��OT�A�N��"���J��T"�����ҧ令true
	for (int i = 0; i < 4; i++) {//�b�o��A�}�l�P�w�W�U���k�|�Ӥ�쪺�u�i��ʡv
		int x_next = x_now + dx[i]; int y_next = y_now + dy[i];

		if (x_next < 0 || y_next < 0 || x_next >= N || y_next >= M) continue;//�p�G�ثe�w�w�e�����U�@��b��ɥ~�A�O�u���i��v�A�ҥH����continue�Ӵ���V�C
		if (map[x_next][y_next] == '#') continue;//�p�G�ثe�w�w�e�����U�@��Owall�A�O�u���i��v�A�ҥH����continue�Ӵ���V�C
		go_maze(x_next, y_next);//�w�g�T�w�O�i�쪺�F�A�ҥH�N���o�̨��C
	}
	return;
}