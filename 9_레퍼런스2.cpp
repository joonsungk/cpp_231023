// 9_레퍼런스2.cpp
#include <iostream>
using namespace std;

void Increment(int x)
{
    ++x;
}

void Increment2(int* px)
{
    ++(*px);
}

void Increment3(int& rx)
{
    ++rx;
}

int main()
{
    int x = 10;
    // Increment(x); // Call by Value

    // Increment2(&x); // Call by address / pointer

    Increment3(x); // Call by reference

    cout << x << endl;
}
