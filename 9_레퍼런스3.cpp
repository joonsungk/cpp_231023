// 9_레퍼런스3.cpp
// : 우선 개념적으로 정리가 필요합니다.

#include <iostream>
using namespace std;

#if 0
int main()
{
    // constexpr const int n = 10;
    constexpr int n = 10; // n의 타입은? const int

    // int* p1 = &n; /* Error! */
    // int& r1 = n;  /* Error! */
    const int* p1 = &n;
    const int& r1 = n;

    int n2 = 10;
    int* p2 = &n2;
    int& r2 = n2;

    const int* p3 = &n2;
    const int& r3 = n2;
}
#endif

// C++ Reference 종류
// 1. int&
//    : lvalue reference
//  => lvalue만 참조 가능합니다.

// 2. const int&
//    : const lvalue reference
//  => lvalue, rvalue, const lvalue 모두 참조할 수 있습니다.

// 3. C++11, int&&
//    : rvalue reference
//  => rvalue만 참조 가능합니다.

void foo(int& r)
{
    cout << "lvalue reference" << endl;
}

void foo(const int& r)
{
    cout << "const lvalue reference" << endl;
}

void foo(int&& r)
{
    cout << "rvalue reference" << endl;
}

int main()
{
    int n = 10;
    foo(n);
    foo(10);

    //  n: lvalue - 왼쪽에 올 수 있는 것
    // 10: rvalue - 왼쪽에 올 수 없는 것

    int& r1 = n; /* OK, n은 lvalue 입니다. */
    // int& r2 = 10; /* NO, 10은 rvalue 입니다. */

    const int& cr1 = n; /* OK */
    const int& cr2 = 10; /* OK */
}

// Overloading
// 1) 완벽 매칭
//  => 정확한 타입에 먼저 매칭됩니다.
// 2) promotion
//  => 상승 변환
//    int -> long
//    float -> double
// 3) conversion
//  => 타입 변환
