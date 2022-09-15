#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable: 4996)

#define Max_Num 200000
#define Max_Length 101
char input[Max_Num][Max_Length];

int Cmp_string(const void *a, const void *b);//ӛ��qsort���Compare function���ɂ�parameter���̈́e����const void*

int main() {
	int count = 0;
	while (scanf("%s", input[count]) != EOF) count++;//��ֻ��ԭ����fgets���ѣ��Y��OJ��һֱWA!!�������������ѽ���fgets���M��ēQ�нoŪ��'\0'��߀��һ�ӣ�ֻ���ׅf�Qscanf

	qsort(input, count, sizeof(input[0]), Cmp_string);//sizeof(input[0])��Ɍ���: sizeof(char)*Max_Length�����hӛ�ã�qsort�e��ĵ�һ������void*������Ҫ��������������֪�����@����е�����ʲ�N�̈́e

	for (int i = 0; i < count; i++) printf("%s\n", input[i]);

	system("pause");
}

int Cmp_string(const void *a, const void *b) {
	const char *x = (const char *)a;
	const char *y = (const char *)b;
	return strcmp(x, y);
}