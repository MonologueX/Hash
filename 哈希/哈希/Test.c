#define _CRT_SECURE_NO_WARNINGS 1
#include "HashTable.h"
//////////////////////////////////////////
//ͷ�ļ�
#include<stdio.h>
#include<assert.h>
#include <windows.h>


////////////////////////////////////////////
////����
//
//char FindFirstChar(const char* str)
//{
//	//////////////////////////////////////////
//	//��ע
//	//////////////////////////////////////////
//	// abcdabcdef
//	//�����ַ���ֻ����һ��
//	//�����ַ�������n��
//	assert(str);
//	int hash_table[256] = { 0 };
//	const char* s1 = str;
//	while (*s1)
//	{
//		hash_table[(unsigned char)*s1]++;
//		*s1++;
//	}
//	s1 = str;
//	while (*s1)
//	{
//		if (1 == hash_table[(unsigned char)*s1])
//		{
//			printf("%s\n", s1);
//			return *s1;
//		}
//		++s1;
//	}
//	return -1;
//}

int main()
{
	TestHashTable();
	system("pause");
	return 0;
}

//////////////////////////////////////////
//�ʼ�
//////////////////////////////////////////
//1.ֱ�Ӷ�ַ�� -- һ��һӳ��
//2.���������� -- һ�Զ�ӳ��
//3.
//4.