// 25_상속2.cpp
#include <iostream>
using namespace std;

// 부모 클래스 / Base / Super
class Animal {
    int age;
    int color;
};

// 자식 클래스 / Derived / Sub

// * C++ 상속
// -> class 자식클래스: public 부모클래스

// => C++에서는 public 상속 / private 상속이라는 개념이 존재합니다.
//    일반적인 객체 지향 설계에서 말하는 상속은 C++의 public 상속만 해당합니다.

class Dog : public Animal {
    int speed;
};

#if 0
class Dog {
    int age;
    int color;
    int speed;
};
#endif

int main()
{
    cout << sizeof(Dog) << endl;
}
