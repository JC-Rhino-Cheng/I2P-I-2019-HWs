#include <stdio.h>
#include <string.h>

int N;//儲存總共有幾個string
char str[5000][5010];//儲存符合pattern的string的內容
int f[5000];//儲存符合pattern的string的頻率(f for frequency)
int temp = 0;//儲存總共有多少"種"string符合pattern

int check(char* input, char* P) {
	char alph1[26] = { '\0' };
	char alph2[26] = { '\0' };
	if (strlen(input) != strlen(P)) return 0;
    else {
		for (int i = 0; i < strlen(P); i++) {
			int idx1 = input[i] - 'a';
			int idx2 = P[i] - 'a';
			if (alph1[idx1] == '\0' && alph2[idx2] == '\0') {
				alph1[idx1] = P[i];
				alph2[idx2] = input[i];
            }
            else {
				if (alph1[idx1] == P[i] && alph2[idx2] == input[i]) continue;
				else return 0;
            }
        }
    return 1;
	}
}

int main(void) {
	char P[5010];
	scanf("%d %s", &N, P);
	for (int i = 0; i < N; i++) {
		char input[5010];
		int flag = 0;
		scanf("%s", input);
		if (check(input, P) == 0) continue;
		int j;
		for (j = 0; j < temp; j++) {
			if (strcmp(str[j], input) == 0) {
				flag = 1;
				break;
            }
        }
		if (flag) f[j]++;
        else {
			strcpy(str[temp], input);
			f[temp] = 1;
			temp++;
        }
    }

	for (int i = 0; i < temp; i++) {
		for (int j = 0; j < temp - i - 1; j++) {
			int flag = 0;
			if (f[j] < f[j + 1]) flag = 1;
			else if (f[j] > f[j + 1]) flag = 0;
            else {
				if (strcmp(str[j], str[j + 1]) > 0) flag = 1;
				else flag = 0;
            }
			if (flag) {
				char change[5010];
				strcpy(change, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], change);

				int change_int = f[j];
				f[j] = f[j + 1];
				f[j + 1] = change_int;
            }
        }
    }

	printf("%d\n", temp);
	for (int i = 0; i < temp; i++) printf("%s %d\n", str[i], f[i]);
}

