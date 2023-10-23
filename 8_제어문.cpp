// 8_제어문.cpp
#include <iostream>
using namespace std;

#if 0
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
#endif

int Process()
{
    // 실패할 경우, -1을 반환합니다.
    return -1;
}

int* Process2()
{
    // 실패할 경우, NULL을 반환합니다.
    return NULL;
}

// C++17, If Statement with Initializer
int main()
{
    // 실패 가능성이 있는 함수를 사용할 때, 반드시 실패 여부를 검증해야 합니다.

    if (int ret = Process(); ret != 0) {
        // ...
    }

    if (int* ret = Process2(); ret == NULL) {
    }
}

#if 0
int main()
{
    // 실패 가능성이 있는 함수를 사용할 때, 반드시 실패 여부를 검증해야 합니다.
    int ret = Process();
    if (ret != 0) {
        // ...
    }

    int* ret2 = Process2();
    if (ret2 == NULL) {
    }
}
#endif
