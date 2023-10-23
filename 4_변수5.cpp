// 4_변수5.cpp
#include <iostream>
using namespace std;

// typedef
// : 변수를 만들듯이 타입의 별칭을 만들 수 있습니다.
typedef int ARR3[3];
typedef int (*PARR3)[3];

int main()
{
    // int x[3] = { 10, 20, 30 };
    // x: int[3]

    ARR3 x = { 10, 20, 30 };
    PARR3 p = &x;
}
