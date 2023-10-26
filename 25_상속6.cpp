// 25_상속6.cpp
#include <iostream>
using namespace std;

// protected 생성자
// 의도: 부모 클래스의 객체는 생성하지 않고, 자식 클래스의 객체만 생성하도록 하고 싶다.
//  => 부모 클래스를 추상(abstract) 개념으로 사용하고 싶다.

class Animal {
protected:
    Animal() { }
};

class Dog : public Animal {
public:
    Dog()
        : Animal {}
    {
    }
};

int main()
{
    Animal a;
    Dog d;
}
