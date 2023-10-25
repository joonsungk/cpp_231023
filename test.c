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

#if 0
#include <stdlib.h>

int main()
{
    int* p = malloc(sizeof(int) * 4);
    // C에서는 void*를 구체적인 포인터타입으로의 암묵적인 변환을 허용합니다.
}
#endif

#if 0
// C99 표준으로 _Bool 타입이 도입되었습니다.
#include <stdbool.h>

int main()
{
    _Bool b = 0;
    bool b2 = true;
}
#endif

#if 0
struct Data { }; // C 표준에서는 허용 X

int main()
{
}
#endif

// 아래 구조체가 크다고 가정합니다.
struct Point {
    int x;
    int y;
};

#if 0
struct Point Add(struct Point a, struct Point b)
{
    struct Point result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}
#endif

struct Point* Add(struct Point a, struct Point b)
{
    // static struct Point result; // 정적 메모리 => 함수가 재진입이 불가능합니다.

    struct Point* result = malloc(sizeof(struct Point));
    result->x = a.x + b.x;
    result->y = a.y + b.y;

    return result;
}

void Add(const struct Point* a, const struct Point* b, struct Point* result) // Out parameter
{
    result->x = a->x + b->x;
    result->y = a->y + b->y;
}

int main(void)
{
    struct Point pt1 = { 10, 20 };
    struct Point pt2 = { 30, 40 };
}
