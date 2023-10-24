// 17_this.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
    // void Set(Point* this, int a, int b)
    void Set(int a, int b)
    {
        cout << "this: " << this << endl;
        // this: 멤버 함수에서 객체의 주소

        x = a;
        // this->x = a;
        y = b;
        // this->y = b;
    }
};

void Set(int x, int y)
{
}

int main()
{
    Set(10, 20);
    /*
        mov     edx, 20
        mov     ecx, 10
        call    void Set(int,int)
    */

    Point pt1, pt2;

    cout << &pt1 << endl;
    pt1.Set(10, 20);
    /*
        mov     r8d, 20
        mov     edx, 10
        lea     rcx, QWORD PTR pt1$[rsp] ; rcx = &pt1;
        call    void Point::Set(int,int)
    */

    cout << &pt2 << endl;
    pt2.Set(100, 200);
}
