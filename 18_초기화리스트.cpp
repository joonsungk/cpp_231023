// 18_초기화리스트.cpp
#include <iostream>
using namespace std;

// 1. 초기화와 대입의 차이점을 이해해야 합니다.
// => 초기화: 변수를 메모리에 할당하면서, 초기값을 지정하는 행위
//     대입: 이미 할당된 메모리의 값을 변경하는 행위

// 2. C++에서 반드시 초기화가 필요한 경우
//  1) reference
//  2) const

#if 0
int main()
{
    int n;
    n = 10; // 대입

    int x = 10; // 초기화
}
#endif

// 3. 생성자에서 멤버 데이터를 초기화하기 위해서는
//    "초기화 리스트" 문법을 이용해야 합니다.
//  -> 초기화리스트는 생성자에서만 사용이 가능합니다.

// 4. 초기화리스트를 반드시 사용해야 하는 경우
//  1) const 멤버
//  2) reference 멤버

class Sample {
    const int x;
    const int y;
    int& r;

public:
    Sample(int a, int b, int& rn)
        : x { a }
        , y { b }
        , r { rn }
    {
    }

#if 0
    Sample(int a, int b)
        : x(a)
        , y(b)
    {
    }
#endif

#if 0
    Sample(int a, int b)
    {
        x = a; // 대입입니다.
        y = b;
    }
#endif
};

int main()
{
    int n = 100;
    Sample s(10, 20, n);
}
