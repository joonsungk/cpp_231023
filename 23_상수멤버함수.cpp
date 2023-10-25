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

#if 0
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

    Point pt1 { 10, 20 };
    const Point pt2 { 20, 30 }; // 상수 객체(불변 객체, Immutable Object)
    // 상수 객체는 상수 멤버 함수만 호출이 가능합니다.

    const Point* p = &pt1;
    // const Point*
    // => 상수 멤버 함수만 호출이 가능합니다.

    const Point& r = pt;
    // const Point&
    // => 상수 멤버 함수만 호출이 가능합니다.
}
#endif

int main()
{
    const Point pt { 10, 20 };
    // 상수 객체는 const Point* / const Point&를 통해서만 참조할 수 있습니다.

    // Point* p = &pt;
    // Point& r = pt;
    const Point* p = &pt; /* OK */
    const Point& r = pt; /* OK */

    Point pt2 = pt; // OK!, 복사는 허용됩니다.
}
