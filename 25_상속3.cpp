// 25_상속3.cpp
#include <iostream>
using namespace std;

// 1. 부모 클래스의 private은 자식 클래스를 통해서 접근이 불가능합니다.

// 2. protected
//  : 외부에서 접근이 불가능하고, 자식 클래스는 접근이 가능합니다.

// 3. C++ 접근 지정자
//  1) private: 외부 접근 불가능, 자식 클래스 접근 불가능, friend 함수/클래스 가능
//  2) protected: 외부 접근 불가능, 자식 클래스 접근 가능
//  3) public: 외부 접근 가능

class Animal {
protected:
    int age = 42;
};

class Dog : public Animal {
public:
    void Print() const
    {
        cout << age << endl;
    }
};

int main()
{
    Dog d;
    d.Print();
}
