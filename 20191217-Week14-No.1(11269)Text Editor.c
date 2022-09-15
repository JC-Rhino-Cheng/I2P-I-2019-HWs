#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning (disable: 4996)

#define MAX_Length 510

char before[MAX_Length];
char after[MAX_Length];
short left_boundary = -1, right_boundary = -1;
unsigned short cursor_now_at = 0;


void backspace(void);
void move_right_parallel_a_space(void);
void move_left_parallel_a_space(void);

int main() {
	fgets(before, MAX_Length, stdin);
	for (int i = 0; i < strlen(before) - 1; i++) {
		if (before[i] == '/') {
			switch (before[i + 1]) {
			case 'b':
				backspace();
				i += strlen("backspace");
				break;
			case 'n':
				if (cursor_now_at - 1 == right_boundary) {
					after[cursor_now_at++] = '\n';
					after[cursor_now_at] = '\0';
					right_boundary++;
				}
				else {
					move_right_parallel_a_space();
					after[cursor_now_at++] = '\n';
					right_boundary++;
				}
				i += strlen("newline");
				break;
			case 'l':
				if (cursor_now_at - 1 == left_boundary);
				else cursor_now_at--;
				i += strlen("left");
				break;
			case 'r':
				if (cursor_now_at - 1 == right_boundary);
				else cursor_now_at++;
				i += strlen("right");
				break;
			default:;
			}
		}
		else {
			if (cursor_now_at - 1 == right_boundary) {
				after[cursor_now_at++] = before[i];
				after[i + 1] = '\0';
				right_boundary++;
			}
			else {
				move_right_parallel_a_space();
				after[cursor_now_at++] = before[i];
				right_boundary++;
			}
		}
	}



	printf("%s", after);
	system("pause");
}

void backspace(void) {
	if (cursor_now_at - 1 == left_boundary) return;
	else if (cursor_now_at - 1 == right_boundary) {
		cursor_now_at--;
		right_boundary--;
		return;
	}
	else {
		move_left_parallel_a_space();
		cursor_now_at--;
		right_boundary--;
		return;
	}
}

void move_left_parallel_a_space(void) {
	char temp[MAX_Length];
	int copy_length = strlen(after) - cursor_now_at + 1; //不接受int copy_length = strlen(after[cursor_now_at]) + 1;
	strncpy(temp, after + (cursor_now_at), copy_length); //不接受strncpy(temp, after[cursor_now_at], copy_length);
	strncpy(after + (cursor_now_at - 1), temp, copy_length);//不接受strncpy(after[cursor_now_at - 1], temp, copy_length);

	return;
}

void move_right_parallel_a_space(void) {
	char temp[MAX_Length];
	int copy_length = strlen(after) - cursor_now_at + 1;//不接受int copy_length = strlen(after[cursor_now_at]) + 1;
	strncpy(temp, after + cursor_now_at, copy_length);//不接受strncpy(temp, after[cursor_now_at], copy_length);
	strncpy(after + (cursor_now_at + 1), temp, copy_length);//不接受strncpy(after[cursor_now_at - 1], temp, copy_length);

	return;
}