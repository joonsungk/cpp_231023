// 33_STL.cpp
#include <iostream>
using namespace std;

// STL(Standard Template Library)
// 1979년: C++ 탄생
// 1998년: C++ 1차 표준안, STL

// * STL 구성 요소
// 1) 컨테이너: 자료 구조
//  - vector, list, deque
//    stack, queue, ..
//    map, set

// 2) 컨테이너 특징
//  - 템플릿 기반 입니다.
//  => 타입에 상관없이 다양한 자료구조를 활용할 수 있습니다.

//  - 멤버 함수의 이름이 유사합니다.
//  => 자료 구조의 전환을 쉽게 수행할 수 있습니다.

//     |-----------------------|
// push_front       |       push_back
//  pop_front       |        pop_back
//    front         |         back
//            insert/remove

//  - 데이터를 참조하는 연산과 제거하는 연산이 분리되어 있습니다.
//  => 값을 반환하는 것이 아니라, 참조를 반환하기 위해서
//     반환용 임시 객체의 복사 생성/제거 비용을 제거하기 위해서

#include <vector>
#include <list>
#include <deque>

#if 0
int main()
{
    // vector<int> v = { 10, 20, 30 };
    // list<int> v = { 10, 20, 30 };
    deque<int> v = { 10, 20, 30 };

    // list<int> l;

    v.push_back(100);
    v.push_back(200);
    v.push_back(300);

    cout << v.back() << endl;
    v.pop_back();

    for (auto e : v) {
        cout << e << endl;
    }
}
#endif

// - 자료 구조의 형태에 따라서 지원되는 연산이 다를 수 있습니다.
// => vector는 연속된 메모리를 사용하기 때문에
//    임의 접근 연산을 제공하지만, list는 제공하지 않습니다.

// => vector는 데이터를 앞에 삽입하는 기능을 제공하지 않습니다.
//    push_front가 없습니다.

int main()
{
    list<int> v = { 10, 20, 30, 40 };
    v.push_front(100);

    // list<int> v = { 10, 20, 30, 40 };
    //  : list는 아래 연산을 제공하지 않습니다.
    // cout << v[2] << endl;

    for (auto e : v) {
        cout << e << endl;
    }
}
