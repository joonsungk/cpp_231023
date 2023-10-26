// 26_다형성4.cpp
#include <iostream>
using namespace std;

// 1. 부모 클래스의 멤버 함수가 가상함수이면, 자식이 재정의한 멤버 함수도 가상함수입니다.

// 2. 문제점
// 1) 부모가 제공하는 멤버 함수가 가상함수일때만, 오버라이딩 해야 합니다.
//   - 부모의 포인터/참조를 통해 해당 기능을 이용할 경우,
//     의도한 함수가 호출되지 않습니다.
// 2) 오버라이딩을 의도했지만, 잘못된 오버라이딩을 한 경우,
//    컴파일 오류가 발생하지 않습니다.

// 3. C++11, override
//  : 자식이 재정의하는 부모의 멤버 함수가 가상 함수가 아니거나
//    존재하지 않는 경우 컴파일 오류가 발생합니다!

class Animal {
public:
    virtual void Hello() const { cout << "Animal Hello" << endl; }
};

class Dog : public Animal {
public:
    // virtual void Hello() const override { cout << "Dog Hello" << endl; } // 1
    void Hello() const override { cout << "Dog Hello" << endl; } // 2
};

int main()
{
    Animal a;
    Dog d;

    Animal* pa = &a;
    pa->Hello();

    pa = &d;
    pa->Hello();

    Animal& ra = d;
    ra.Hello();
}
