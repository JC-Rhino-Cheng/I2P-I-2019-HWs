#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 0, M = 0;
	int a[101] = { 0 };
	long double sum = 0, temp = 0;
	int result_in_int;//我原本沒有這行
	scanf_s("%d %d", &N, &M);
	for (int n = N; n >= 0; n--) 
		scanf_s("%d", &a[n]);
	for (int n = N; n >= 0; n--) {
		temp = 1;
		for (int j = 0; j < n; j++) 
			temp *= M;
		temp *= a[n];
		sum += temp;
	}//Technique1
	result_in_int = sum;//我原本沒有這行
	printf("%d\n", result_in_int);//我原本沒有這行
	//printf("%Lf\n", sum);//我原本這行沒有標成註解
	system("pause");
}
/*
Note1: 我原本沒有line8、line21~23，是因為看到OJ裡面的題目描述裡有:
-(10)^9 ≤ f(M) ≤ 10^9
但是judge結果0/4，全部Wrong Ans，所以我開啟BreakPoint，結果程序執行的完全沒有問題，
我就猜是不是帶有太多小數點，結果取整數就AC==
好吧! 其實你的題目敘述裡面，丟入函數的值是整數，所有係數也都是整數，姑且算你
"-(10)^9 ≤ f(M) ≤ 10^9"是多寫出來的垃圾話吧。



Technique1: line10~18的for loop可以改寫成:
for(int n = N; n>=0; n--)
	sum +=  a[n] * pow(M, n) ;
善用math.h中的pow函式!
*/