#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"
#pragma warning (disable: 4996)

void Print_List(Node* head);
void Delete_List(Node* head);

int main() {
	char op[10];//op = operation. "10" 是因為， "push"(4)、"pop"(3)、"print"(5)、"reverse"(7)，最多7個字，考慮到結尾的'\0'是8個char，取個簡單點的數字
	
	Node* head = NULL;

	while (~scanf("%s", op)) {
		if (strcmp(op, "push") == 0) {
			int x;
			scanf("%d", &x);
			Push(&head, x);
        }//如果指令是push，則他還有額外的參數需要讀取。是個變數x，屬於-1000到1000的閉區間。
		if (strcmp(op, "pop") == 0) Pop(&head);
		if (strcmp(op, "reverse") == 0) Reverse_List(&head);
		if (strcmp(op, "print") == 0) Print_List(head);
    }

	Delete_List(head);
	head = NULL;

	system("pause");
}

void Print_List(Node* head) {
	if (head == NULL) {
		puts("");
		return;
    }
	printf("%d", head->data);
	if (head->next != NULL) printf(" -> ");
	Print_List(head->next);
}//竟然又是遞迴!!!所以Linked List很有可能又會碰到很多很多很多的可怕的遞迴。

void Delete_List(Node* head) {
	if (head == NULL) return;
	Delete_List(head->next);
	free(head);
}//竟然又是遞迴!!!所以Linked List很有可能又會碰到很多很多很多的可怕的遞迴。