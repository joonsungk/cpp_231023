// 7_함수2.cpp
#include <iostream>
using namespace std;

#if 0
int Squarei(int x) { return x * x; }
double Squared(double x) { return x * x; }

int main()
{
    cout << Squarei(10) << endl;
    cout << Squared(3.14) << endl;
}
#endif

// 함수 오버로딩(Overloading, 중복 적재)
// : 함수의 이름이 동일하지만, 함수의 인자 정보(인자의 타입, 개수)가 다를 경우에만 허용됩니다.
// 원리: Name Mangling
//  - 컴파일시 컴파일러가 함수의 이름을 함수의 인자정보를 포함하는 형태로 생성합니다.

// * 정리
//  - 일반적으로 C 프로그램에서 C++ 함수를 호출하거나, C++ 프로그램에서 C 함수를 호출하는 것이
//    불가능하지만, C++에서 제공하는 extern "C"를 이용하면 가능합니다.

// __Z3Squarei
int Square(int x)
{
    return x * x;
}

// __Z3Squared
double Square(double x)
{
    return x * x;
}

int main()
{
    cout << Square(10) << endl;
    cout << Square(3.14) << endl;
}
