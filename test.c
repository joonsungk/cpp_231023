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

#if 0
// void foo(void) { }
void foo(int a, int b) { }
// 0000000100003f90 T _foo

int main(void)
{
}
#endif

#if 0
// GCC, Clang => VLA
int main(void)
{
    int c = 10;

    int arr[c];
}
#endif

#include <stdlib.h>

int main()
{
    int* p = malloc(sizeof(int) * 4);
    // C에서는 void*를 구체적인 포인터타입으로의 암묵적인 변환을 허용합니다.
}
