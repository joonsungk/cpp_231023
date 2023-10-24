// 7_함수4.cpp
#include <iostream>
using namespace std;

// 인라인 함수
// => 함수를 호출하지 않고, 함수의 구현으로 호출부를 기계어 치환합니다.
// => 인라인 최적화는 컴파일러 최적화 명령입니다.
//    MSVC: /Ob1
// 1) 인라인 최적화를 통해서 더이상 호출되지 않는 함수는
//    코드 메모리에서 제거됩니다.
// 2) 인라인 최적화는 코드 메모리 사용량을 증가시킬 수 있습니다.
//    때문에, 간결한 함수에서 사용하는 것이 좋습니다.
// 3) 인라인 함수라고 하더라도, 인라인 최적화 여부를 컴파일러가 판단합니다.

// C99 표준에서도 인라인 함수가 도입되었습니다.
//  C: static inline Square(int x) { return x * x; }

// 4) 인라인 함수는 다른 파일에서 접근할 수 없는 내부 연결(Internal linkage)을 갖습니다.
//    범용적으로 사용되어야 하는 인라인 함수는 반드시 헤더를 통해 구현이 제공되어야 합니다.

// => 기존에 매크로 함수를 함수 호출의 오버헤드를 제거하기 위한 목적으로 사용하였다면,
//    인라인 함수를 사용하는 것이 좋습니다.

inline int Square(int x);

int Square(int x)
{
    return x * x;
}

int main()
{
    int x = 10;

    int result = Square(x);
    // 인라인 최적화 X
    /*
        mov     ecx, DWORD PTR x$[rsp]
        call    int Square(int)               ; Square
        mov     DWORD PTR result$[rsp], eax
    */

    // 인라인 최적화 O
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
