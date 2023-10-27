// 32_연산자오버로딩5.cpp
#include <iostream>
using namespace std;

// 정수의 역활을 수행하는 클래스 타입입니다.
class Integer {
    int value;

public:
    Integer(int n = 0)
        : value { n }
    {
    }

    Integer& operator++()
    {
        ++value;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Integer& i);
};

ostream& operator<<(ostream& os, const Integer& i)
{
    return os << i.value;
}

// ++n;
//   C: 증가된 n의 값
// C++: 증가된 n의 참조

int main()
{
    Integer v = 42;
    ++ ++ ++v;
    // v.operator++();

    cout << v << endl;

    int n = 42;
    ++ ++ ++n;

    cout << n << endl;
}
