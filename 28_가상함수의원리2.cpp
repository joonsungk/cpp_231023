// 28_가상함수의원리2.cpp
#include <iostream>
using namespace std;

#if 0
class AAA {
public:
    void foo() { cout << "AAA foo" << endl; } // 1
};

class BBB {
public:
    void goo() { cout << "BBB goo" << endl; } // 2
};

int main()
{
    AAA aaa;
    BBB bbb;

    AAA* p = reinterpret_cast<AAA*>(&bbb);
    p->foo();
    // p의 타입을 기반으로 AAA::foo(p);
}
#endif

class AAA {
public:
    virtual void foo() { cout << "AAA foo" << endl; } // 1
};

class BBB {
public:
    virtual void goo() { cout << "BBB goo" << endl; } // 2
};

int main()
{
    AAA aaa;
    BBB bbb;

    AAA* p = reinterpret_cast<AAA*>(&bbb);
    p->foo();
    // 동적 바인딩
    // (p->vftp[0])(p);
}
