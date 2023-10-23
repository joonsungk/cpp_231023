// 9_레퍼런스.cpp
#include <iostream>
using namespace std;

// 1. C++에서 레퍼런스 타입이 도입되었습니다.
//  => 기존 메모리에 새로운 이름을 부여합니다.

#if 0
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
int main()
{
    int n = 100;

    int* p = &n;

    n = 42;
    cout << *p << endl;

    *p = 100;
    cout << n << endl;
}
