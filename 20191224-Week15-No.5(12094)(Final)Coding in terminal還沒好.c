#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning (disable: 4996)

#define MAX_Length 100005

char input[MAX_Length];
char output[MAX_Length];
int left_boundary = -1, right_boundary = -1;
int cursor = 0;
int width = 80;

void Left_Shift(void);
void Right_Shift(void);
void Print(char *);

int main() {
	fgets(input, MAX_Length, stdin);
	//input[strlen(input) - 1] = '\0';

	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == '\n') continue;
		else if (input[i] == '\\') {
			switch (input[i + 1]) {
			case 'n':
				if (cursor - 1 == left_boundary) {
					Right_Shift();
					output[cursor++] = '\n';
					right_boundary++;
				}
				else if (cursor - 1 == right_boundary) {
					output[cursor++] = '\n';
					output[cursor] = '\0';
					right_boundary++;
				}
				else {
					Right_Shift();
					output[cursor++] = '\n';
					right_boundary++;
				}
				i++;
				break;
			case 'b':
				if (cursor - 1 == left_boundary);
				else if (cursor - 1 == right_boundary) {
					cursor--;
					right_boundary--;
				}
				else {
					Left_Shift();
					cursor--;
					right_boundary--;
				}
				i++;
				break;
			case 'l':
				if (cursor - 1 == left_boundary);
				else if (cursor - 1 == right_boundary) cursor--;
				else cursor--;
				i++;
				break;
			case 'r':
				if (cursor - 1 == left_boundary)cursor++;
				else if (cursor - 1 == right_boundary);
				else cursor++;
				i++;
				break;
			case 's': {
				//要處理s [x y]。
				//要做的事情有: 
				//(Step0)因為's'是input[i+1]，所以'['是input[i+3]。x的第一位數字是input[i+4]。
				//(Step1)抓取x的數值成int，並且計算x為幾位數。
				//(Step2)x是幾位數已經知道以後，就可以精確跳到y的第一位數字
				//(Step3)抓取y的值、並計算y為幾位數。
				//(Step4)藉由x、y為幾位數字，仿照上面的n、b、l、r這些operation的「i++」，去精準跳到下一個指令。
				int x_length = 0, y_length = 0;
				int x = 0;

				for (int j = i + 4; input[j] != ' '; j++) {
					x *= 10; x += input[j] - '0';
					x_length++;
				}width = x;

				for (int j = i + 4 + x_length + 1; input[j] != ']'; j++) y_length++;

				i += x_length + y_length + 5;
			}
			default:;
			}
		}
		else {
			if (cursor - 1 == right_boundary) {
				output[cursor++] = input[i];
				output[cursor] = '\0';
				right_boundary++;
			}
			else {
				Right_Shift();
				output[cursor++] = input[i];
				right_boundary++;
			}
		}
	}

	Print(output);

	system("pause");
}


void Left_Shift(void) {
	char temp[MAX_Length];
	int copy_length = strlen(output) - cursor + 1;
	strncpy(temp, output + (cursor), copy_length);
	strncpy(output + (cursor - 1), temp, copy_length);

	return;
}

void Right_Shift(void) {
	char temp[MAX_Length];
	int copy_length = strlen(output) - cursor + 1;
	strncpy(temp, output + (cursor), copy_length);
	strncpy(output + (cursor + 1), temp, copy_length);

	return;
}


void Print(char *string) {
	int Starting_Point_of_the_New_Line = 0;
	int flag_Endline = 0;

	while (string[Starting_Point_of_the_New_Line] != '\0') {
		int i;
		for (i = Starting_Point_of_the_New_Line; i < Starting_Point_of_the_New_Line + width; i++) {
			if (string[i] != '\n' && string[i] != '\0') putchar(string[i]);
			else if (string[i] == '\0') { flag_Endline = 1; break; }
			else { i++; break; }
		}
		if (!flag_Endline)printf("\n");
		Starting_Point_of_the_New_Line = i;
	}

}