// 9_레퍼런스.cpp
#include <iostream>
using namespace std;

// 1. C++에서 레퍼런스 타입이 도입되었습니다.
//  => 기존 메모리에 새로운 이름을 부여합니다.

#if 1
int main()
{
    int n = 100;
    int& r = n;

    n = 42;
    cout << r << endl;

    r = 100;
    cout << n << endl;
}
#endif

// 2. 포인터와 레퍼런스의 차이를 이해해야 합니다.
#if 0
int main()
{
    int n = 100;

    int* p = &n;

    n = 42;
    cout << *p << endl;

    *p = 100;
    cout << n << endl;
}
#endif

// 포인터: 주소를 가지는 변수입니다.
//       포인터의 주소를 통해 메모리에 접근해서, 값을 읽거나 변경할 수 있습니다.
//  참조: 기존 메모리에 새로운 이름을 부여합니다.
//       새롭게 부여된 이름을 통해 메모리에 값을 읽거나 변경할 수 있습니다.

int main()
{
    int n = 100;

    int* p = &n;

    cout << &n << endl;
    cout << &p << endl;

    int& r = n; // r의 타입은 int&
    cout << &n << endl;
    cout << &r << endl;

    // - 레퍼런스는 반드시 초기화가 필요합니다.
    // - 레퍼런스는 널값도 가질 수 없습니다.
    // int& r2;

    int* p2 = NULL;
}
