#include <stdio.h>
#include <stdlib.h>

int main() {
	int hourly_sala;
	int h1, m1, s1, h2, m2, s2;
	int time_stamp1, time_stamp2;
	int time_span, span_hr, span_min, span_sec;
	scanf_s("%d", &hourly_sala);
	scanf_s("%d:%d:%d ~ %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);//Notice1見下方
	time_stamp1 = h1 * 3600 + m1 * 60 + s1;
	time_stamp2 = h2 * 3600 + m2 * 60 + s2;
	time_span = time_stamp2 - time_stamp1;
	span_sec = time_span % 60;
	time_span = (time_span - span_sec) / 60;
	span_min = time_span % 60;
	span_hr = (time_span - span_min) / 60;
	printf("Working Time: %d Hour(s) %d Minute(s) %d Second(s)\n", span_hr, span_min, span_sec);
	printf("Daily Wage: %d TWD\n", span_hr* hourly_sala);


	system("pause");
}
/*
Notice1: 其實scanf可以針對特定格式去進行輸入! 比如說我要求要存入
YYYY/MM/DD HH:MM:SS，那scanf就以("%d/%d/%d %d:%d:%d",&y,&m,&d,&h,&min,&s);
呈現即可。但是要注意!!如果我scanf呈現("%d/%d",&y,&m)，但是使用者輸入的格式是YYYY, MM
那麼電腦無法正確接收在YYYY以後的所有變數的值!

*/