// 4_변수4.cpp
#include <iostream>
using namespace std;

// C++11, decltype
// => 주어진 표현식과 동일한 타입을 구하는 연산자입니다.

// GNU extention
// => typeof와 동일한 기능입니다.

int main()
{
    const int x = 100;

    decltype(x) a = 42;
    // 우항이 반드시 필요하지 않습니다.

    // a = 100;
    //  : x와 동일한 타입인 const int가 되었으므로, 값을 수정할 수 없습니다.
}
