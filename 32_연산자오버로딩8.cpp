// 32_연산자오버로딩8.cpp
#include <iostream>
using namespace std;

// 함수 호출 연산자를 재정의할 수 있습니다.
class Func {
    int base;

public:
    Func(int b = 0)
        : base { b }
    {
    }

    // 반환 타입과 인자 정보를 자유롭게 만들 수 있습니다.
    int operator()(int a, int b) const
    {
        return base + a + b;
    }

    int operator()(int a, int b, int c) const
    {
        return base + a + b + c;
    }
};

int main()
{
    // 상태를 가질 수 있습니다.
    Func f(100); // 함수 객체(Functor)

    int result = f(10, 20, 30);
    //           f.operator()(10, 20)
    cout << result << endl;
}
