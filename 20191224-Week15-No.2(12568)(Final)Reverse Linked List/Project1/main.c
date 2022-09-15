#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"
#pragma warning (disable: 4996)

void Print_List(Node* head);
void Delete_List(Node* head);

int main() {
	char op[10];//op = operation. "10" �O�]���A "push"(4)�B"pop"(3)�B"print"(5)�B"reverse"(7)�A�̦h7�Ӧr�A�Ҽ{�쵲����'\0'�O8��char�A����²���I���Ʀr
	
	Node* head = NULL;

	while (~scanf("%s", op)) {
		if (strcmp(op, "push") == 0) {
			int x;
			scanf("%d", &x);
			Push(&head, x);
        }//�p�G���O�Opush�A�h�L�٦��B�~���ѼƻݭnŪ���C�O���ܼ�x�A�ݩ�-1000��1000�����϶��C
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
}//���M�S�O���j!!!�ҥHLinked List�ܦ��i��S�|�I��ܦh�ܦh�ܦh���i�Ȫ����j�C

void Delete_List(Node* head) {
	if (head == NULL) return;
	Delete_List(head->next);
	free(head);
}//���M�S�O���j!!!�ҥHLinked List�ܦ��i��S�|�I��ܦh�ܦh�ܦh���i�Ȫ����j�C