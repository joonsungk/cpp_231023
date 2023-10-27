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

// 규칙
// 1) 연산자 우선순위는 변하지 않습니다.
// 2) 피연산자 개수도 변하지 않습니다.
//   a + b
//   -> a.operator+(b)
//      operator+(a, b)

// 3) 새로운 연산자를 정의할 수 없습니다.
// 4) 연산자 오버로딩이 허용되지 않는 연산자도 있습니다.
//    - ::(범위 연산자)
//    - . (a.foo(), 접근 연산자)
//    - ?:(3항 연산자)

// 5) 반드시 피연산자 중에 한개는 사용자 정의 타입이어야 합니다.
// 6) 연산자 중에 반드시 멤버 함수를 통해서만 허용하는 경우가 있습니다.
//  => 클래스의 제작자만 제공할 수 있습니다.
//  1) 대입 연산자
//    a = b;
//  2) 호출 연산자
//    a(), a(10), a(10, 20);
//  3) 임의 접근 연산자
//    v[0] = 10;
//  4) 객체 포인터 접근 연산자
//    v->foo()
//  5) 포인터 역참조 연산자
//    *a;

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
