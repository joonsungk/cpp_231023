// 23_상수멤버함수2.cpp
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

    void Print() const { cout << x << ", " << y << endl; }

    void Move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
};

class Rect {
    Point leftTop;

public:
    Rect(int x, int y)
        : leftTop { x, y }
    {
    }

    // 상수 멤버 함수는 멤버 데이터를 const 취급합니다.
    // 참조를 반환할 경우, const &를 반환해야 합니다.
    const Point& GetLeftTop() const { return leftTop; }
    Point& GetLeftTop() { return leftTop; }
    // C++에서 비상수 멤버 함수와 상수 멤버 함수를 동시에 제공할 수 있습니다.
    // => 참조를 반환할 때, 많이 사용합니다.

    Point GetLeftTop2() const { return leftTop; }
    // 객체 내부의 상태를 외부에서 연산을 수행하는 것이 좋지 않다.
};

// 상수 멤버 함수 / 비상수 멤버 함수를 모두 제공할 경우
//          Rect r; ---> 비상수 멤버 함수 호출
//   const  Rect r; --->  상수 멤버 함수 호출
//   const Rect* r; --->  상수 멤버 함수 호출
//   const Rect& r; --->  상수 멤버 함수 호출

// 상수 멤버 함수
//          Rect r; ---> 상수 멤버 함수 호출
//   const  Rect r; ---> 상수 멤버 함수 호출
//   const Rect* r; ---> 상수 멤버 함수 호출
//   const Rect& r; ---> 상수 멤버 함수 호출

// 비상수 멤버 함수
//          Rect r; ---> 비상수 멤버 함수 호출
//   const  Rect r; ---> X
//   const Rect* r; ---> X
//   const Rect& r; ---> X

void foo(const Rect& r)
{
    const Point& pt = r.GetLeftTop(); // Error!
    pt.Print();
}

int main()
{
    Rect r { 10, 20 };
    Point& pt = r.GetLeftTop();
    pt.Move(100, 200);
    pt.Print();
}
