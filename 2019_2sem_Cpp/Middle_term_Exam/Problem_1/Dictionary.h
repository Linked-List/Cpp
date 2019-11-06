#pragma once

#include "Entry.h"

class Dictionary {
private:
	Entry entries[100];
	int size;

public:
	Dictionary();
	Entry* find(std::string key); // ������ null��ȯ �� ��������
	Entry** find(char* value); // ������ null��ȯ �� ��������
	Entry* insert(std::string key, char* value); // ������ Entry�߰�, ������ ��������
	Entry* modify(std::string key, char* value); // ������ �� ����, ������ ��������
	std::string deletion(std::string key); // ������ ����, ������ ���� ����
	void printAll();
};