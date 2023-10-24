// 18_초기화리스트2.cpp
#include <iostream>
using namespace std;

// 주의사항
// * 멤버 데이터가 초기화되는 순서는 초기화리스트의 순서가 아니라,
//   멤버 데이터가 선언된 순서대로 초기화됩니다.
// => 초기화리스트를 작성할 때, 반드시 멤버 데이터가 선언된 순서대로 작성해야 합니다.
class Point {
    int y;
    int x;

public:
    Point(int n)
        : y { n }
        , x { 10 + y }
    {
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point pt { 10 };
    pt.Print();
}
