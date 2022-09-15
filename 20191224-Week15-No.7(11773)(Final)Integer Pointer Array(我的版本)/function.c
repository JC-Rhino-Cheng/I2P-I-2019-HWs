#include "function.h"
#include <stdlib.h>
#pragma warning (disable: 4996)


void malloc_array(int **array, int array_size) {
	*array = (int *) malloc ( sizeof(int)*array_size );
	return;
}


int** malloc_ptr(int array_size) {
	int **the_first_element_of_this_array;
	the_first_element_of_this_array = (int **) malloc ( sizeof(int *)*array_size );
	return the_first_element_of_this_array;
}


void pointer_ptr_to_array(int *array, int **ptr, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0, sum = 0; j < N; j++) {
			sum += j;
			*(ptr + j) = &array[sum];
		}
	}
	return;
}

