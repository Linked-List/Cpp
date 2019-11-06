#pragma once

#include "Entry.h"

class ExtEntry : public Entry{
public:
	ExtEntry();
	ExtEntry(std::string key, char* value);
	void setKey(std::string key);
	void setValue(char* value); // ������ ù��° �� ���� (������ //���Ѵ�)
	void setValues(char* value); // ��ü �� ����
	void addValue(char* value); // �� �߰�
	std::string getKey();
	char* getValue(); // ������ ù��° �� ��ȯ
	char* getValues(); // ��ü �� ��ȯ
};