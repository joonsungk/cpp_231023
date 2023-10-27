// 32_연산자오버로딩.cpp
#include <iostream>
using namespace std;

#if 0
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

    Point Add(const Point& rhs) const
    {
        Point result { x + rhs.x, y + rhs.y };
        return result;
    }

    friend Point Add(const Point& lhs, const Point& rhs);
};

Point Add(const Point& lhs, const Point& rhs)
{
    Point result { lhs.x + rhs.x, lhs.y + rhs.y };
    return result;
}

int main()
{
    Point pt1 { 10, 20 };
    Point pt2 { 100, 200 };

    // Point 객체간의 덧셈 연산을 제공하고 싶습니다.
    //  pt1 + pt2
    // 1) 일반 함수
    Point result = Add(pt1, pt2);

    // 2) 멤버 함수
    // Point result = pt1.Add(pt2); // Point::Add(&pt1, pt2);
    result.Print();
}
#endif

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

    // Point operator+(const Point& rhs) const
    // {
    //     Point result { x + rhs.x, y + rhs.y };
    //     return result;
    // }

    friend Point operator+(const Point& lhs, const Point& rhs);
};

Point operator+(const Point& lhs, const Point& rhs)
{
    Point result { lhs.x + rhs.x, lhs.y + rhs.y };
    return result;
}

// 연산자 오버로딩
// 정의: 객체를 대상으로 연산자를 사용하였을 경우,
//      약속된 멤버 함수 또는 일반 함수가 호출됩니다.

int main()
{
    Point pt1 { 10, 20 };
    Point pt2 { 100, 200 };

    // Point 객체간의 덧셈 연산을 제공하고 싶습니다.
    //  pt1 + pt2
    Point result = pt1 + pt2;
    // 1) 멤버 함수
    // Point result = pt1.operator+(pt2);

    // 2) 일반 함수
    // Point result = operator+(pt1, pt2);

    result.Print();
}
