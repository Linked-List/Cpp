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
		delete cl;
	}

	system("pause");
	return 0;
}