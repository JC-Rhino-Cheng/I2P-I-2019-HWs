#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#pragma warning (disable: 4996)

int main() {
	int *array, **ptr;
	int N, offset;
	scanf("%d %d", &N, &offset);

	malloc_array(&array, (1 + N)*N / 2);
	ptr = malloc_ptr(N);

	for (int i = 0; i < (1 + N)*N / 2; i++) array[i] = i;
	pointer_ptr_to_array(array, ptr, N);
	for (int i = 0; i < N; i++) printf("%d\n", *(ptr[i] + (offset)));

	free(ptr);
	free(array);

	system("pause");
}
