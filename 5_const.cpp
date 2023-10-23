// 5_const.cpp
#include <iostream>
using namespace std;

// 1. C++에서는 반드시 상수는 초기화를 수행해야 합니다.

// 2. 상수 표현식
//  : 컴파일러가 미리 계산을 수행할 수 있으면, 컴파일 시간에 계산을 수행해서
//    기계어를 생성합니다.

// 3. C++에서 const 상수는 초기값이 컴파일 시간에 결정된다면,
//    컴파일러는 상수 표현식으로 취급합니다.

// 4. C++11, 상수 표현식에 사용할 수 있는 키워드입니다.
//  => constexpr

int main()
{
    // constexpr const int c = 100; // 컴파일 시간 상수
    constexpr int c = 100;
    printf("%d\n", c);

    int x = 100;
    const int c2 = x; // 실행 시간 상수
    printf("%d\n", c2);
}
