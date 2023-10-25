// 18_초기화리스트4.cpp
#include <iostream>
using namespace std;

// C++에서 멤버 데이터를 초기화하는 2가지 방법
// - 필드 초기화, C++11
// - 초기화 리스트

class Point {
    // 1) C++11, 필드 초기화
    // => 초기화를 수행하지 않을 경우, 기본값을 지정할 수 있습니다.
    int x = 100;
    int y = 42;

public:
    Point()
    {
        // x = 10; /* 대입 */
        // y = 20; /* 대입 */
    }

    Point(int a, int b)
        // 2) 초기화 리스트
        : x { a }
        , y { b }
    {
    }

    void Print() { cout << x << ", " << y << endl; }
};

int main()
{
    Point pt2;
    pt2.Print();

    Point pt { 50, 60 };
    pt.Print();
}
