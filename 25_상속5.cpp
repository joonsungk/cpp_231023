// 25_상속5.cpp
#include <iostream>
using namespace std;

class Animal {
    int age;

public:
    Animal(int n)
        : age { n }
    {
    }
};

// 초기화리스트를 반드시 정의해야 하는 경우
// 1) const 멤버
// 2) reference 멤버
// 3) 기본 생성자를 제공하지 않는 멤버
// 4) 기본 생성자를 제공하지 않는 부모

class Dog : public Animal {
public:
    // Dog() : Animal{} {}

    Dog()
        : Animal { 42 }
    {
    }
};

int main()
{
    Dog d;
}
