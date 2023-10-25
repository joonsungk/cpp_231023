// 22_static.cpp
#include <iostream>
using namespace std;

#if 0
int cnt = 0;

class Car {

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }
};

int main()
{
    cout << cnt << endl;

    Car car;
    cout << cnt << endl;

    cnt = 0;

    Car cars[5];
    cout << cnt << endl;
}
#endif

// 정적 멤버 데이터
// 1) 클래스의 접근 제어를 사용할 수 있는 전역 변수입니다.
// 2) 정적 멤버 데이터는 반드시 선언과 정의가 분리되어야 합니다.

// 헤더 코드
#if 0
class Car {
public:
    static int cnt; // 정적 멤버 데이터 선언

    Car() { ++cnt; }
    ~Car() { --cnt; }
};

// 소스 코드
int Car::cnt = 0; // 정적 멤버 데이터 정의

int main()
{
    // 정적 멤버 데이터에 접근하는 방법
    // 1) 클래스
    //  - 클래스::정적멤버데이터
    // 2) 객체
    //  - 객체.정적멤버데이터

    cout << Car::cnt << endl;

    Car cars[5];

    Car car;
    cout << Car::cnt << endl;
    cout << car.cnt << endl;
}
#endif

class Car {
    int age; // 4
    int speed; // 4
    double height; // 8

    static int cnt;
};

int Car::cnt = 0;

int main()
{
    cout << sizeof(Car) << endl;
}
