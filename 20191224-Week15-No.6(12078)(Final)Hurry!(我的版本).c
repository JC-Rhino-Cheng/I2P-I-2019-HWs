#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#pragma warning (disable: 4996)

#define min(a, b) ( ( a < b ) ? a : b )
#define Max_Num_of_People 3002
bool flag_urinal_used[Max_Num_of_People];

int main() {
	unsigned short T; scanf("%hu", &T);
	while (T--) {
		unsigned short N, K; scanf("%hu%hu", &N, &K);

		memset(flag_urinal_used, false, sizeof(flag_urinal_used));
		flag_urinal_used[N + 1] = flag_urinal_used[0] = true;

		for (int i = 0; i < K; i++) {
			int the_MAX_min_LR_of_the_array = -1;
			int the_number_of_urinal_with_the_MAX_min_LR_of_the_array = -1;
			for (int j = 0; j <= N + 1; j++) {
				if (flag_urinal_used[j]) continue;
				int L = 0, R = 0, min_of_L_and_R;
				for (int k = j - 1; k >= 0; k--) {
					if (flag_urinal_used[k])break;
					else L++;
				}
				for (int k = j + 1; k <= N + 1; k++) {
					if (flag_urinal_used[k])break;
					else R++;
				}

				min_of_L_and_R = min(L, R);
				if (min_of_L_and_R > the_MAX_min_LR_of_the_array) {
					the_MAX_min_LR_of_the_array = min_of_L_and_R;
					the_number_of_urinal_with_the_MAX_min_LR_of_the_array = j;
				}
			}
			flag_urinal_used[the_number_of_urinal_with_the_MAX_min_LR_of_the_array] = true;
			if (i == K - 1) printf("%d\n", the_number_of_urinal_with_the_MAX_min_LR_of_the_array);
		}
	}
	system("pause");
}