// 2_static3.cpp
#include <iostream>
using namespace std;

// 1. 멤버 함수는 this가 암묵적으로 전달됩니다.
// 2. 정적 멤버 함수는 this가 전달되지 않습니다.

class Sample {
    constexpr static int VERSION = 100; // 상수일때만 초기화를 허용합니다.

    int a = 100;
    static int s;

public:
    // void m1(Sample* this)
    void m1()
    {
        cout << a << endl; // OK!
        //  this->a

        cout << s << endl; // OK!

        m2(); // OK!, this->m2();
        sm1(); // OK!
    }
    void m2() { }

    static void sm1()
    {
        // cout << a << endl; // NO!
        // m1(); // NO!

        cout << s << endl;
        // sm2();
    }

    // 정적 멤버 함수에서 멤버 함수나 멤버 데이터에 접근할 수 없는 이유
    // => this가 전달되지 않기 때문입니다.
    // => this의 역활을 수행하는 인자를 명시적으로 전달하면, 가능합니다.

    static void sm2(Sample* self)
    {
        cout << self->a << endl;
        self->m1();
        self->m2();
    }
};

int Sample::s = 10;

int main()
{
    Sample s;
    Sample::sm2(&s); // !!!!
}
