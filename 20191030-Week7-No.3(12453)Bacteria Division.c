#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable: 4996)
#define MOD 10177

long long fast_pow(int base, int index);

int main() {
	freopen("sample.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int x, y, n;
	while (scanf("%d%d%d", &x, &y, &n) != EOF) {
		int base = y + 1, index = n - 1;
		printf("%llu\n", ( ( fast_pow(base, index) % MOD ) * (x % MOD)) % MOD ); // Note1-1
	}
	system("pause");
}

long long fast_pow(int base, int index) {
	if (index == 0) return 1;
	else if (index & 1) {
		long long temp = fast_pow(base, index / 2) % MOD;
		return (temp * temp * base) % MOD; //Note1-2
	}
	else {
		long long temp = fast_pow(base, index / 2) % MOD;
		return (temp * temp) % MOD; //Note1-3
	}
}


/*
Note1: 我原本看不懂https://acm.cs.nthu.edu.tw/problem/12453/內的code為啥要在Note1-2(也就是line23處) %MOD，想說，
你這樣寫難道不會改變餘數的數值嗎?
結果就看到了日月卦長所給出的救贖https://reurl.cc/aldRpl:

::同餘性質
::由於計算方法數的題目通常答案都很大
::通常會叫你將答案mod一個整數
::因此這些性質會經常被使用(翻譯都先各自mod之後，再多mod幾次(至少一次))
::(A+B)%M=(A%M+B%M)%M
::(A×B)%M=(A%M×B%M)%M

*/