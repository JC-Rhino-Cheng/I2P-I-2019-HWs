#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#pragma warning (disable: 4996)

double prefix(void);

int main() {
	freopen("sample.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	scanf("%d", &N);

	while (N--) {
		double output; int handan_Jap;
		output = prefix();//prefix函式在運行的時候，直接print出運算的式子，並且回傳該式子的計算結果
		handan_Jap = output;
		if (fabs(handan_Jap - output) <= 0.01) printf("= %d\n", handan_Jap);
		else printf("= %.1f\n", output);
	}//line18~line20，題目有規定若整數就不要輸出小數點。若小數點的話只print出小數後一位。

	system("pause");
}

double prefix() {
	char c;
	while ((c = getchar()) != EOF) {
		if (isdigit(c)) {
			ungetc(c, stdin);
			int Num_in; scanf("%d", &Num_in);
			printf("%d ", Num_in);
			return Num_in;
		}
		else if (c == '+') {
			double op1, op2;
			printf("( ");//每次一看到prefix裡面有四則運算的operator，就先印出一個，之後透過line38抓取有效的數值
			op1 = prefix();
			printf("+ ");//每次成功抓到一個數值的時候prefix函式就已經先print出來了，return回來後就馬上在數值後面印出operator。之後用line40抓取第二個有效的數值。
			op2 = prefix();
			printf(") ");//當抓取數值已經完畢，就代表這層運算已經結束的，所以print出)。
			return op1 + op2;//line37~42只有抓取和印出的動作，啊我要return運算結果，所以這樣寫。
		}
		else if (c == '-') {
			double op1, op2;
			printf("( ");
			op1 = prefix();
			printf("- ");
			op2 = prefix();
			printf(") ");
			return op1 - op2;
		}
		else if (c == '*') {
			double op1, op2;
			printf("( ");
			op1 = prefix();
			printf("* ");
			op2 = prefix();
			printf(") ");
			return op1 * op2;
		}
		else if (c == '/') {
			double op1, op2;
			printf("( ");
			op1 = prefix();
			printf("/ ");
			op2 = prefix();
			printf(") ");
			return op1 / op2;
		}
	}
}

//本題寫法請見老師的ppt(Unit7)