// 32_연산자오버로딩.cpp
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
