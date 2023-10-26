// 26_다형성.cpp
#include <iostream>
using namespace std;

class Animal {
};

class Dog : public Animal { };

// class Dog { };

int main()
{
    Animal a;
    Dog d;

    Animal* p1 = &a;
    Animal& r1 = a;

    // - 부모 타입의 포인터/참조 타입으로 자식 객체를 참조할 수 있습니다.
    // - 자식의 포인터/참조 타입은 부모 포인터/참조 타입으로의 암묵적인 변환을 허용합니다.
    // => Upcasting
    Animal* p2 = &d;
    Animal& r2 = d;

    // * Downcasting은 암묵적인 변환이 허용되지 않습니다.
    // Dog* p = &a; /* Error! */
    // Dog& r = a; /* Error! */
}
