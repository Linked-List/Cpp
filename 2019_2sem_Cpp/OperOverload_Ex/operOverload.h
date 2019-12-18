#pragma once

#include <iostream>

#define MAX_FRAME_SIZE 20

class MyClass2
{
public:
    int myNum;
};

class MyClass
{
private:
    int myNum;
    int arr[10];

public:
    MyClass()
    {
        std::cout << "�⺻������ ȣ��" << std::endl;
        myNum = 0;
        for (int i = 0; i < 10; i++)
            arr[i] = 0;
    } // MyClass a; Ȥ�� new MyClass()�� ȣ���Ҷ� �Ҹ�

    // ���������
    MyClass(const MyClass &op)
    {
        std::cout << "��������� ȣ��" << std::endl;
        myNum = op.myNum;
        for (int i = 0; i < 10; i++)
            arr[i] = op.arr[i];
    }
    // = ������
    void operator=(const MyClass &op)
    {
        std::cout << "=������ ȣ��" << std::endl;
        myNum = op.myNum;
        for (int i = 0; i < 10; i++)
            arr[i] = op.arr[i];
    }

    // ��ȯ������
    // Explicit
    MyClass(const int &op)
    {
        std::cout << "int Ÿ�Ի����� Ȥ�� ��ȯ������ ȣ��" << std::endl;
        myNum = op;
        for (int i = 0; i < 10; i++)
            arr[i] = 0;
    }
    MyClass(const MyClass2 &op)
    {
        std::cout << "MyClass2 Ÿ�Ի����� Ȥ�� ��ȯ������ ȣ��" << std::endl;
        myNum = op.myNum;
        for (int i = 0; i < 10; i++)
            arr[i] = 0;
    }
    // ��ȯ������ - �� ����Ÿ���� ������? ����Ÿ���� �Լ��̸����ڳ�
    // ������� explicit ���𰡴�
    operator int()
    {
        std::cout << "(int) ��ȯ������ ȣ��" << std::endl;
        return myNum;
    }
    operator MyClass2()
    {
        std::cout << "(MyClass2) ��ȯ������ ȣ��" << std::endl;
        MyClass2 a;
        a.myNum = this->myNum;
        return a;
    }

    // + - * / %
    // ���� ���� �Լ� operator+�� ȣ���ϰ�, �Ű������� �����ʳ��� ��.
    MyClass operator+(const MyClass &op)
    {
        MyClass t;
        t.myNum = myNum + op.myNum;
        std::cout << "operator+ ȣ��" << std::endl;
        return t;
    }
    // > < == != <= >=
    // && || !�� ���ϴ°� ��õ
    // ������� ���� �Ȱ�����, ���� ��ȯ���� bool�̶� �׳� �����ô�.
    bool operator<(const MyClass &op)
    {
        std::cout << "operator< ȣ��" << std::endl;
        return myNum < op.myNum;
    }

    // += -= *= /= %=
    // �ϴ� ��Ģ������� ���������δ�, �Լ� ȣ���ϴ� ���� �� ��ü�� �ٲ۴�.
    // =���� �����ڴ� void�� �ص��ǰ� MyClass&�� �ص��ȴ�.
    // ������ ���̴� a = (b = c) �������� �����ϳ� �̴�(void�� �ȵ�).
    MyClass &operator+=(const MyClass &op)
    {
        std::cout << "operator+= ȣ��" << std::endl;
        myNum += op.myNum;
        for (int i = 0; i < 10; i++)
            arr[i] += op.arr[i];
        return *(this);
    }

    // ++ --
    // (int)�κ��� �ǹ̰� �ִ� Ÿ���� �ƴ϶�, �׳� �����̴�. �򰥸��� ����
    MyClass &operator++()
    {
        std::cout << "��������++ ȣ��" << std::endl;
        myNum++;
        return *(this);
    }
    const MyClass operator++(int)
    {
        std::cout << "��������++ ȣ��" << std::endl;
        MyClass a = *this; // ���� �������� �ӽð�ü ��������.
        myNum++;
        // ������ �ø��� �ӽð�ü�� ��ȯ�Ѵ�.
        return a;
    } // �߰� ������ϰ� const����

    // []
    int &operator[](const int index)
    {
        std::cout << "�Ϲݺ����� []ȣ��" << std::endl;
        return arr[index];
    }
    const int operator[](const int index) const
    { // �ڿ� �ִ� const�� ����
        std::cout << "Const ��ü�� []ȣ��" << std::endl;
        return arr[index];
    }
    // ( )
    void operator()(int n1, int n2, int n3)
    {
        std::cout << "operator() ȣ�� " << n1 << " " << n2 << " " << n3 << std::endl;
    }

    // << , >>
    // friend�Լ��� �� Ŭ������ private�� �ǵ帱���ִ� �Լ�
    // friend Ŭ������ �� ������ Ŭ������ Ȯ������
    // Top-level Function�̹Ƿ� �ǹؿ� ���� ������
    friend std::ostream &operator<<(std::ostream &out, const MyClass &op);
    friend std::istream &operator>>(std::istream &in, MyClass &op);

    void* operator new(size_t size); // ���Ǵ� �ؿ�
    void operator delete(void*);

    void setMyNum(int num)
    {
        this->myNum = num;
    }
    int getMyNum() const
    {
        return myNum;
    }
};

std::ostream &operator<<(std::ostream &out, const MyClass &op)
{
    out << "operator<< ȣ�� : " << op.myNum; // cout�� �ƴ϶� �Ű����� out�ΰͿ� ����
    return out;
}
std::istream &operator>>(std::istream &in, MyClass &op)
{
    std::cout << "operator>> ȣ��" << std::endl;
    in >> op.myNum;
    return in;
}

// ���������� �޸� Ǯ �����
unsigned char myFramePool[sizeof(MyClass)*MAX_FRAME_SIZE] = {0,};
bool myFrameOccupied[MAX_FRAME_SIZE] = {0,};

void* MyClass::operator new(size_t size){
    for(int i=0;i<MAX_FRAME_SIZE;i++){
        if(!myFrameOccupied[i]){
            myFrameOccupied[i] = true; // �Ҵ�����ٰ� ǥ��
            std::cout << "Occupied One Memory" << std::endl;
            return reinterpret_cast<MyClass*>(myFramePool)+i; // �����ּ� ��ȯ
        }
    }
    throw "Out of Space";
    return NULL;
}

void MyClass::operator delete(void* address){
    int index = (reinterpret_cast<long>(address) - reinterpret_cast<long>(myFramePool))/sizeof(MyClass);
    myFrameOccupied[index] = false; // �޸� 0���� �ʱ�ȭ�� �ʿ����
    std::cout << "Deleted One Memory" << std::endl;
    return;
}