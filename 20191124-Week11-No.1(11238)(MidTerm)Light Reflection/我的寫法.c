#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)


int main() {
	unsigned int Height, Width; scanf("%u%u", &Height, &Width);//邊界分別為: x=1、x=Height、y=1、y=Width

	unsigned int x, y; scanf("%u%u", &x, &y);//紀錄目前位置

	unsigned short limit; scanf("%hu", &limit);//要輸出撞第limit次的座標位置
	unsigned short count = 1;//紀錄已經撞牆幾次

	short dx[] = { -1,1,1,-1 };
	short dy[] = { 1,1,-1,-1 };//編號0、1、2、3分別是: 往右上、右下、左下、左上。x、y方向採用電腦式陣列型座標軸
	unsigned short direction = 0;//初始方向為: 編號0

	while (count < limit) {
		x += dx[direction]; y += dy[direction];
		if (x == 1 || y == 1 || x == Height || y == Width) {//如果到達x邊界或y邊界的話
			if ((x == 1 || x == Height) && (y == 1 || y == Width)) break;//如果是頂點，直接break
			else //如果不是頂點
				switch (direction) {//看他原本是哪個方向，依據位置不同，後來的方向有兩種可能
					case 0:
						if (x == 1) { direction = 1; count++; break; }//變換方向、數一次變方向、break
						if (y == Width) { direction = 3; count++; break; }
						break;
					case 1:
						if (y == Width) { direction = 2; count++; break; }
						if (x == Height) { direction = 0; count++; break; }
						break;
					case 2:
						if (x == Height) { direction = 3; count++; break; }
						if (y == 1) { direction = 1; count++; break; }
						break;
					case 3:
						if (x == 1) { direction = 2; count++; break; }
						if (y == 1) { direction = 0; count++; break; }
						break;
				}			
		}
	}

	printf("(%u,%u)", x, y);

	system("pause");
}