#include <stdio.h>
#include "function.h"

void execInst(int *ptrArr[], char inst, int param1, int param2) {//Notice1�B2
	if (inst == 'P') {//���� ���O�����Щҫ�����m�CP 1 2 �A����2���x�s��"int�ܼƪ���m"�ᵹ1�x�s�C
		ptrArr[param1] = ptrArr[param2];//Notice3
		//(ptrArr +param1) = (ptrArr + param2);//��ԣ����o�˼g??
	}
	else if (inst == 'S') {//���
		*ptrArr[param1] = param2;//Notice4
	}


	return ;
}

/*
Notice1: �ۤv�b�}�Y��Declare���F�褣��M������Ϊ�function�Ҽg��parameter�����@���@�ˡA�_�h�|runtime error
��p���A�}�Ydeclare:
void execInst(int *ptrArr[], char inst, int param1, int param2);
�������:
void execInst(int *ptrArr, char inst, int param1, int param2){}
�@�w����!!!

Notice2: �p�G�A�n�ǤJ�@�Ӱ}�C�A�hparameter�B�@�w�n��[]!!!!!
��g��: void execInst(int *ptrArr[], char inst,........)�A�h�i�H���T�ϥ�array
�Y�g��: void execInst(int *ptrArr, char inst,...........)�A�h�L�k�ϥ�array�A�N�|�ɭPaccess reading violation�A
�]���b�ᤩ��(line9)���ɭԡA�{���޿�|�ܦ���"ptrArr[param1] == &ptrArr[param1]==�o�Ӧ�m" �]�w��param2

Notice3: 
���{���Ө��A�]���O�@�ӿW�ߪ�function(�W�sexecInst���禡)�A�bparameter�B�ұ����쪺
�T��"int *ptrArr[]"���t�N�O"�@�Ӧ�m"�A�ҥH�A
ptrArr[param1] = ptrArr[param2]���A
���o�Ө禡�AptrArr[param1]�èS��int�Ȫ��N�q�A�ӥu��ptrArr+param1����m�N�q�C
�]�]���A�o���Notice4�C

Notice4:
line9���A*ptrArr[param1] = param2�C�p�PNotice3�ҭz�AptrArr[param1]�u����m�N�q�A�ҥH�ݭndereference�C
�p�G�����g��ptrArr[param1] = param2�A�@�˷|access reading violation
*/