// 2_namespace3.cpp
// #include <stdio.h>
#include <cstdio>
// C++은 C의 헤더를 위의 형태로 제공하고 있습니다.
//  stdio.h  -> cstdio
// stdlib.h  -> cstdlib
// string.h  -> cstring

int main()
{
    // C++은 C의 모든 표준 라이브러리 함수를 std의 이름 공간을 통해
    // 사용할 수 있습니다.
    std::printf("Hello, C\n");
}
