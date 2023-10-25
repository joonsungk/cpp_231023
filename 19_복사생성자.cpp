// 19_복사생성자.cpp
// : 중요합니다!
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 기본 생성자를 제공합니다.

// 2. 사용자가 생성자를 1개라도 제공하면,
//    컴파일러는 기본 생성자를 제공하지 않습니다.

// 3. 사용자가 자신과 동일한 타입을 인자로 전달받는 생성자(복사 생성자)를 제공하지
//    않는다면, 컴파일러는 멤버를 복사하는 복사 생성자를 제공합니다.

class Point {
    int x;
    int y;

public:
    // 복사 생성자
    Point(const Point& rhs)
        : x { rhs.x }
        , y { rhs.y }
    {
        cout << "Point(const Point&)" << endl;
    }

    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Print() { cout << x << ", " << y << endl; }
};

int main()
{
    Point pt { 10, 20 };
    pt.Print();

    Point other { pt }; // Point(const Point&)
    other.Print();

    // 복사 생성자가 호출되는 경우
    Point other1 = pt;
    Point other2(pt);
    Point other3 = { pt };
    Point other4 { pt };
}
