#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#pragma warning (disable: 4996)


int main(void){
	Point *point_array;
	int M, N;
	float ans;

	scanf("%d", &M);
   // give point_array memory and get first element address
	point_array = ones_vec_1(M);

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
      // compute distance of two points
		ans = compute_distance(point_array, first, second);
		printf("%.3f\n", ans);
   }

	system("pause");
}
