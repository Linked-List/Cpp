#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/*
	����5: LinkedList�� �����ϰ�, word.txt ���Ϸκ��� ���� �о LinkedList�� Add ���ص�
		   printAll �޼ҵ带 �����Ͽ� LinkedList�� ���� ��µǵ��� ����
*/
int main() {
	LinkedList list;
	ifstream ifs;
	ifs.open("word.txt");
	
	list.readFile(ifs);
	list.printAll();


	ifs.close();
	system("pause");
}