// 7_함수3.cpp
#include <iostream>
using namespace std;

// * 함수 오버로딩 주의 사항
// 1. 함수의 인자 정보가 동일하고, 반환 타입만 다를 경우, 오버로딩이 불가능합니다.
// int foo() { }
// void foo() { }

// 2. 파라미터 기본값과 함께 사용할 경우, 모호성 오류가 발생할 수 있습니다.
void foo(int a = 100) { }
void foo() { }

int main()
{
    // foo(); // 컴파일 오류!
}
