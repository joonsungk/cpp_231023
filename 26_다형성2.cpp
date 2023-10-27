// 26_다형성2.cpp
#include <iostream>
using namespace std;

#if 0
class Dog {
    int age;

public:
    int GetAge() const { return age; }
};

class Cat {
    int age;

public:
    int GetAge() const { return age; }
};

void PrintAge(const Dog& r)
{
    cout << r.GetAge() << endl;
}

void PrintAge(const Cat& r)
{
    cout << r.GetAge() << endl;
}

int main()
{
    Dog d;
    PrintAge(d);

    Cat c;
    PrintAge(c);
}
#endif

#if 0
// Upcasting 활용 1. 동종을 처리하는 함수를 정의할 수 있습니다.

class Animal {
    int age;

public:
    int GetAge() const { return age; }
};

class Dog : public Animal {
};

class Cat : public Animal {
};

void PrintAge(const Animal& r)
{
    cout << r.GetAge() << endl;
}

int main()
{
    Dog d;
    PrintAge(d);

    Cat c;
    PrintAge(c);
}
#endif

#if 0
// Duck Typing
// : 어떤 객체가 오리처럼 꽥꽥거리고 뒤뚱뒤뚱 걷는다면, 오리다.

// => C++은 템플릿을 기반으로 구현할 수 있습니다.


class Dog {
    int age;

public:
    int GetAge() const { return age; }
};

class Cat {
    int age;

public:
    int GetAge() const { return age; }
};

class User {
    int age;

public:
    int GetAge() const { return age; }
};

template <typename TYPE>
void PrintAge(const TYPE& r)
{
    cout << r.GetAge() << endl;
}
// 컴파일 시간 다형성
// => 코드 메모리 사용량이 증가할 수 있지만, 인라인 최적화가 가능합니다.

#if 0
void PrintAge(const Dog& r)
{
    cout << r.GetAge() << endl;
}

void PrintAge(const Cat& r)
{
    cout << r.GetAge() << endl;
}
#endif

int main()
{
    Dog d;
    PrintAge(d);

    Cat c;
    PrintAge(c);
}
#endif
