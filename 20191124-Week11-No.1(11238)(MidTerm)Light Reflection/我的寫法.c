#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)


int main() {
	unsigned int Height, Width; scanf("%u%u", &Height, &Width);//��ɤ��O��: x=1�Bx=Height�By=1�By=Width

	unsigned int x, y; scanf("%u%u", &x, &y);//�����ثe��m

	unsigned short limit; scanf("%hu", &limit);//�n��X����limit�����y�Ц�m
	unsigned short count = 1;//�����w�g����X��

	short dx[] = { -1,1,1,-1 };
	short dy[] = { 1,1,-1,-1 };//�s��0�B1�B2�B3���O�O: ���k�W�B�k�U�B���U�B���W�Cx�By��V�ĥιq�����}�C���y�жb
	unsigned short direction = 0;//��l��V��: �s��0

	while (count < limit) {
		x += dx[direction]; y += dy[direction];
		if (x == 1 || y == 1 || x == Height || y == Width) {//�p�G��Fx��ɩ�y��ɪ���
			if ((x == 1 || x == Height) && (y == 1 || y == Width)) break;//�p�G�O���I�A����break
			else //�p�G���O���I
				switch (direction) {//�ݥL�쥻�O���Ӥ�V�A�̾ڦ�m���P�A��Ӫ���V����إi��
					case 0:
						if (x == 1) { direction = 1; count++; break; }//�ܴ���V�B�Ƥ@���ܤ�V�Bbreak
						if (y == Width) { direction = 3; count++; break; }
						break;
					case 1:
						if (y == Width) { direction = 2; count++; break; }
						if (x == Height) { direction = 0; count++; break; }
						break;
					case 2:
						if (x == Height) { direction = 3; count++; break; }
						if (y == 1) { direction = 1; count++; break; }
						break;
					case 3:
						if (x == 1) { direction = 2; count++; break; }
						if (y == 1) { direction = 0; count++; break; }
						break;
				}			
		}
	}

	printf("(%u,%u)", x, y);

	system("pause");
}