// 25_상속5.cpp
#include <iostream>
using namespace std;

#if 0
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
#endif

#include <string>

class Animal {
    int age;

public:
    Animal(int n)
        : age { n }
    {
    }
};

// 초기화 순서
//  부모 클래스 생성자 호출 -> 선언된 멤버를 순서대로 초기화

class Dog : public Animal {
    string name;

public:
    Dog(int age, const string& s)
        : Animal { age }
        , name { s }
    {
    }
};

int main()
{
    Dog dog { 42, "Tom" };
}
