#include <stdio.h>
#include <stdlib.h>

void main() {
	int in, in_backup, trans, trans_backup;//in用來輸入、trans用來儲存in+1。backup各自備份
	int a[11] = { 0 };//in的二進位轉換，最高位是a[10]、最低位是a[0]
	int b[11] = { 0 };//trans的二進位轉換，最高位是b[10]、最低位是b[0]
	int count_for_binary, count_for_JinWei_times;

	//從line10~line27是在處理第一個輸出
	scanf_s("%d", &in);
	in_backup = in;
	trans = in + 1;
	trans_backup = trans;
	for (int i = 0; trans != 0; i++) {
		b[i] = trans % 2;
		trans /= 2;
	}//line13~line16的迴圈用來取值二進位
	for (int i = 10; ; i--) {
		if (b[i] != 0){
			count_for_binary = i;//從最高位開始的第一個不為零的，紀錄為count_for_binary，故只要從a[count_for_binary]開始往a[0]輸出即可
			break;
		}
	}
	for (int i = count_for_binary ; i >= 0; i--) {
		printf("%d", b[i]);//從a[count_for_binary]開始往a[0]輸出
	}
	
	//從line29~line40是在處理總共進位了幾次
	for (int i = 0; in != 0; i++) {
		a[i] = in % 2;
		in /= 2;
	}//line30~line33的迴圈用來取值二進位
	for (int i = 0; ; i++) {
		if (a[i] == 0){
			count_for_JinWei_times = i;//如果數字是101101100111，從最低位開始數，第"四"個開始不為0，則記錄count_for_JinWei_times為3
			break;
		}
	}
	printf(" %d", count_for_JinWei_times);
	
	
	
	system("pause");
}