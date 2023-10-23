// 7_함수.cpp
#include <iostream>
using namespace std;

// 미지정 동작(Unspecified Behavior)
// : C/C++에서 컴파일러가 인자를 전달할 때, 뒤에서부터 전달할지, 앞에서부터 전달할지
//  미지정되어 있습니다.
//  => 컴파일러마다 다릅니다.

// Default Parameter(파라미터 기본값)
// 정의: 전달되지 않은 함수의 인자를 파라미터 기본값으로 컴파일러가
//      자동으로 처리합니다.

// 주의 사항 2가지
// 1) 반드시 마지막 파라미터부터 기본값을 지정할 수 있습니다.
// 2) 함수가 선언과 정의로 분리하는 경우,
//    선언부에만 작성해야 합니다.

// Add.h
int Add(int a, int b, int c = 0, int d = 0); // 선언, 헤더파일

int main()
{
    std::cout << Add(10, 20, 30, 40) << std::endl;
    // std::cout << Add(10, 20, 30, 0) << std::endl;
    std::cout << Add(10, 20, 30) << std::endl;

    // std::cout << Add(10, 20, 0, 0) << std::endl;
    std::cout << Add(10, 20) << std::endl;
}

// Add.cpp
int Add(int a, int b, int c /* =0 */, int d /* =0 */) // 정의
{
    return a + b + c + d;
}
