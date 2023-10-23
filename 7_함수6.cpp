// 7_함수6.cpp
#include <iostream>
using namespace std;

// 오직 정수 타입에 대해서만 동작하도록 만들고 싶습니다.
// 실수 타입에 대해서는 사용을 금지하고 싶습니다.
int Square(int x) { return x * x; }

// C++에서 함수를 금지하는 방법
// 1) 함수의 구현을 제공하지 않고, 선언만 제공합니다.
//  => 링크 오류를 발생시킵니다.
//   문제점
//   - 문제의 원인을 파악하기 어렵습니다.
//   - 의도를 전달하기 어렵습니다.
/*
ld: Undefined symbols:
  Square(double), referenced from:
      _main in 7_함수6-918cfb.o
*/
// 2) C++11, Delete function
/*
7_함수6.cpp:26:13: error: call to deleted function 'Square'
    cout << Square(3.14) << endl;
*/
double Square(double x) = delete;

int main()
{
    cout << Square(10) << endl;
    // cout << Square(3.14) << endl;
}
