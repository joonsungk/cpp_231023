// 33_STL4.cpp
#include <vector>
#include <iostream>
using namespace std;

#include <algorithm> // 알고리즘 함수가 제공됩니다.

// 인라인 함수라고 하더라도, 함수 포인터를 통해서 호출하면,
// 인라인 최적화가 불가능합니다.
inline bool cmp1(int a, int b)
{
    // cout << "cmp1" << endl;
    return a < b;
}

// 함수 객체를 정책으로 전달하면, 인라인 최적화가 가능합니다!
class Func {
public:
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

#if 1
int main()
{

    vector<int> x = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

    sort(begin(x), end(x), cmp1);
    //                  bool (*)(int, int)

    Func cmp;
    sort(begin(x), end(x), cmp);
    //                     Func

    // C++11, 함수 객체를 만드는 새로운 문법이 도입되었습니다.
    // => Lambda Expression(람다 표현식)
    // : 실행 가능한 코드 조각을 참조하는 기술
    // - C++에서는 익명의 함수 객체를 생성하는 문법
    sort(begin(x), end(x), [](int a, int b) -> bool { return a > b; });

    for (auto e : x) {
        cout << e << endl;
    }
}
#endif

#if 0
int main()
{
    bool a1 = cmp1(10, 20);

    bool (*f)(int, int) = cmp1;
    bool a2 = f(10, 20);
}
#endif
