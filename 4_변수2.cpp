// 4_변수2.cpp
// 중요합니다.

struct Point {
    int x;
    int y;
};

#if 0
int main()
{
    // Copy Initialization
    int n1 = 42;
    int x1[3] = { 10, 20, 30 };
    Point pt1 = { 10, 20 };

    // Direct Initialization
    int n2(42);
    int x2[3] { 10, 20, 30 };
    Point pt2 { 10, 20 };
}
#endif

// C++11, Uniform Initialization(일관된 초기화)
#if 0
int main()
{
    // Copy Initialization
    int n1 = { 42 };

    int x1[3] = { 10, 20, 30 };
    Point pt1 = { 10, 20 };

    // Direct Initialization
    int n2 { 42 };

    int x2[3] { 10, 20, 30 };
    Point pt2 { 10, 20 };
}
#endif

// C/C++
// => 암묵적인 변환으로 인해 오류가 발생할 수 있습니다.
// => Uniform Initialization
//   : Preventing Narrow
//   - 실수 타입이 정수 타입으로의 암묵적인 변환,
//     더 넓은 표현 범위의 정수가 더 적은 표현 범위의 정수로의 암묵적인 변환
//     허용하지 않습니다.
//  => 반드시 명시적인 변환을 사용해야 합니다.

#include <climits> // limits.h

int main()
{
    double d1 = 3.14;
    double d2 = 4.5;
    int x2[2] = { (int)d1, (int)d2 };

    double d = 3.14;
    if (d > INT_MAX || d < INT_MIN) {
        // ...
    } else {
        int n1 = { (int)d };
    }

    long long x = 10000000000000LL;
    if (x > INT_MAX || x < INT_MIN) {

    } else {
        int n2 { (int)x };
    }
}
