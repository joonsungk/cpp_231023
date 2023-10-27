// 32_연산자오버로딩4.cpp
#include <iostream>
using namespace std;

// 1. endl은 함수 입니다.
#if 0
namespace xstd {
class ostream {
public:
    ostream& operator<<(int n)
    {
        printf("%d", n);
        return *this;
    }

    ostream& operator<<(double d)
    {
        printf("%lf", d);
        return *this;
    }

    ostream& operator<<(char ch)
    {
        printf("%c", ch);
        return *this;
    }

    // endl
    ostream& operator<<(ostream& (*f)(ostream&))
    {
        return f(*this);
        // return *this;
    }
};

// endl
// : IO Manipulator(IO 조정자)
ostream& endl(ostream& os)
{
    os << '\n';
    return os;
}

ostream cout;
}

int main()
{
    int n = 42;
    xstd::cout << n;
    xstd::cout << xstd::endl;
    // cout.operator<<(endl);

    // endl(cout);
}
#endif

// 2. 사용자는 다양한 형태의 IO 조정자를 제공할 수 있습니다.
ostream& menu(ostream& os)
{
    os << "1. 자장면" << endl;
    os << "2. 짬뽕" << endl;
    os << "3. 탕수육" << endl;
    return os;
}

int main()
{
    cout << menu;
}
