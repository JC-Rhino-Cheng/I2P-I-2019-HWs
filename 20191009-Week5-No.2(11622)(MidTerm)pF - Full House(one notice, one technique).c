#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning (disable: 4996)

int main(){
	freopen("sample.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	short T;//T表示總共有T組牌，極值10000
	scanf("%hd", &T);
	while(T--){
		char arr[5][3];//因為一組大牌，一定有5張牌，所以有5。至於3，是因為考慮到如果是有丟出任一張10(ex: 10鐵支)，那這樣就要有三格來儲存('1'、'0'、'\0')。我原本是只用一維陣列(char arr['16', since (1、0、\0)* 5 + \n = 16])想要讀取整個一串而沒有根據不同卡牌存入不同x-axis的陣列，然後才在煩惱之後排序很難處理....真TM智障
		for(int i = 0; i < 5; i++) scanf("%s", arr[i]);//因為scanf是停讀點是在遇到\n或空格的時候，現在的情況是空格，所以剛好拿來用。這裡fgets就不好用。
		for(int i = 0; i < 5; i++){
			for(int j = i + 1; j < 5; j++){
				if( strcmp ( arr[i], arr[j] ) > 0 ){//Technique1。"cmp" is compare in short.
					char temp[3];
					strcpy_s( temp, arr[j] );//Notice1。"cpy" is copy in short.
					strcpy_s( arr[j], arr[i] );
					strcpy_s( arr[i], temp );
				}
			}
		}//line14~23的迴圈是在把所有x-axis的橫列橫列們依照ASCII字典序來排列
		if( strcmp( arr[0] , arr[1]) == 0 && strcmp( arr[1] , arr[2]) == 0 &&strcmp( arr[3] , arr[4]) == 0 ) printf("YES\n");
		else if( strcmp( arr[0] , arr[1]) == 0 && strcmp( arr[2] , arr[3]) == 0 &&strcmp( arr[3] , arr[4]) == 0 ) printf("YES\n");
		else printf("NO\n");
	}	
	system("pause");
}

/*
Technique1: 在字典裡，當前面字串應該比後面字串放在後面的時候(即ASCII排序: arr[i] > arr[j])，則strcmp(,)返回值為正。當前面字串應該比後面字串放在前面的時候(即ASCII排序: arr[i] < arr[j])，則strcmp(,)返回值為負。用正負的技巧，可以來判斷是否要調整順序。另外，當前面字串和後面字串沒有先後之分時(即ASCII排序: arr[i] = arr[j])，則strcmp(,)返回值0。所以可以藉由strcmp(,)返回是否為0來判斷兩個字串是否一模一樣，line24~25即是此技巧的展現。
Notice1: C語言裡面，字串是沒辦法透過類似temp = "1234abcd" 的方式賦值的，必須經過strcpy的手續。
*/
//助教的版本比較簡單，而且即便沒有載入header: string.h 一樣可以用，可以參考看看。