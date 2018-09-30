#define _CRT_SECURE_NO_WARNINGS 1
#include "HashTable.h"
//////////////////////////////////////////
//头文件
#include<stdio.h>
#include<assert.h>
#include <windows.h>


////////////////////////////////////////////
////函数
//
//char FindFirstChar(const char* str)
//{
//	//////////////////////////////////////////
//	//备注
//	//////////////////////////////////////////
//	// abcdabcdef
//	//查找字符串只出现一次
//	//查找字符串出现n次
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
//笔记
//////////////////////////////////////////
//1.直接定址法 -- 一对一映射
//2.除留余数法 -- 一对多映射
//3.
//4.