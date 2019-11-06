#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "HighCreditAccount.h"
#include <iostream>

AccountHandler::AccountHandler():accNum(0){}
void AccountHandler::ShowMenu() const{
    std::cout << "1. ���°���" << std::endl;
    std::cout << "2. �Ա�" << std::endl;
    std::cout << "3. ���" << std::endl;
    std::cout << "4. ��������" << std::endl;
    std::cout << "5. ����" << std::endl;
}
void AccountHandler::MakeAccount(){
    int sel=0;
    std::cout << "1. Make Normal Account" << std::endl;
    std::cout << "2. Make Credit Account" << std::endl;
    std::cin >> sel;
    switch(sel){
        case NORMAL:
            MakeNormalAccount();
            break;
        case CREDIT:
            MakeCreditAccount();
    }
}
void AccountHandler::DepositMoney(){
    int ID;
    int money;
    std::cout << "ID�� �Ա��� �ݾ� �Է� : ";
    std::cin >> ID >> money;
    for(int i=0;i<accNum;i++){
        if(accArr[i]->getAccID() == ID){
            accArr[i]->Deposit(money);
            std::cout << "�Ա� ���� ó�� �Ϸ�" << std::endl;
            return;
        }
    }
    std::cout << "[ERROR]�ݾ��� �߸��Ǿ��ų�, ID�� ã���� �����ϴ�." <<std::endl;
}
void AccountHandler::WithdrawMoney(){
    int ID;
    int money;
    std::cout << "ID�� ����� �ݾ� �Է� : ";
    std::cin >> ID >> money;
    for(int i=0;i<accNum;i++){
        if(accArr[i]->getAccID() == ID){
            accArr[i]->Withdraw(money);
            std::cout << "��� ���� ó�� �Ϸ�" << std::endl;
            return;
        }
    }
    std::cout << "[ERROR]�ݾ��� �߸��Ǿ��ų�, ID�� ã���� �����ϴ�." <<std::endl;
}

void AccountHandler::ShowAllAccInfo() const{
    std::cout << "=========�� ���� ����=========\n";
    std::cout << "�̸�\tID\t�ܾ�" << std::endl;
    for(int i=0;i<accNum;i++)
        accArr[i]->ShowAccInfo();
    std::cout << "=========�� �� �� �� =========\n\n";
}

AccountHandler::~AccountHandler(){
    for(int i=0;i<accNum;i++)
        delete accArr[i];
}

void AccountHandler::MakeNormalAccount(){
    int ID;
    char name[NAME_LEN];
    std::cout << "ID, �̸� �Է� : ";
    std::cin >> ID >> name;
    NormalAccount* newAccount = new NormalAccount(ID,0,name,3);
    accArr[accNum++] = newAccount;
    std::cout << "Normal Account ���� �Ϸ�. ����� ID : " << ID << std::endl << std::endl;
}
void AccountHandler::MakeCreditAccount(){
    char name[NAME_LEN];
    int credit;
    int ID;
    std::cout << "ID, �̸��� �ſ���(1~3) �Է� : ";
    std::cin >> ID >> name >> credit;
    if(credit == 1)
        credit = LEVEL_A;
    else if(credit == 2)
        credit = LEVEL_B;
    else
        credit = LEVEL_C;
    HighCreditAccount* newAccount = new HighCreditAccount(ID,0,name,3,credit);
    accArr[accNum++] = newAccount;
    std::cout << "Credit Account ���� �Ϸ�. ����� ID : " << ID << std::endl << std::endl;
}