#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning (disable: 4996)

int Check(char*, char*);
int Qualified_strings[5001][5001];
int frequency[5001];
int count_types_of_qualified_strings;

int main() {
	int N; char Pattern[5001];//N代表:後面總共有N個待比對字串。Pattern代表: 要比較的目標字串。
	scanf("%d %s", &N, Pattern);

	for (int i = 0; i < N; i++) {
		char input[5001]; scanf("%s", input);

		if (Check(input, Pattern) == 0)continue;

		int j = 0; int flag_found_the_same_string = 0;
		for (; j < count_types_of_qualified_strings; j++) {
			if (strcmp(Qualified_strings[j], input) == 0) {
				flag_found_the_same_string = 1;
				break;
			}
		}
		if (flag_found_the_same_string) frequency[j]++;
		else {
			strcpy(Qualified_strings[count_types_of_qualified_strings], input);
			frequency[count_types_of_qualified_strings++] ++;
		}
	}



	for (int i = 0; i < count_types_of_qualified_strings - 1; i++) {
		for (int j = 0; j < count_types_of_qualified_strings - i - 1; j++) {
			int flag_whether_need_to_exchange = 0;
			if (frequency[j] < frequency[j + 1]) flag_whether_need_to_exchange = 1;
			else if (frequency[j] > frequency[j + 1])flag_whether_need_to_exchange = 0;
			else if (frequency[j] == frequency[j + 1]) {
				if (strcmp(Qualified_strings[j], Qualified_strings[j + 1]) > 0)flag_whether_need_to_exchange = 1;
			}

			if (flag_whether_need_to_exchange) {
				char temp_for_string[5001];
				strcpy(temp_for_string, Qualified_strings[j]);
				strcpy(Qualified_strings[j], Qualified_strings[j + 1]);
				strcpy(Qualified_strings[j + 1], temp_for_string);

				int temp_for_frequency = frequency[j];
				frequency[j] = frequency[j + 1];
				frequency[j + 1] = temp_for_frequency;
			}
		}
	}








	printf("%d\n", count_types_of_qualified_strings);
	for (int i = 0; i < count_types_of_qualified_strings; i++)printf("%s %d\n", Qualified_strings[i], frequency[i]);



	system("pause");
}

int Check(char* input, char* Pattern) {
	if (strlen(input) != strlen(Pattern)) return 0;
	else {
		char check_to_bound[5001]; memset(check_to_bound, '\0', sizeof(check_to_bound));
		char check_from_bound[5001]; memset(check_from_bound, '\0', sizeof(check_from_bound));
		for (int i = 0; i < strlen(Pattern); i++) {
			int index1 = input[i] - 'a';
			int index2 = Pattern[i] - 'a';
			if (check_to_bound[index1] == '\0' && check_from_bound[index2] == '\0') {
				check_to_bound[index1] = Pattern[i];
				check_from_bound[index2] = input[i];
			}
			else if (check_to_bound[index1] == Pattern[i] && check_from_bound[index2] == input[i])continue;
			else return 0;
		}
		return 1;
	}
}