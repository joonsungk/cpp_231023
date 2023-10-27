// 33_STL2.cpp
#include <iostream>
using namespace std;

// 컨테이너 요소
// 2) 반복자(Iterator)
//  : 배열에서 포인터의 역활과 유사합니다.
//  => 컨테이너(컬렉션)의 요소를 순회하는 객체

#if 0
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
#endif

#include <vector>
#include <list>

// begin: 컨테이너의 시작 위치를 가르키는 반복자
//   end: 컨테이너의 마지막 요소 다음 위치를 가르키는 반복자
int main()
{
    //             p1                p2
    //              |                 |
    // int x[5] = { 10, 20, 30, 40, 50 };
    vector<int> x = { 10, 20, 30, 40, 50 };
    // list<int> x = { 10, 20, 30, 40, 50 };

    // 멤버 함수를 통해 반복자를 꺼내면,
    // 일반 배열은 사용이 불가능합니다.
    // auto p1 = x.begin();
    // auto p2 = x.end();

    // vector<int>::iterator p1 = begin(x);
    auto p1 = begin(x);
    auto p2 = end(x);

    // C++은 반개 구간을 사용합니다.
    // : [begin, end)

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
