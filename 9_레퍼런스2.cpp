// 9_레퍼런스2.cpp
#include <iostream>
using namespace std;

void Increment(int x)
{
    ++x;
}

void Increment2(int* px)
{
    if (px) {
        ++(*px);
    }
}

// 레퍼런스는 유효성 체크가 필요하지 않습니다.
void Increment3(int& rx)
{
    ++rx;
}

int main()
{
    int x = 10;
    // Increment(x); // Call by Value

    // Increment2(&x); // Call by address / pointer

    // Increment3(x); // Call by reference

    Increment2(NULL);

    cout << x << endl;
}
