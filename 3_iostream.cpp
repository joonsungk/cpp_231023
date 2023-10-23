// 3_iostream.cpp
#include <iostream>
using namespace std;

int main()
{
    // int n = 0xFAFA;
    // 1111 1010 1111 1010
    long long x = 10'000'000'000'000;

    // C++11, 2진수 상수를 표현하는 기능이 추가되었습니다.
    // 상수에 단일 따옴표를 이용해서 가독성을 높일 수 있습니다.
    int n = 0b1111'1010'1111'1010;

    printf("%x\n", n);
    printf("%X\n", n);

    // IO 조정자(Manipulator)
    // : hex, uppercase
    cout << hex << n << endl;
    cout << hex << uppercase << n << endl;
}
