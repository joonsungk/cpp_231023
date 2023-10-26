// 28_가상함수의원리
#include <iostream>
using namespace std;

class Shape {
    int x;
    int y;
};

class Rect : public Shape {
    int width;
    int height;
};

int main()
{
    Shape s;
    cout << sizeof(s) << endl; // 8

    Rect r;
    cout << sizeof(r) << endl; // 16
}
