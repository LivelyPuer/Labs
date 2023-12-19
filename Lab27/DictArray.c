//#define _CRT_SECURE_NO_WARNINGS
//#include <string.h>
//#include "Dict.h"
//
//#define MAX_WORDS 10000
//
//// ����� 
//char words[MAX_WORDS][MAX_LEN_WORD + 1];
//// ���������� ���� � �������
//int numWords = 0;
//
//
///* CREATE - ������� �������.
//���������� ����� ������� ������������� �������. */
//void Create() {
//	numWords = 0;
//}
//
//
///* DESTROY - ���������� �������.
//���������� ����� ��������� ������������� �������. */
//void Destroy() {
//	numWords = 0;
//}
//
///* INSERT � ��������� ������� � ���������.
//��������� � �������� ������ ���������� ��������.
//��� ��������� ���������� �������� � ���������, ��������� �� ����������. */
//void Insert(char* word) {
//	if (!Member(word)) {
//		if (numWords < MAX_WORDS) {
//			strcpy(words[numWords], word);
//			numWords++;
//		}
//	}
//}
//
//
///* MEMBER � ��������, �������� �� ��������� ������� ������ ������� ��������� ��� ���.
//���� �������� - ���������� 1, ����� - ���������� 0 */
//int  Member(char* word) {
//	for (int i = 0; i < numWords; i++) {
//		if (strcmp(words[i], word) == 0) {
//			return 1;
//		}
//	}
//	return 0;
//}
//
