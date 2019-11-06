#include <iostream>

class FruitSeller{
private:
    int Apple_Price;
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int money){
        Apple_Price = price;
        numOfApples = num;
        myMoney = money;
    }

    int SaleApples(int money){
        int num = money/Apple_Price;
        numOfApples -= num;
        myMoney += money;
        return num;
    }

    void showSalesResult(){
        printf("���� ��� : %d\n", numOfApples);
        printf("�Ǹ� ���� : %d\n", myMoney);
    }
};

class FruitBuyer{
private:
    int myMoney;
    int numOfApples;

public:
    void InitMembers(int money){
        myMoney = money;
        numOfApples = 0;
    }
    void BuyApples(FruitSeller& seller, int money){
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }
    void ShowBuyResult(){
        printf("���� �ܾ� : %d\n", myMoney);
        printf("��� ���� : %d\n", numOfApples);
    }
};

int main(){
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);

    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    printf("-- ���� �Ǹ����� ��Ȳ --\n");
    seller.showSalesResult();

    printf("-- ���� �������� ��Ȳ --\n");
    buyer.ShowBuyResult();
    return 0;
}