#include <iostream>
#include "Add.h"
#include "Div.h"
#include "Sub.h"
#include "Mul.h"
using namespace std;
/*
	����2: Calc��� Ŭ������ ������ ��.
	       Calc�� ��ӹ޴� Ŭ����4�� Add, Sub, Mul, Div�� �����ϰ�
		   ���� Ŭ������ �´� calculate() �޼ҵ带 �����϶�.
		   ���� Main�Լ����� ��Ģ���꿡 ���缭 Ŭ������ �����Ҵ� �ϰ�
		   ������� ����ض�.
*/
int main() {
	int x, y;
	char c;
	
	cout << "�� ������ �Է��Ͻÿ�" << endl;
	cin >> x >> y;

	cout << "��Ģ������ �ϳ��� �����Ͻÿ�(+,-,*,/)" << endl;
	cin >> c;

	if (c == '+') {
		Add* cl = new Add;
		cl->setValue(x, y);
		cout << "��� : " << cl->calculate() << endl;
		delete cl;
	}
	else if (c == '-') {
		Sub* cl = new Sub;
		cl->setValue(x, y);
		cout << "��� : " << cl->calculate() << endl;
		delete cl;
	}
	else if (c == '*') {
		Mul* cl = new Mul;
		cl->setValue(x, y);
		cout << "��� : " << cl->calculate() << endl;
		delete cl;
	}
	else if (c == '/') {
		Div* cl = new Div;
		cl->setValue(x, y);
		cout << "��� : " << cl->calculate() << endl;
		delete cl;
	}

	system("pause");
	return 0;
}