#include <iostream>
#include "Add.h"
#include "Div.h"
#include "Sub.h"
#include "Mul.h"
using namespace std;
int main() {
	int x, y;
	char c;
	Calc* cl = nullptr;
	
	cout << "�� ������ �Է��Ͻÿ�" << endl;
	cin >> x >> y;

	cout << "��Ģ������ �ϳ��� �����Ͻÿ�(+,-,*,/)" << endl;
	cin >> c;

	switch(c){
	case '+':
		cl = new Add;
		break;
	case '-':
		cl = new Div;
		break;
	case '*':
		cl = new Mul;
		break;
	case '/':
		cl = new Div;
	}

	if(cl != nullptr){
		cl->setValue(x, y);
			cout << "��� : " << cl->calculate() << endl;
	}

	system("pause");
	return 0;
}