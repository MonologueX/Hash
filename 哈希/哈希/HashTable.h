#define _CRT_SECURE_NO_WARNINGS 1

//////////////////////////////////////
//头文件
#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <windows.h>
#define N 10
enum STATUS
{
	HTEXIST,
	HTDELETE,
	HTEMPTY,
};
typedef int HTDataType;

typedef struct HashNode
{
	HTDataType _key;
	STATUS _status;
}HashNode;

typedef struct HashTable
{
	HashNode* _tables;
	size_t _size;
	size_t _capacity;
}HashTable;

///////////////////////////////////////
//函数代码

void HTInit(HashTable* ht, size_t capacity)
{
	assert(ht);
	assert(capacity > 0);

	ht->_tables = (HashNode*)malloc(sizeof(HTDataType)*capacity);
	assert(ht->_tables);

	ht->_size = 0;
	ht->_capacity = capacity;
	for (size_t i = 0; i < capacity; ++i)
	{
		ht->_tables[i]._status = HTEMPTY;
	}
}

void HTDestory(HashTable* ht)
{
	assert(ht);
	free(ht->_tables);
	ht->_tables = NULL;
	ht->_size = 0;
	ht->_capacity = 0;
}

size_t HashFunc(HashTable* ht, HTDataType key)
{
	return key % (ht->_capacity);
}

void CheckCapacity(HashTable* ht)
{
	if ((ht->_size)*10 / ht->_capacity > 7)
	{
		HashTable newht;
		HTInit(&newht, (ht->_capacity)*2);
		//把旧表的有效数据插入到新表
		for (size_t i = 0; i < ht->_capacity; ++i)
		{
			if (ht->_tables[i]._status == HTEXIST)
			{
				HTInsert(&newht, ht->_tables[i]._key);
			}
		}
		HTDestory(ht);
		ht->_tables = newht._tables;
		ht->_size = newht._size;
		ht->_capacity = newht._capacity;
	}
}

//成功：0  失败：-1
int HTInsert(HashTable* ht, HTDataType key)
{
	assert(ht);

	CheckCapacity(ht);
	size_t index = HashFunc(ht, key);
	while (ht->_tables[index]._status == HTEXIST)
	{
		if (ht->_tables[index]._key = key)
		{
			return -1;
		}

		++index;
		if (index == ht->_capacity)
		{
			index = 0;
		}
	}
	ht->_tables[index]._key = key;
	ht->_size++;
	ht->_tables[index]._status == HTEXIST;
	return 0;
}

//int HTFind(HashTable* ht, HTDataType key)
//{
//	assert(ht);
//	size_t index = HashFunc(ht, key);
//	while (ht->_tables[index]._status != HTEMPTY)
//	{
//		if (ht->_tables[index]._key = key)
//		{
//			if (ht->_tables[index]._status == HTEXIST)
//			{
//				return 0;
//			}
//			else
//			{
//				return - 1;
//			}
//		}
//
//		++index;
//		if (index == ht->_capacity)
//		{
//			index = 0;
//		}
//	}
//	return -1;
//}
HashNode* HTFind(HashTable* ht, HTDataType key)
{
	assert(ht);
	size_t index = HashFunc(ht, key);
	while (ht->_tables[index]._status != HTEMPTY)
	{
		if (ht->_tables[index]._key = key)
		{
			if (ht->_tables[index]._status == HTEXIST)
			{
				return &(ht->_tables[index]);
			}
			else
			{
				return NULL;
			}
		}

		++index;
		if (index == ht->_capacity)
		{
			index = 0;
		}
	}
	return NULL;
}
int HTRemove(HashTable* ht, HTDataType key)
{
	HashNode* node = HTFind(ht, key);
	if (node)
	{
		node->_status = HTDELETE;
		--ht->_size;
		return 0;
	}
	else
	{
		return -1;
	}
}

/////////////////////////////////////////////
//测试代码
void HTPrint(HashTable* ht)
{
	assert(ht);

	for (size_t i = 0; i < ht->_capacity; ++i)
	{
		if (ht->_tables[i]._status == HTEXIST)
		{
			printf("[EX:%d] ", ht->_tables[i]._key);
		}
		else if (ht->_tables[i]._status == HTDELETE)
		{
			printf("[DEL:%d] ", ht->_tables[i]._key);
		}
		else
		{
			printf("[EM:NULL] ");
		}
	}
	printf("\n");
}

void TestHashTable()
{
	HashTable ht;
	HTInit(&ht, 10);
	HTInsert(&ht, 5);
	HTInsert(&ht, 15);
	HTInsert(&ht, 25);
	HTInsert(&ht, 35);
	HTInsert(&ht, 1);
	HTInsert(&ht, 19);
	HTInsert(&ht, 2);
	HTPrint(&ht);
	HTInsert(&ht, 8);
}