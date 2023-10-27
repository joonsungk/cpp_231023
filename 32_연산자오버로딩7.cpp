// 32_연산자오버로딩7.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 기본 생성자를 제공합니다.
// 2. 사용자가 생성자를 1개라도 제공하면,
//    컴파일러는 기본 생성자를 제공하지 않습니다.
// 3. 사용자가 복사 생성자를 제공하지 않으면,
//    컴파일러는 멤버를 복사하는 복사 생성자를 제공합니다.
// 4. 사용자가 대입 연산자를 제공하지 않으면,
//    컴파일러는 멤버를 복사하는 대입 연산자를 제공합니다.

// 핵심: 복사 생성자를 제공하면 대입 연산자를 반드시 함께 제공해야 합니다.
//      이동 생성자를 제공하면 이동 연산자를 반드시 함께 제공해야 합니다.

class Point {
    int x;
    int y;

public:
    Point(const Point& rhs)
        : x { rhs.x }
        , y { rhs.y }
    {
        cout << "Point(const Point& rhs)" << endl;
    }

    Point& operator=(const Point& rhs)
    {
        cout << "operator=(const Point& rhs)" << endl;
        x = rhs.x;
        y = rhs.y;

        return *this;
    }

    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Print() const
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    // a = 10;
    // C: 대입된 값
    // C++: 대입된 lvalue 참조가 결과입니다.

    Point pt1 { 10, 20 };
    Point pt2 = pt1; // 복사 생성자 - 초기화

    pt2 = pt1; // 대입 연산자
}
