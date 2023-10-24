// 10_캐스팅.cpp
#include <iostream>
using namespace std;

#include <cstdlib> // malloc

// C++에서 명시적인 캐스팅이 필요한 경우가 있습니다.
// 1) Uniform Initialization
// 2) void* -> T*
//   C++은 void*를 구체적인 포인터 타입으로의 암묵적인 변환을 허용하지 않습니다.
// 3) 메모리 재해석
// 4) const T* -> T*
//   : 수정 가능한 메모리에 대해서 타입의 불일치 문제를 해결하기 위해서 사용합니다.

// => C++은 용도와 목적에 따라서 4가지의 캐스팅 연산자를 제공합니다.
//  - static_cast
//   : 가장 기본적인 C++의 캐스팅 연산자 입니다.
//    "연관성 있는 타입 간의 캐스팅에서 사용됩니다."
//     실수 -> 정수
//     큰 표현 범위 정수 -> 작은 표현 범위 정수
//     void* -> T*

//  - reinterpret_cast
//   : 메모리를 재해석하는 목적으로 사용하는 연산자입니다.

//  - const_cast
//  - dynamic_cast

int main()
{
    double d = 3.14;
    // int n1 { (int)d };
    int n1 { static_cast<int>(d) };

    long long ll = 1000000LL;
    // int n2 { (int)ll };
    int n2 { static_cast<int>(ll) };

    // int* p = (int*)malloc(sizeof(int) * 4);
    int* p = static_cast<int*>(malloc(sizeof(int) * 4));

    int x = 0x12345678;
    // unsigned char* px = (unsigned char*)&x;
    // unsigned char* px = static_cast<unsigned char*>(&x); /* Error! */
    unsigned char* px = reinterpret_cast<unsigned char*>(&x);

    // double* pf = reinterpret_cast<double*>(&x);
    // *pf = 3.14; /* 미정의 동작 */

    printf("%x %x %x %x\n", px[0], px[1], px[2], px[3]);

    int data = 42;
    const int* pd = &data;

    // const int* -> int* : 타입의 불일치 문제를 해결하기 위해서
    int* pd2 = (int*)pd;
}

#if 0
int main()
{
    double d = 3.14;
    int n1 { (int)d };

    long long ll = 1000000LL;
    int n2 { (int)ll };

    int* p = (int*)malloc(sizeof(int) * 4);

    int x = 0x12345678;
    unsigned char* px = (unsigned char*)&x;
    printf("%x %x %x %x\n", px[0], px[1], px[2], px[3]);

    int data = 42;
    const int* pd = &data;

    // const int* -> int* : 타입의 불일치 문제를 해결하기 위해서
    int* pd2 = (int*)pd;
}
#endif

// char는 signed인지 unsigned인지 미지정 사항입니다.
// char는 3가지 타입이 존재합니다.
// - char: 문자 타입
// - signed char: 1바이트 부호 있는 정수 타입
// - unsigned char: 1바이트 부호 없는 정수 타입
