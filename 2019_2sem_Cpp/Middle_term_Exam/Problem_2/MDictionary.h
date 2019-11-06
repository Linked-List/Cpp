#pragma once

#include "ExtEntry.h"

class MDictionary {
private:
	ExtEntry extEntries[100];
	int size;

public:
	MDictionary();
	ExtEntry* find(std::string key); // ������ null��ȯ �� ��������
	ExtEntry** find(char* value); // ������ null��ȯ �� ��������
	ExtEntry*insert(std::string key, char* value); // key�� �������� ������ Entry�߰� ������, �� �߰�
	std::string deletion(std::string key); // ������ ��������
};
