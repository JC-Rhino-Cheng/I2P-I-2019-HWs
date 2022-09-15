#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#pragma warning (disable: 4996)

int gcd(int a, int b);
int lcm(int a, int b);
int power(int a, int b);

int main(){
	freopen("sample.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d\n", gcd(lcm(power(a, b), c), d) );
	printf("%d\n", gcd(power(lcm(a, b), c), d) );
	printf("%d\n", lcm(gcd(power(a, b), c), d) );
	printf("%d\n", lcm(power(gcd(a, b), c), d) );
	printf("%d\n", power(gcd(lcm(a, b), c), d) );
	printf("%d\n", power(lcm(gcd(a, b), c), d) );
	system("pause");
}


int gcd(int a, int b){
	int gcd = 1 ;//gcd要初始為1，因為兩數可能互質，如果沒初始化的話gcd會是亂數。
	int min;
	min = ( a < b ) ? a : b;
	for(int i = 1; i <= min; i++)//我只要從1判斷到a、b兩數中較小者即可。
		if( a % i == 0 && b % i == 0) gcd = i;
	return gcd;
}

int lcm(int a, int b){
	int lcm, flag_lcm_finded = 0;
	lcm = ( a > b ) ? a : b ;//最小公倍數一定>=兩數之中較大者。
	do{
		if( lcm % a != 0 || lcm % b != 0)	lcm++;
		else flag_lcm_finded = 1;
	}while( ! flag_lcm_finded );//如果目前設定的lcm不能把a、b兩數都整除，那就要把lcm++，之後再試一次能否把兩數都整除。如果能整除，代表已經找到真正的lcm了，就跳脫迴圈，所以設計了一個flag來判斷是否跳出。
	return lcm;
}

int power(int a, int b){
	int result;
	result = pow(a, b);//直接從math.h調用函式。pow回傳值為float，不過我的result變數為int，所以會自動降等。OK的。
	return result;
}



/*
Technique1: 關於gcd，可使用輾轉相除法，可參見https://hackmd.io/yUcW1UmPR8io2pGCn16J7g?view
Technique2、3: 關於power，由於math.h裡面的函數power很容易overflow，所以也可參見以上網址，其中，
	若不懂: (1)，"b & 1" 的含意，看https://stackoverflow.com/questions/26812562/what-does-condition-ifk-1-mean-in-c
	若不懂: (2)，(1)中所說的bitwise AND operation，看https://openhome.cc/Gossip/CGossip/LogicalBitwise.html
	若不懂: (3)，(1)中所說的LSB，查維基百科

*/