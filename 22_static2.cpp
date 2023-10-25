// 22_static2.cpp
#include <iostream>
using namespace std;

// 멤버 데이터: 객체의 상태
//  멤버 함수: 객체의 행위

// 정적 멤버 데이터: 클래스의 상태 / class property
//  정적 멤버 함수: 클래스의 행위 / class method

class Car {
    static int cnt;

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    // 멤버 함수는 객체가 생성되어야 호출이 가능합니다.
    int GetCount() { return cnt; }

    // 객체를 생성하지 않고, 호출 가능한 멤버 함수가 있습니다.
    // => 정적 멤버 함수
    //  : this가 전달되지 않습니다.
    // "일반함수와 동일한데, 접근 제어를 사용할 수 있는 함수입니다."
    static int GetCount2() { return cnt; }
};

int Car::cnt = 0;

int main()
{
    // 정적 멤버 함수를 호출하는 방법 2가지
    // 1) 클래스::
    cout << Car::GetCount2() << endl;
    // 2) 객체.

    Car car;
    cout << car.GetCount() << endl;
    cout << car.GetCount2() << endl;
}
