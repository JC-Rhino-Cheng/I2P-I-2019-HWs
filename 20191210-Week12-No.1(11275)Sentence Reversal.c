#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning (disable: 4996)

#define Max_length 502//�D�ػ��̪�500�r���A�p�G�Ҽ{�쵲����\0�A�O501�r���C�i�O�]�����U�Ϊ��Ofgets�A�L�|Ū�J\n�A�ҥH�ֻ̤ݭn502�C

void sentence_reversal(char *now, char* original_pos);

int main() {
	char input[Max_length];
	while (fgets(input, Max_length, stdin) != NULL) {
		//�p�G��Jabc�A��ڤW���r��O: input[0�B1�B2�B3�B4]='a'�B'b'�B'c'�B'\n'�B'\0'�Clength=4�C
		input[strlen(input) - 1] = '\0';//�ҥH��input[length-1]�אּ'\0'�C

		sentence_reversal(input, input);//�i�J���j�A��Ҧ�������X���C
		puts("");//��곣�w�greverse�n��A�i�J�U�Ӧr�ꪺreverse�e�A������C
	}
	system("pause");
}

void sentence_reversal(char *now, char* original_pos) {
	if (now[0] == '\0') return;//Basis�C�p�G�w�g�ˬd��y�l���̧��ݪ�'\0'�F�A����X�A�����^��W��recursion�C

	int now_word_length = 0;
	for (int i = 0;; i++) {
		if (now[i] == ' ' || now[i] == '\0') {//�y���A�������Ů�O��' '�ӧP�_�C���F�Ҷq��̫�@�ӵ��A�ҥH�h�[�Jnow[i]=='\0'�C
			now_word_length = i;//�z�Li�Ӽƥثe�Ҧb��"��"���h�֦r���C
			sentence_reversal(now + now_word_length + 1, original_pos);//��������U�@��"��"�C�z�Lnow+now_word_length+1�Ӫ�����Ǹ���U��"��"
			break;
		}
	}//���ɤw�g���D�F�ثe�Ҧb����������

	char temp[Max_length];
	strncpy(temp, now, now_word_length); temp[now_word_length] = '\0';//��ثe�Ҧb�����ƻs��temp�}�C�̡C�ӳ̫�ݭn�O�o��'\0'�_�h�L�kprintf�C//Notice1�C

	if (now == original_pos) printf("%s", temp);//�p�G�O��X���̫�@�ӵ�(�]�N�O�ϥΪ̩ҿ�J���Ĥ@�ӵ�)�A�h�᭱���Ů�C
	else printf("%s ", temp);

	return;
}


//Notice1: ���ǥѳo�ӨҤl�A�Ӧn�n��|����n��str"n"cpy�A���O�u�n��strcpy�N�n�C