// 7_함수4.cpp
#include <iostream>
using namespace std;

// 인라인 함수
// => 함수를 호출하지 않고, 함수의 구현으로 호출부를 기계어 치환합니다.
// => 인라인 최적화는 컴파일러 최적화 명령입니다.
//    MSVC: /Ob1

inline int Square(int x);

int Square(int x)
{
    return x * x;
}

int main()
{
    int x = 10;

    int result = Square(x);
    /*
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
        mov     DWORD PTR result$[rsp], eax
    */

    result = x * x;
    /*
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
        mov     DWORD PTR result$[rsp], eax
    */
}
