#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable: 4996)

#define Max_Num 200000
#define Max_Length 101
char input[Max_Num][Max_Length];

int Cmp_string(const void *a, const void *b);//記得qsort配的Compare function，兩個parameter的型別都是const void*

int main() {
	int count = 0;
	while (scanf("%s", input[count]) != EOF) count++;//我只是原本用fgets而已，結果OJ就一直WA!!而且我明明就已經把fgets吃進來的換行給弄成'\0'了還是一樣，只能妥協換scanf

	qsort(input, count, sizeof(input[0]), Cmp_string);//sizeof(input[0])或可寫作: sizeof(char)*Max_Length。永遠記得，qsort裡面的第一參數是void*，所以要靠第三個參數來知道，這個陣列到底是什麼型別

	for (int i = 0; i < count; i++) printf("%s\n", input[i]);

	system("pause");
}

int Cmp_string(const void *a, const void *b) {
	const char *x = (const char *)a;
	const char *y = (const char *)b;
	return strcmp(x, y);
}