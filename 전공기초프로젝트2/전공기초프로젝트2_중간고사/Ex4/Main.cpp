#include <iostream>
#include "People.h"
#include "AddressBook.h"
/*
	����4: People Ŭ������ �����ϰ�, �Ʒ� main�޼ҵ� ����� �ش� ������°� �������� ����
	      *�� ������ �� ����δ� .h���Ͽ�, ���Ǻδ� .cpp���Ͽ� ����� ������.
	
	���� �ν��Ͻ� ���� 14
	�̴��� ������ �����̽��ϴ�.
	������ ������ �����̽��ϴ�.
	���� �ν��Ͻ� ���� 12
	����Ϸ��� �ƹ� Ű�� �����ʽÿ�...
*/
int main() {
	People kim;
	People jang("��");
	People* lee = new People("��");
	People* choi = new People("��", 35);
	People peoples1[10];
	AddressBook addBook1;
	for (int i = 0; i < 10; i++) {
		peoples1[i].setAge(20 + i);
	}

	cout << "���� �ν��Ͻ� ���� " << People::countCreated() << endl;
	delete(lee);
	delete(choi);
	cout << "���� �ν��Ͻ� ���� " << People::countCreated() << endl;

	system("pause");
}