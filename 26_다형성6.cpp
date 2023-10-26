// 26_다형성6.cpp
#include <iostream>
using namespace std;

class Car {
public:
    virtual void Start() { cout << "Car Start" << endl; }
};

class Sedan : public Car {
public:
    // 모든 Sedan의 자식 클래스는 아래 함수를 사용해야 합니다.
    //  오버라이딩 금지: C++11, final
    void Start() override final { cout << "Sedan Start" << endl; }
};

// 상속 금지: C++11, final
// => 상속을 목적으로 설계되지 않은 클래스는 final 클래스로 만드는 것이 좋습니다.

class Avante final : public Sedan {
public:
    // void Start() override { cout << "Avante Start" << endl; }
};

// class Avente2 : public Avante {
// };

int main()
{
    Car* p = new Sedan;
    p->Start();

    p = new Avante;
    p->Start();

    Sedan* ps = new Avante;
    ps->Start();
}
