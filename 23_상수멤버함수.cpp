// 23_상수멤버함수.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    // 상수 멤버 함수
    // => 멤버 함수 안에서 객체의 상태를 변경할 수 없습니다.
    // : 객체의 상태를 변경하지 않는 모든 멤버 함수는 상수 멤버 함수로 제공해야 합니다.
    void Print() const
    {
        // 상수 멤버 함수 안에서는 멤버 데이터를 const 취급합니다.
        // int -> const int
        // x = 10;
        // y = 10;

        cout << x << ", " << y << endl;
    }

    void SetX(int a)
    {
        x = a;
    }

    void SetY(int b)
    {
        y = b;
    }
};

void foo(const Point& pt)
{
    // pt.SetX(10);
    // pt.SetY(20);

    pt.Print();
}

int main()
{
    Point pt { 10, 20 };
    foo(pt);
}
