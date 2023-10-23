// test.c
#if 0
int main(void)
{
    auto int a; // 자동 변수
}
#endif

#if 0
#include <stdio.h>

int main(void)
{
    const int c;
}
#endif

#if 0
int main(void)
{
    const char* s = "hello";
    // s[0] = 'x'; /* 미정의 동작 */
}
#endif

// void foo(void) { }
void foo(int a, int b) { }
// 0000000100003f90 T _foo

int main(void)
{
}
