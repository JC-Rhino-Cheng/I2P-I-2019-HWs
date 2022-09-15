#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable: 4996)

int main() {
	freopen("sample.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char input[2001];
	while (scanf("%s", input) != EOF) {
		int count = 0, length = strlen(input);

		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				if (i - j >= 0 && input[i - j] == input[i + 1 + j] && i + 1 + j < length)
					count++;
				else
					break;
			}
		}

		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				if (i - 1 >= 0 && input[i - 1 - j] == input[i + 1 + j] && i + 1 + j < length)
					count++;
				else
					break;
			}
		}
		printf("%d\n", count);
	}



	system("pause");
}