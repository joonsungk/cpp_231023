// 26_다형성4.cpp
#include <iostream>
using namespace std;

// 함수 오버라이딩(Overriding)
// 1. 정의: 부모 클래스가 제공하는 멤버 함수를 자식 클래스가 재정의할 수 있습니다.

// 2. 부모 클래스의 멤버 함수를 자식이 오버라이딩 하였을 때,
//    부모의 포인터/레퍼런스를 통해 호출하였을 경우,
//    자식의 멤버 함수가 호출되지 않는 문제가 발생합니다.
//  - 원인
//    Animal* p = &d;
//    p->Cry();
//     : 어떤 함수를 호출할지 결정하는 것(Binding)
//   1) static binding(정적 바인딩)
//    : 컴파일 시간에 컴파일러가 p의 타입을 보고, 어떤 함수를 호출할지 결정합니다.
//    => 인라인 최적화가 가능합니다.

//   2) dynamic binding(동적 바인딩)
//    : 실행 시간에 객체의 타입을 조사해서, 어떤 함수를 호출하지 결정합니다.

// => 정적 바인딩
// => 반드시 오버라이딩 하는 멤버 함수는 가상 함수로 만들어야 합니다.

class Animal {
public:
    virtual void Cry() const { cout << "Animal Cry" << endl; }
};

class Dog : public Animal {
public:
    virtual void Cry() const { cout << "Dog Cry" << endl; }
};

int main()
{
    Animal a;
    Dog d;

    Animal* pa = &a;
    pa->Cry();

    pa = &d;
    pa->Cry();

    Animal& ra = d;
    ra.Cry();
}

#if 0
int main()
{
    Animal a;
    a.Cry();

    Dog d;
    d.Cry();
}
#endif
