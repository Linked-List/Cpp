#include <iostream>
#include "Add.h"
#include "Div.h"
#include "Sub.h"
#include "Mul.h"
using namespace std;
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
	}
	else if (c == '-') {
		Sub* cl = new Sub;
		cl->setValue(x, y);
		cout << "��� : " << cl->calculate() << endl;
	}
	else if (c == '*') {
		Mul* cl = new Mul;
		cl->setValue(x, y);
		cout << "��� : " << cl->calculate() << endl;
	}
	else if (c == '/') {
		Div* cl = new Div;
		cl->setValue(x, y);
		cout << "��� : " << cl->calculate() << endl;
	}

	system("pause");
	return 0;
}