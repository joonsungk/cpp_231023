// 18_초기화리스트3.cpp
#include <iostream>
using namespace std;

// 멤버 데이터를 만들 때, 다른 이름 규칙을 사용합니다.
// 1) member_ -> *
// 2) m_member
// 3) mMember
// 4) _member => 권장 X, 표준 라이브러리의 이름 규칙입니다.
//    C언어도 심볼의 이름이 언더스코어로 시작하는 형태로 만드는 것은 위반입니다.
//   #ifndef CALC_H_

class Point {
    int x_;
    int y_;

public:
    Point(int x, int y)
        : x_ { x }
        , y_ { y }
    {
    }
    // Point() { cout << "Point()" << endl; }

    void SetX(int x)
    {
        x_ = x;
    }

    void Print() { cout << x_ << ", " << y_ << endl; }
};

// * 초기화리스트를 반드시 정의해야 하는 경우
// 1) const 멤버
// 2) reference 멤버
// 3) 기본 생성자를 제공하지 않는 객체 멤버

class Rect {
    Point leftTop;

public:
    // Rect() : leftTop{}
    // {}
    Rect()
        // : leftTop(10, 20)
        : leftTop { 10, 20 } // !!!
    {
    }

    Rect(int x, int y)
        : leftTop { x, y }
    {
    }
};

int main()
{
    Rect r;
}
