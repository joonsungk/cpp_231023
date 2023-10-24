// 1_시작.cpp

// 1. 확장자
// -   C: .c
// - C++: .cpp .cc .cxx ...

// 2. 컴파일러
// - MSVC: Microsoft Visual C/C++ Compiler
// - GCC
// - LLVM

// 3. C++ 표준
// 1998년: C++ 1차 표준안, C++98
// 2003년: C++03
// 2011년: C++11, C++ 2차 표준안 - Modern C++
// 2014년: C++14
// 2017년: C++17, C++ 3차 표준안 - *
// 2020년: C++20
// 2023년: C++23

// 4. C++은 C의 문법을 지원합니다.
// - C의 표준과 C++안에서의 C의 표준은 다릅니다.

// Compile: Ctrl + F7
// Compile + Linking + Run: Ctrl + F5

#include <stdio.h>

void foo(void) { }
void goo() { }

int main()
{
    // goo(10);
    // foo(10);

    printf("Hello, C\n");
    // return 0;
    // 컴파일러가 자동으로 return 0;를 처리합니다.
}
