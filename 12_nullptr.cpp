// 12_nullptr.cpp
#include <iostream>
using namespace std;

void foo(int n) { cout << "int" << endl; }
void foo(int* p) { cout << "int*" << endl; }

#if 0
int main()
{
    // 정수 0은 포인터 타입으로의 암묵적인 변환이 허용됩니다.
    int* p1 = 0;
    double* p2 = 0;

    // int* p3 = 100; /* Error! */

    // NULL은 정수 타입인지 포인터 타입인지 모호합니다.
    // => 타입 안정성이 없습니다.
    // int* p3 = NULL;

    foo(0);
    foo(NULL);
}
#endif

// C++11, NULL을 대체하는 nullptr이 도입되었습니다.
// => nullptr의 타입은 nullptr_t 타입입니다.
//    포인터 타입으로의 암묵적인 변환을 허용하고, 논리식에서 참/거짓을 판단할 수 있습니다.
#if 0
int main()
{
    foo(0);
    foo(nullptr);
    int* p1 = nullptr;
    double* p2 = nullptr;

    int* p = nullptr;
    if (p) {
        // ...
    }
}
#endif

// C++에서는 참/거짓을 표현하는 기본 타입이 존재합니다.
// => bool
//   true: 참
//  false: 거짓
int main()
{
}
