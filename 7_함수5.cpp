// 7_함수5.cpp
#include <iostream>
using namespace std;

#if 0
int Square(int x) { return x * x; }
double Square(double x) { return x * x; }
long long Square(long long x) { return x * x; }
#endif
// 함수의 인자와 반환 타입만 다르고, 함수의 구현(알고리즘)은 동일합니다.
// => 코드를 컴파일 시간에 생성할 수 있는 템플릿을 사용하면 좋습니다.

// 함수 템플릿
template <typename TYPE>
TYPE Square(TYPE x) { return x * x; }

int main()
{
    cout << Square(10) << endl;
    // TYPE -> int

    cout << Square(3.14) << endl;
    // TYPE -> double

    cout << Square(100000000LL) << endl;
    // TYPE -> long long
}
