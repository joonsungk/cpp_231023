// 16_소멸자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 소멸자를 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 소멸자를 제공합니다.
//    ~Person() {}
#if 0
class Person {
};

int main()
{
    Person p; // Person()
} // ~Person()
#endif

// 2. 클래스 내부에서 자원(메모리, 파일)을 할당한 경우,
//    소멸자를 통해 객체가 파괴되기 전에 자원을 해지해야 합니다.
class Person {
    char* name;

public:
    Person(const char* s)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~Person()
    {
        delete[] name;
    }

    void Print()
    {
        cout << name << endl;
    }
};

int main()
{
    Person person { "Tom" };
    person.Print();
}
