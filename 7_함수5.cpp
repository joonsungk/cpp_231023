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
// => 적은 코드로 다양한 타입에서 동작하는 함수를 정의할 수 있습니다.
//    전달된 인자의 타입에 따른 코드 메모리 사용량이 존재합니다.
// => 인라인 최적화가 가능한 경우, 코드 메모리 사용량을 최적화할 수 있습니다.

#if 0
template <typename TYPE>
inline TYPE Square(TYPE x) { return x * x; }

int main()
{
    // 인자의 타입을 통해 TYPE을 결정합니다.
    // => 암묵적인 타입 추론
    cout << Square(10) << endl;
    // TYPE -> int

    cout << Square(3.14) << endl;
    // TYPE -> double

    cout << Square(100000000LL) << endl;
    // TYPE -> long long

    // 명시적으로 타입을 지정할 수 있습니다.
    cout << Square<double>(10.0F) << endl;
}
#endif

template <typename T1, typename T2> // 타입 파라미터
void foo(T1 a, T2 b) // 값 파라미터
{
    // T1 temp = a;
    // auto temp = a;
    decltype(a) temp;
}

// C++ 표준 라이브러리: STL(Standard Template Library)
int main()
{
    foo(10, 3.14);
    // foo<int, double>(10, 3.14);
    //    |-----------||--------|
    //      타입 인자       값 인자
}
