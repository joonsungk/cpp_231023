// 8_제어문.cpp
#include <iostream>
using namespace std;

int main()
{
    int x[3] = { 10, 20, 30 };

    constexpr int len = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < len; ++i) {
        cout << x[i] << endl;
    }

    // C++11, Ranged-for
    for (auto e : x) {
        cout << e << endl;
    }
}
