// 26_다형성7.cpp
#include <iostream>
using namespace std;

// 가상 소멸자
// 1. 부모의 포인터를 통해 자식 객체를 delete 할때,
//    소멸자도 정적 바인딩을 하기 때문에, 자식의 소멸자가 제대로 호출되지 않는 문제가 발생합니다.
// 2. 반드시 부모 클래스의 소멸자는 가상 소멸자로 제공해야 합니다.
// 3. 부모가 제공하는 소멸자가 가상 함수이면, 자식의 소멸자는 자동으로 가상 함수가 됩니다.

class Animal {
public:
    Animal() { cout << "Animal()" << endl; }

    virtual ~Animal() { cout << "~Animal()" << endl; }
};

class Dog : public Animal {
public:
    Dog()
        : Animal {}
    {
        cout << "Dog()" << endl;
    }

    // 자식의 소멸자에 override를 통해, 부모의 소멸자가 가상이 아닌 경우,
    // 컴파일 오류가 발생합니다.
    ~Dog() override
    {
        cout << "~Dog()" << endl;

        // ~Animal();
    }
};

int main()
{
    Animal* p = new Dog;

    delete p;
    // Animal::~Animal()

    // Dog d;
}
