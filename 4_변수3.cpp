// 4_변수3.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    // int a;
    // a의 타입은? int

    // int* p;
    // p의 타입은? int*

    int x[3] = { 10, 20, 30 };
    // x의 타입은? int[3]

    int* p = x; // p = &x[0]
    // p ----> int

    // 배열의 이름은 배열의 첫번째 원소의 주소로 해석됩니다. => Decay
    // - Decay 예외
    //  1) sizeof
    cout << sizeof(x) << endl;

    //  2) &(주소 연산자)
    int(*p2)[3] = &x;
    // p2 -------> int[3]
}
#endif

// auto(Type deduction, C++11)
// 1) 컴파일 시간에 변수의 타입을 우항의 타입을 기반으로 결정합니다.
// 2) 의존성 있는 타입을 표현할 때,
//    변수의 타입이 변경되어도 코드를 수정할 필요가 없습니다.

// 3) auto는 주의해서 사용해야 합니다.
// 4) C 언어의 auto 키워드를 다른 의미로 사용합니다.

#if 0
int main()
{
    long long x[3] = { 10, 20, 30 };

    // long long* p = x;
    // long long(*p2)[3] = &x;

    auto p = x;
    auto p2 = &x;

    // auto a;
    // 컴파일 오류가 발생합니다.
    // 반드시 우항이 필요합니다.
}
#endif

int main()
{
    const int n = 100;
    // n: const int

    // const가 따라가지 않습니다.
    // auto x = n;
    // x = 100;

    const auto x = n;
    // x = 100;
}
