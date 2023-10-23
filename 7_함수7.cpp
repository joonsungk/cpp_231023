// 7_함수7.cpp
#include <iostream>
using namespace std;

// 문제점: 반환 타입이 복잡한 경우, 가독성이 떨어집니다.
#if 0
int Add(int a, int b)
{
    return a + b;
}

using PARR3 = int (*)[3];

// int (*foo())[3]
PARR3 foo()
{
    static int x[3] = { 10, 20, 30 };
    return &x; // int (*)[3]
}
#endif

// C++11, 함수를 정의하는 새로운 방법이 도입되었습니다.
//  - Trailing Return Type
//   : 반환 타입을 추론할 수 있습니다.

// auto Add(int a, int b) -> int

auto Add(int a, int b)
{
    return a + b;
}

// auto foo() -> int (*)[3]
auto foo()
{
    static int x[3] = { 10, 20, 30 };
    return &x; // int (*)[3]
}

template <typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

int main()
{
}

// Rust, Go, Swift, Kotlin ...
