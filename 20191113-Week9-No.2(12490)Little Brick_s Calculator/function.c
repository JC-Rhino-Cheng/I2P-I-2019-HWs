/*#include <stdio.h>
#include <ctype.h>
#include "function.h"

int flag_is_used[1000010];

int solver(int **ptr, int *sum, char *s){
	int count_num_of_valid_numbers = 0;
	for (int i = 0; i < 1000010; i++) {
		if (!flag_is_used[i]) {
			if (s[i] == '-' || s[i] == '+') {
				if (s[i] == '+') {
					int j = i;
					int temp = 0;
					for (int k = j + 1; isdigit(s[k]); k++) {
						temp *= 10; temp += s[k] - '0';
						flag_is_used[k]++;
					}
					**(ptr + count_num_of_valid_numbers) = temp;
					count_num_of_valid_numbers++;
				}
				else {
					int j = i;
					int temp = 0;
					for (int k = j + 1; isdigit(s[k]); k++) {
						temp *= 10; temp += s[k] - '0';
						flag_is_used[k]++;
					}
					temp *= -1;
					**(ptr + count_num_of_valid_numbers) = temp;
					count_num_of_valid_numbers++;
				}
			}
			else if (isdigit(s[i])) {
				int temp = 0;
				for (int j = i; isdigit(s[j]); j++) {
					temp *= 10; temp += s[j] - '0';
					flag_is_used[j]++;
				}
				**(ptr + count_num_of_valid_numbers) = temp;
				count_num_of_valid_numbers++;
			}
		}
	}
	

	int total = 0;
	for (int i = 0; i < count_num_of_valid_numbers; i++) {
		total += **(ptr + i);
	}
	*sum = total;
	return count_num_of_valid_numbers;
}*/









#include <stdio.h>
#include <ctype.h>
#include "function.h"

int solver(int **ptr, int *sum, char *s)
{
	int i = 0, j = 0;
	while (s[i] != '\0')
		i++;
	ungetc('b', stdin);
	for (j = i - 1; j >= 0; j--) {
		if (isdigit(s[j]) || (s[j] == '-' && isdigit(s[j + 1])))
			ungetc(s[j], stdin);
		else
			ungetc(' ', stdin);
	}
	i = 0;
	while (scanf_s("%d", ptr[i])) {
		*sum += *ptr[i];
		i++;
	}
	return i;
}
