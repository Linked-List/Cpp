#include "ColorPoint.h"
#include <iostream>

/*
	����3: Point��� Ŭ������ �����, �װ��� ��ӹ޴� ColorPoint Ŭ������ �����Ͽ�
	      �ش� main�Լ��� ���� �۵��ϵ��� ����
*/
int main() {
	ColorPoint cp(10, 20, "RED");
	cp.setPoint(10, 20);
	cp.setColor("Green");
	cp.show(); // ������� ����

	system("pause");
	return 0;
}