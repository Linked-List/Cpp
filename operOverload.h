#include <iostream>

class MyClass{
private:
    int myNum;
    int arr[10];

public:
    MyClass(); // MyClass a; Ȥ�� new MyClass()�� ȣ���Ҷ� �Ҹ�

    // ���������
    // =
    MyClass(const MyClass& op);
    void operator=(const MyClass& op);

    // ��ȯ������
    // Explicit
    MyClass(int op);
    MyClass(int* op);
    operator int();
    //MyClass 2 type?

    // + - * / %
    // > < == != 
    // && || !�� ���ϴ°� ��õ
    // += -= *= /= %=
    // ++ --
    MyClass operator+(const MyClass& op); // ��������ִ�.
    bool operator==(const MyClass& op); // ���� �񱳿����� bool��ȯ����?
    MyClass& operator+=(const MyClass& op);
    MyClass operator++();
    MyClass operator++(int);

    // []
    // ( )
    int& operator[](const int index);
    int operator[](const int index) const;
    void operator()(int num, int num2, int num3);

    // <<
    // >>
    friend std::ostream& operator<<(std::ostream& out, const MyClass& op);
    friend std::istream& operator>>(std::istream& in, MyClass& op);

// template

// R-value Reference + �̵�������

};