#include "function.h"
#include <stdlib.h>
#include <math.h>
#pragma warning (disable: 4996)

Point * ones_vec_1(int length) {
	Point* temp = (Point*)malloc(sizeof(Point) * length);
	//寫法一for (int i = 0; i < length; i++) scanf("%d%d", &(*(temp + i)).x, &(*(temp + i)).y);
	for (int i = 0; i < length; i++) scanf("%d%d", &((temp + i)->x), &((temp + i)->y));//寫法二
	return temp;
}

float compute_distance(Point* a, int first_id, int second_id) {
	int dis_x = a[first_id].x - a[second_id].x;
	int dis_y = a[first_id].y - a[second_id].y;
	return (float)sqrt(dis_x * dis_x + dis_y * dis_y);
}