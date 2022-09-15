#include "function.h"
#include <stdlib.h>
#pragma warning (disable: 4996)

Node* My_Reverse_List(Node *A, Node *B);

void Push(Node** ptr_head, int x) {
	if (*ptr_head == NULL) {//�p�G�ثe��head�S��������󪺶�(��N�ONode���N��)�A�N��o��Linked List�ثe�S������F��
		Node *temp;//Linked List��̫�ڭ̤��|�h�ި쩳�C�@�Ӷ�(�]�N�ONode)���W�r�O����A�ҥH�W�٤@�I�������n
		temp = (Node *) malloc ( sizeof(Node) );//��malloc�X�@�Ӷ�C
		temp->data = x;//�o�Ӷ�̭���data�s�Jx
		temp->next = NULL;//�o�Ӷ�n���N�쥻��head�A�ҥH��̭���next�Ҧs���N�O�쥻head�ҫ���NULL
		*ptr_head = temp;//head�N���A��NULL�A����ڭ��malloc�X�Ӫ���C
	}
	else {//�M�W��Q�k�@�ˡA�u���ǳ\���P�A���`�O
		Node *temp = (Node *) malloc ( sizeof(Node) );
		temp->data = x;
		temp->next = *ptr_head;//�smalloc�X�Ӫ���̭���next�n�x�s���O�쥻��head Node�A�]�N�Ohead�ҫ���Node"��m"�ҫ���Node�C
		*ptr_head = temp;
	}
	return;
}

void Pop(Node** ptr_head) {
	if (*ptr_head == NULL);//�p�G�쥻��head�N�w�g���VNULL�A�N�N��o��Linked List�̭��w�g�S��Node��F�A�ҥHԣ�Ƴ����ηF�A����return�Y�i�C
	else {
		Node *original_head = *ptr_head;//����쥻��head�ҫ���Node��m�s�_�ӡC
		*ptr_head = (*ptr_head)->next;//��head������쥻head�ҫ���Node"��m"�ҫ���Node�Ҧs��next�C
		free(original_head);
	}
}

void Reverse_List(Node** ptr_head) {
	if (*ptr_head == NULL) return;
	Node *New_head;
	New_head = My_Reverse_List(*ptr_head, (*ptr_head)->next);
	(*ptr_head)->next = NULL;
	*ptr_head = New_head;
	return;
}

Node* My_Reverse_List(Node *A, Node *B) {
	if (A->next == NULL) return A;
	Node* New_head = My_Reverse_List(B, B->next);
	B->next = A;
	return New_head;
}
