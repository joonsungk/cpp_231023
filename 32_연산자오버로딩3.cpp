// 32_연산자오버로딩3.cpp
#include <iostream>
using namespace std;

#if 0
namespace xstd {
class istream {
public:
    istream& operator>>(int& n)
    {
        scanf("%d", &n);
        return *this;
    }
};

istream cin;
};

int main()
{
    int n1, n2;
    xstd::cin >> n1 >> n2;
    // cin.operator>>(n1).operator>>(n2);

    cout << n1 << ", " << n2 << endl;
}
#endif

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    friend ostream& operator<<(ostream& os, const Point& pt);
    friend istream& operator>>(istream& is, Point& pt);
};

istream& operator>>(istream& is, Point& pt)
{
    return is >> pt.x >> pt.y;
    // return is;
}

ostream& operator<<(ostream& os, const Point& pt)
{
    return os << pt.x << ", " << pt.y;
    // return os;
}

int main()
{
    Point pt { 10, 20 };

    cin >> pt;
    // cin.operator>>(pt);
    // operator>>(cin, pt);

    cout << pt << endl;

    cout << endl;
}
