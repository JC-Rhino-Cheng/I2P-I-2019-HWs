#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

#define MAX_NUM_OF_PEOPLE 10000000
int comfort_level[MAX_NUM_OF_PEOPLE];//��������У�ÿ���˵�comfort level��
int matched[MAX_NUM_OF_PEOPLE];//����comfort level��X�Ĕ�ֵ��ͬ���˵�"λ��"��
int Tall[MAX_NUM_OF_PEOPLE];
//�������У��������^��ֻ�ܷ���global

int main() {
	int N, X;//N��ʾ��N���ˡ�X����Ąt��Little Brick����λ�õ�comfort level��N��X�ĘOֵ����10^7��
	scanf("%d%d", &N, &X);

	int count = 0;//���ը衦���ը�A���������ж����˵�comfort level��X��ͬ��

	for (int i = 0; i < N; i++) {
		scanf("%d", &Tall[i]);

		int j = i - 1;
		while (j >= 0) {
			if (Tall[i] > Tall[j]) j -= comfort_level[j] + 1;
			else break;
		}
		comfort_level[i] = i - j - 1;
		if (comfort_level[i] == X) matched[count++] = i;//Notice1
	}
	/*line17~27��Ҫ˼·:
	ÿ�ζ����x��ĳ���˵���ߣ�֮���R�Ͼ�Ӌ���@���˵�comfort_level��
	���@���˵�comfort_level��ȫ��ǰ����Щ�˵���ߛQ����
	���N������^����?
	
	!!!���c!!!�҂���֪ǰ�������˵�comfort_level!!!
	�Ǽ�������i���ҵ�comfort_level���N����???���ǲ���Ҫ�ҵ�������ǰ��ĵ�һ�����Ҹߵ��ˡ�!!!
	�������ǰ��ĵ�һ�����Ҹߵ������ľ�̖��j�����ҵ�comfort_level������: i-j-1�ˆ�?
	(i��ָ: �ĵ�"1"�����_ʼ�㣬�����@����̖i���ˣ�������i����)
	(i��ָ: �ĵ�"1"�����_ʼ�㣬�����@����̖j���ˣ�������j����)
	(���ҵ�comfort_level����i-j-1���ǂ��pһ�����Ҫ�۵��Լ���)(Ո���Ю��D���˽�)
	
	����Ҫ���N�ҡ�����ǰ��ĵ�һ�����Ҹߵ���(X)����?
	�ܺ��ΰ�!��ȥ������ǰ��ĵ�һ����(A)������comfort_level�Ƕ���?
	����ȥ�ҡ�����������(A)����comfort_level���@�ӾͿ����ҵ������������˵�ǰ��ĵ�һ�������ߵ���(B)����
	�ҵ��@���˿��Ԏ���?�ܺ��ΰ�!���ֻ���@����(B)�ȡ�����ǰ��ĵ�һ����(A)��߀�ߣ�������A��B֮�g��
	�ҿ��Դ_������B����������˶���A߀��!
	��������ѽ���A߀���ˣ���A��B֮�g�ĳ���B������˶���A��������ֻ��Ҫ�_�JB���ױ��Ҹ�߀���Ұ��ͺ��ˡ�
	
	ѭ���@��˼·��line22�ʹ��Q�������line21��Ҫ�_�����ܳ���߅�硣
	line26:����ҵ��˳�����ͬcomfort_level���ˣ���������candidate�������Ҿ�ӛ�����λ�ã��K��count++��
	*/
	if (count) {
		printf("%d", matched[0] + 1);
		for (int i = 1; i < count; i++) printf(" %d", matched[i] + 1);
		puts("");
	}
	else printf("ouo\n");

	system("pause");
}


//���}��ô������̵�ppt���^���׶�

//Notice1: �@���÷�������!!!!һ��Ҫ����Ϥ!!!!