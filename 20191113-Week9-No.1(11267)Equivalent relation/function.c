#include <stdio.h>
#include "function.h"

void execInst(int *ptrArr[], char inst, int param1, int param2) {//Notice1、2
	if (inst == 'P') {//換成 指別的指標所指的位置。P 1 2 ，指把2所儲存的"int變數的位置"丟給1儲存。
		ptrArr[param1] = ptrArr[param2];//Notice3
		//(ptrArr +param1) = (ptrArr + param2);//為啥不能這樣寫??
	}
	else if (inst == 'S') {//賦值
		*ptrArr[param1] = param2;//Notice4
	}


	return ;
}

/*
Notice1: 自己在開頭所Declare的東西不能和實際應用的function所寫的parameter有絲毫不一樣，否則會runtime error
比如說，開頭declare:
void execInst(int *ptrArr[], char inst, int param1, int param2);
實際應用:
void execInst(int *ptrArr, char inst, int param1, int param2){}
一定報錯!!!

Notice2: 如果你要傳入一個陣列，則parameter處一定要有[]!!!!!
當寫成: void execInst(int *ptrArr[], char inst,........)，則可以正確使用array
若寫成: void execInst(int *ptrArr, char inst,...........)，則無法使用array，將會導致access reading violation，
因為在賦予值(line9)的時候，程式邏輯會變成把"ptrArr[param1] == &ptrArr[param1]==這個位置" 設定成param2

Notice3: 
對於程式而言，因為是一個獨立的function(名叫execInst的函式)，在parameter處所接收到的
訊息"int *ptrArr[]"的含意是"一個位置"，所以，
ptrArr[param1] = ptrArr[param2]中，
對於這個函式，ptrArr[param1]並沒有int值的意義，而只有ptrArr+param1的位置意義。
也因此，牽扯到Notice4。

Notice4:
line9中，*ptrArr[param1] = param2。如同Notice3所述，ptrArr[param1]只有位置意義，所以需要dereference。
如果直接寫成ptrArr[param1] = param2，一樣會access reading violation
*/