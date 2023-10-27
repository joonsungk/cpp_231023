// 33_STL2.cpp
#include <iostream>
using namespace std;

// 컨테이너 요소
// 2) 반복자(Iterator)
//  : 배열에서 포인터의 역활과 유사합니다.

int main()
{
    //           p1                p2
    //            |                 |
    int x[5] = { 10, 20, 30, 40, 50 };

    int* p1 = x; // &x[0]
    int* p2 = x + 5; // 마지막 요소 다음 위치(Past the end)
    // 표준에서 유효한 개념

    // C++은 반개 구간을 사용합니다.
    // : [begin, end)

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
