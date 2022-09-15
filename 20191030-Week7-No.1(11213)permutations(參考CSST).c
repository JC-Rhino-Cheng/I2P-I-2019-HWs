#include <stdio.h>
#include <stdlib.h>
#pragma warning ( disable: 4996 )

char list[6];

void show(int n);//記得如果要判斷每個遞迴是否有沒有正確進入，可以用最簡單的方法判斷，那就是: 在遞迴函式的開頭位置寫一行: printf("%d%d%d%d", ..,..,..,..,......)
//記得，每個題目都要從最簡單測資的著手!!!!助教給的最簡單測資，可能也沒有到真的最簡單，所以可以自己造一個簡單測資!!!
void Swap(int k, int i);
void Perm(int k, int n);

int main(void) {
	int num, i;

	scanf("%d", &num);

	for (i = 0; i < num; i++) list[i] = '1' + i;//如果num是4，則list[0~3]分別是char的1、2、3、4
	Perm(0, num);
	system("pause");
	return 0;
}




void show(int n) {
	int i;
	printf("(%c", list[0]);
	for (i = 1; i < n; i++) printf(",%c", list[i]);
	printf(")\n");
}

void Swap(int k, int i) {
	char temp = list[k];
	list[k] = list[i];
	list[i] = temp;
}

void Perm(int k, int n) {
	if (k == n) {
		show(n);
	}
	for (int i = k; i < n; i++) {
		Swap(k, i);
		Perm(k + 1, n);
		Swap(i, k);
	}
}