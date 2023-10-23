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
// 레퍼런스로 작성된 코드는 포인터로 작성할 수 있습니다.
// 포인터 작성된 코드는 레퍼런스를 통해 작성할 수 없는 경우도 있습니다.
// => 포인터와 레퍼런스 모두 작성할 수 있다면,
//    레퍼런스를 이용해서 작성하는 것이 좋습니다.
void Increment3(int& rx)
{
    ++rx;
}

void foo(int* result)
{
    // 결과를 받고 싶으면, 유효한 포인터를 전달해야 합니다.
    if (result) {
        *result = 42;
    }
}

// foo(NULL);
// foo(&x);

int main()
{
    int x = 10;
    // Increment(x); // Call by Value

    // Increment2(&x); // Call by address / pointer

    // Increment3(x); // Call by reference

    Increment2(NULL);

    cout << x << endl;
}
