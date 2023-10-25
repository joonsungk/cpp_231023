// 24_참조반환.cpp
#include <iostream>
using namespace std;

#if 0
class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Print() const { cout << x << ", " << y << endl; }

    void Move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
};

int main()
{
    Point pt { 0, 0 };

    pt.Move(10, 20);
    pt.Move(10, 20);
    pt.Move(10, 20);
    pt.Move(10, 20);
}
#endif

#if 0
class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Print() const { cout << x << ", " << y << endl; }

    Point* Move(int dx, int dy)
    {
        x += dx;
        y += dy;

        return this;
    }
};

int main()
{
    Point pt { 0, 0 };

    pt.Move(10, 20)
        ->Move(10, 20)
        ->Move(10, 20)
        ->Move(10, 20);

    pt.Print();
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

    void Print() const { cout << x << ", " << y << endl; }

    Point& Move(int dx, int dy)
    {
        x += dx;
        y += dy;

        return *this; // 자기 자신의 참조를 반환
    }
};

int main()
{
    Point pt { 0, 0 };

    // Chaining => 참조 반환
    pt.Move(10, 20)
        .Move(10, 20)
        .Move(10, 20)
        .Move(10, 20);

    pt.Print();
}
