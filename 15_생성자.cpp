// 15_생성자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 인자 없는 생성자를 제공합니다.
#if 0
class Point {
    int x;
    int y;

    // public:
    //     Point() {} // 인자 없는 생성자 - Default Constructor(기본 생성자)
};

int main()
{
    Point pt; // -> Point()
}
#endif

// 2. 사용자가 생성자를 1개라도 제공하면,
//    컴파일러는 기본 생성자를 제공하지 않습니다.

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    Point pt { 10, 20 }; // -> Point(int, int)

    // Point pt2; // Error!
}
