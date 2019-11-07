#include <iostream>
#include <string>

using namespace std;

int operator/(string str, string find)
{
    int count = 0;
    int index = -1;
    while ((index = str.find(find)) != -1)
    {
        str.erase(index, find.length());
        count++;
    }
    return count;
}
string operator-(string str, string del)
{
    int index = -1;
    if ((index = str.find(del)) != -1)
        str.erase(index, del.length());
    return str;
}
string operator*(string str, int num)
{
    string tmp = string();
    while (num > 0)
    {
        tmp += str;
        num--;
    }
    return tmp;
}

int main()
{
    string s1 = "this is test string. test is ok.";
    string s2, s3, s4, s5, s6;
    int n;

    n = s1 / "test"; // s1�� ���Ե� "test"�� ���� ��ȯ : n=2
    cout << n << endl;

    s2 = s1 - "test"; // s1���� "test"�� ������� ����(���鹮�� ����) : s2 = "this is  string. test is ok.";
    cout << s2 << endl;
    s3 = s2 - "test"; // s3 = "this is  string.  is ok.";
    cout << s3 << endl;

    n = s3 / "test"; // n = 0
    cout << n << endl;

    string word = "test";
    s4 = word * 3; // "test"�� 3�� �ݺ��ϴ� ���ڿ� ���� : s4 = "testtesttest"
    cout << s4 << endl;

    // '-' �� '*' �����ڴ� ������ ���� ���ӵ� ������ �����ؾ� ��
    s5 = s1 - "test" - "this"; // s5 = " is  string. test is ok"
    cout << s5 << endl;

    string word2 = "bbaq";
    s6 = word2 * 3 * 2; // s6 = "bbaqbbaqbbaqbbaqbbaqbbaq"
    cout << s6 << endl;
    return 0;
}