// 32_연산자오버로딩2.cpp
#include <iostream>
using namespace std;

#if 0
namespace xstd {
class ostream {
public:
    ostream& operator<<(int n)
    {
        printf("%d", n);
        return *this;
    }

    ostream& operator<<(double d)
    {
        printf("%lf", d);
        return *this;
    }
};

ostream cout;
}

// 1. cout의 정확한 타입은 std::ostream 입니다.
// 2. 연산자 재정의와 함수 오버로딩을 통해 제공되고 있습니다.
int main()
{
    int n = 42;
    xstd::cout << n;
    // xstd::cout.operator<<(n); // operator<<(int)

    double d = 3.14;
    xstd::cout << d;
    // xstd::cout.operator<<(d); // operator<<(double)

    xstd::cout << n << d;
    // cout.operator<<(n).operator<<(d)
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

    friend ostream& operator<<(ostream& os, const Point& pt);
};

// 아래 함수를 통해 사용자 정의 타입을 표준 입출력 객체를 통해 처리할 수 있습니다.
ostream& operator<<(ostream& os, const Point& pt)
{
    os << pt.x << ", " << pt.y;
    return os;
}

int main()
{
    Point pt { 10, 20 };

    cout << pt << endl;
    // cout.operator<<(pt);
    // operator<<(cout, pt).operator<<(endl);

    cout << endl;
}
