// 2차원 배열포인터
// type (*) [열크기] - 이거가 통틀어서 2차원 배열포인터 타입임

// 2차원 배열포인터 선언
// type (*ptr)[열크기]; 일케하면 만들어진거

// C,C++에서 2차원 배열 포인터 리턴 하는법
// type(*함수명(매개변수))[열크기]{
//     2차원 배열 포인터 반환
//}

//---------------------------------------------

// 1차원 배열 레퍼런스
// type (&) [크기]

// 2차원 배열 레퍼런스
// type (&) [행크기][열크기]

// 1차원 배열 레퍼런스 선언
// type (&ref)[크기] = arr; 레퍼런스니까 바로 배열 넣어줘야하지?

// 2차원 배열 레퍼런스 선언
// type (&ref)[행크기][열크기] = arr2d;

// 비슷하게 레퍼런스 배열도 반환한다. 대신 레퍼런스는 1차원에서 갯수 알려주고, 2차원은 행 열 크기 다 줘야한다.
// type(&함수명(매개변수))[크기]{
//     1차원 배열 레퍼런스 반환
//}

// type(&함수명(매개변수))[행크기][열크기]{
//     2차원 배열 레퍼런스 반환
//}

#include <iostream>

struct A
{
    enum
    {
        Rows = 3,
        Cols = 4
    };
    int matrix[Rows][Cols];
    int (&operator[](size_t i))[Cols]
    {
        return matrix[i];
    }
};

int main()
{
    A a;
    int k = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            a[i][j] = k++;
    // a[i]는 operator[]를 불러서 크기가 Cols인 일차원배열레퍼런스를 반환한다. 그래서 i번째 행의 배열을 반환함
    // a[i]가 배열이니까 [j]는 당연히 되겠쥬?
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            std::cout << a[i][j] << "\t";
        std::cout << std::endl;
    }
    return 0;
}