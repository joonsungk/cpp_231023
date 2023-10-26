// 25_상속4.cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base()" << endl; } // (3)
    ~Base() { cout << "~Base()" << endl; } // <4>
};

class Derived : public Base {
public:
    // 자식 클래스의 생성자의 초기화리스트에서 부모의 기본 생성자를 호출하는 코드를
    // 컴파일러가 자동으로 처리합니다.
    Derived()
    // : Base() - Base::Base() - (2)
    {
        cout << "Derived()" << endl; // (4)
    }

    ~Derived()
    {
        cout << "~Derived()" << endl; // <2>

    } // Base::~Base() - <3>
    // 자식 클래스의 소멸자의 마지막에 부모의 소멸자를 호출하는 코드를
    // 컴파일러가 자동으로 처리합니다.
};

int main()
{
    Derived d;
    // Derived::Derived(); - (1)

} // Derived::~Derived() - <1>
