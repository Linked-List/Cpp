#include "operOverload.h"
#include <iostream>

// �����Ƽ� �������� �ȳ��� �˾Ƽ� ����.

void func(const MyClass& op){
    std::cout << "MyClass type �Լ� ȣ��" << std::endl;
}
void func2(int op){
    std::cout << "int type �Լ� ȣ��" << std::endl;
}

int main(){
    std::cout << "1-1. MyClass a; ��������" << std::endl;
    MyClass a; // �⺻�����ڰ� �Ҹ��� ���
    std::cout << "1-2. MyClass* ptr = new MyClass;" << std::endl;
    MyClass* ptr = new MyClass; // ���� ����� ����
    delete ptr;

    std::cout << "2-1. 3�� ¥�� Ŭ���� �迭 ����" << std::endl;
    MyClass b[3]; // ����� ���� �ٷ� �����ڰ� �Ҹ��� ���.
    std::cout << "2-2. new�� �̿��� �迭 �����Ҵ�" << std::endl;
    ptr = new MyClass[3]; // ������ ���� ����� ����
    delete[] ptr;

    std::cout << "3-1. ��������� ȣ����1 - MyClass c(a)" << std::endl;
    a.setMyNum(10); // �׽�Ʈ�ϱ����� ��������� ����
    MyClass c(a);
    std::cout << "3-2. ��������� ȣ����2 - MyClass d = a (�ʱ�ȭ���)" << std::endl;
    MyClass d = a;
    std::cout << "3-3. =������ ȣ�� - MyClass e; e = a; (3-2�� ����غ������� �ٸ���.)" << std::endl;
    MyClass e;
    e = a;

    std::cout << "4. ��ȯ������ ȣ�� - �ش� Ÿ�Կ� �ش��ϴ� �����ڰ� �����ϸ� �˾Ƽ� �ٲ���" << std::endl;
    std::cout << "4-1. �ʱ�ȭ �ܰ��� ȣ�� - �ش� Ÿ���� �����ڸ� �׳� �θ�" << std::endl;
    MyClass f(1);
    MyClass g = 1;
    MyClass h = static_cast<MyClass>(1);
    std::cout << "4-2. �׿� �ܰ��� ȣ�� - �ش� �����ڷ� �ӽ� ��ü�� ���� ������ ���Խ�Ų��." << std::endl;
    static_cast<MyClass>(1); // ���� ����ȯ�� ����
    func(1); // �ڵ� ����ȯ�� ����. (�������� �����ھտ� explicit ����)
    
    std::cout << "4-3. Ŭ���������� �����ϳ�? - �����ϴ�." << std::endl;
    MyClass2 aa;
    aa.myNum=10;
    MyClass i = aa; // �ʱ�ȭ �ܰ��� ȣ��
    static_cast<MyClass>(aa); // ��������ȯ
    func(aa); // �ڵ�����ȯ

    std::cout << "4-4. ��ȯ ������" << std::endl;
    (int)i; // C��Ÿ�� ��������ȯ
    static_cast<int>(i); // C++��Ÿ�� ����ȯ
    func2(i); // �ڵ�����ȯ
    
    std::cout << "4-5. �̶��� Ŭ������ ����?" << std::endl;
    static_cast<MyClass2>(i); // �����ϴ�.

    std::cout << "5. ��Ģ/�� ���� �����ε�" << std::endl;
    std::cout << "5-1. + - * / % ����" << std::endl;
    h + i;
    // h + 10;
    // �̴� �츮�� ���� operator int()�� ���Ƿ� ���ؼ� int + int�� ��������.
    // myClass + myClass�� �������� ���� �����Ͽ����� ����.
    h + static_cast<MyClass>(10); // ��ȣ���� ���ָ� ����!
    // �ٸ������ explicit operator int()�� ��ȣ���� �� �ذ��ϸ�ȴ�.
    std::cout << "5-2. < > == != <= >= ����" << std::endl;
    h < i;
    std::cout << "5-3. += -= *= /= %= �� ����" << std::endl;
    std::cout << (h += i).getMyNum() << std::endl; // returnŸ���� ��⶧���� �̷� ������ ����
    std::cout << "5-4. ����������" << std::endl;
    std::cout << "Original : " << h.getMyNum() << std::endl;
    std::cout << (++h).getMyNum() << std::endl;
    std::cout << (h++).getMyNum() << std::endl;
    
    std::cout << "5-5. �迭������" << std::endl;
    h[0] = 10;
    const MyClass& p2 = h;
    p2[0];
    std::cout << "5-6. �Լ�������" << std::endl;
    h(10,20,30); // �Ű������� ������ ������� �ٲܼ��ִ�.
    // C++���� �̰� �̿��� Java�� Comparator�� �����Ѵ�.
    // C++ Functor �˻�

    std::cout << "6-1. IO������" << std::endl;
    std::cin >> h;
    std::cout << h << std::endl; // �� �� ���

    /*
    �߰�����
    ��� �������� ���� ��� ��ü�� �ӽð��̴�.
    ��) int num = 1+2; ���⼭ 3�� �ӽð��̴�.
    �� �ӽ��� ���� �����ʿ� �׻� ���⶧���� R-Value��� �θ���.
    ����� ����Ǹ� �������� ���̴�.
    �� ����� ����ϸ� �Ⱦ��ټ��� �ִ�. �̸� ����ִ� ����� �ΰ����̴�.
    const int& / ������ int type��, ������ int type ��θ� �����Ҽ��ִ�.
    int&& / �������� �����ؼ� �����Ѵ�. (�������� ���� ������)
    �ٸ� ������ ��� const�̱⶧���� ���� �������� ���Ѵ�.

    �̰� �� �˾ƾ��ϳ�.
    return type�� MyClass�̸� ��ȯ�� �� �������� ������ �ȵ��ֱ⶧���� R-Value�̴�.
    a+(b+c)�� �ϸ� b+c�� ���� �ӽð����� a�� operator+�� ���ڷ� ���޵ȴ�.
    ���� operator+(int& a)�� �����ϸ� ������ ���ϴ�.
    -> operator+(const int& a)�� �����ϰų� r-value�� ���� operator+(int&& a)�� �߰��� �����ؾ��Ѵ�.
    */
    int myNum = 1;
    const int& p = 10+20;
    const int& p3 = myNum;
    int&& p4 = 10; // �̰Ͷ��� �������̴�.
    //int&& p5 = myNum; ����
    p4++; // �� �ӽð��� ���浵 �����ϴ�. **10�̶�� ���ͷ��� �ٲٴ°� �ƴϴ�.**
    std::cout << "���ͷ� 10 : " << 10 << std::endl;
    std::cout << "�ӽð� p4 ���� : " << p4 << std::endl;


    // �޸��Ҵ����� ������ new delete �����ε�
    std::cout << "7-1. �����س��� new �Լ� ��� �õ�" << std::endl;
    MyClass* z = new MyClass;
    z->setMyNum(50);
    std::cout << "z�� �ּڰ� : " << reinterpret_cast<long>(z) << std::endl;
    std::cout << "���� ���� ���Ǹ޸� �ּڰ� : " << reinterpret_cast<long>(myFramePool) << std::endl;
    std::cout << "��ġ�ϴ� ����� ����" << std::endl;
    std::cout << "z1�����س��ٰ� �� ��� : " << z->getMyNum() << std::endl;
    std::cout << "7-2. delete �Լ� ���" << std::endl;
    delete z;
    
    std::cout << "7-3. �迭�� �� �Ǵ°�?" << std::endl;
    z = new MyClass[5];
    std::cout << "z�� �ּڰ� : " << reinterpret_cast<long>(z) << std::endl;
    std::cout << "���� ���� ���Ǹ޸� �ּڰ� : " << reinterpret_cast<long>(myFramePool) << std::endl;
    delete[] z;
    std::cout << "�� �ȵ�~ new[] delete[] �ٽ� �����ؾ��ϴµ� �ȹ���� ���� ����" << std::endl;
    
    return 0;
}