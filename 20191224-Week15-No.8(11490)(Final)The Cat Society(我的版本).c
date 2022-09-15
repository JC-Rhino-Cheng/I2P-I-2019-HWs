#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable: 4996)

#define MAX_num_of_cats_and_food 10000

int Cmp(const void *, const void *);

typedef struct _Cat {
	char name[31];
	unsigned short occupation;
	unsigned short age;
}Cat;

int main() {
	unsigned short N, M;
	Cat cat_number[MAX_num_of_cats_and_food];

	while (scanf("%hu%hu", &N, &M) == 2) {
		char occupation_title[11];//工作名稱最長的是apprentice，而strlen("apprentice")=10。考慮到結尾的'\0'，故取11
		for (int i = 0; i < N; i++) {
			scanf("%s %s %d", cat_number[i].name, occupation_title, &(cat_number[i].age));
			switch (occupation_title[0]) {
			case'e': {cat_number[i].occupation = 1; break; }
			case'n': {cat_number[i].occupation = 2; break; }
			case'k': {cat_number[i].occupation = 3; break; }
			case'w': {cat_number[i].occupation = 4; break; }
			case'a': {cat_number[i].occupation = 5; break; }
			case'm': {cat_number[i].occupation = 6; break; }
			case'd': {cat_number[i].occupation = 7; break; }
			case'l': {cat_number[i].occupation = 8; break; }
			default:;
			}
		}

		qsort(cat_number, N, sizeof(Cat), Cmp);

		for (int i = 0; i < N&&i < M; i++) puts(cat_number[i].name);

	}


	system("pause");
}


int Cmp(const void* a, const void *b) {
	Cat A = *(Cat *)a;
	Cat B = *(Cat *)b;

	if (A.occupation < B.occupation)return -1;
	else if (A.occupation > B.occupation)return 1;
	else {
		if (A.age > B.age) return (A.occupation == 5) ? 1 : -1;
		else if (A.age < B.age) return (A.occupation == 5) ? -1 : 1;
		else return strcmp(A.name, B.name);
	}

}