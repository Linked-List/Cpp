#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"
using namespace std;

int main(){
    List list;
    List list2;
    list.add("�Ǳ����б�");
    list.add("���ѹα�");
    list.add("�����");
    list.fileSave();

    list2.fileLoad();
    list2.printAll();
    return 0;
}