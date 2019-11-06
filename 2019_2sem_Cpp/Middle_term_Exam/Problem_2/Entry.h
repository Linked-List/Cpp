#pragma once

#include <string>

class Entry {
private:
	std::string key; // �ܾ��
	char* value; // �ǹ�

public:
	Entry();
	Entry(std::string key, char* value);
	void setKey(std::string key);
	void setValue(char* value);
	std::string getKey();
	char* getValue();
	~Entry(); // �޸� ���� �ذ�� �Ҹ���
};