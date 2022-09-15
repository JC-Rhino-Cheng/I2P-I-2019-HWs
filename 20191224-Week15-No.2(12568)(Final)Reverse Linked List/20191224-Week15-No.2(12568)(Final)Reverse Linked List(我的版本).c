#include "function.h"
#include <stdlib.h>
#pragma warning (disable: 4996)

Node* My_Reverse_List(Node *A, Node *B);

void Push(Node** ptr_head, int x) {
	if (*ptr_head == NULL) {//如果目前的head沒有指到任何的圓(圓就是Node的意思)，代表這個Linked List目前沒有任何東西
		Node *temp;//Linked List到最後我們不會去管到底每一個圓(也就是Node)的名字是什麼，所以名稱一點都不重要
		temp = (Node *) malloc ( sizeof(Node) );//先malloc出一個圓。
		temp->data = x;//這個圓裡面的data存入x
		temp->next = NULL;//這個圓要取代原本的head，所以圓裡面的next所存的就是原本head所指的NULL
		*ptr_head = temp;//head就不再指NULL，轉指我剛剛malloc出來的圓。
	}
	else {//和上方想法一樣，只有些許不同，見注記
		Node *temp = (Node *) malloc ( sizeof(Node) );
		temp->data = x;
		temp->next = *ptr_head;//新malloc出來的圓裡面的next要儲存的是原本的head Node，也就是head所指的Node"位置"所指的Node。
		*ptr_head = temp;
	}
	return;
}

void Pop(Node** ptr_head) {
	if (*ptr_head == NULL);//如果原本的head就已經指向NULL，就代表這個Linked List裡面已經沒有Node圓了，所以啥事都不用幹，直接return即可。
	else {
		Node *original_head = *ptr_head;//先把原本的head所指的Node位置存起來。
		*ptr_head = (*ptr_head)->next;//把head轉指成原本head所指的Node"位置"所指的Node所存的next。
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
