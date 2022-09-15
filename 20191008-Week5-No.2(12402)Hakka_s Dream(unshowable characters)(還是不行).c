#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable: 4996)

int main() {
	freopen("sample.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		int x, y;
		double growth_rate;
		scanf("%d%d", &x, &y);
		growth_rate = (float) (y - x) / x * 100;

		growth_rate = round(10000 * growth_rate) / 10000;

		growth_rate = (fabs(growth_rate) < 0.0049 && growth_rate < 0 ) ? -growth_rate : growth_rate;

		printf("%7.2f%% ", growth_rate);
		if (growth_rate >= 0.05) printf("(#`Д´)ﾉ\n");
		else if (growth_rate <= -0.05) printf("(ゝ∀･)b\n");
		else printf("\\^o^/\n");
	}
}
