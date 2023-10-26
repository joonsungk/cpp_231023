// 19_복사생성자3.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample&) { cout << "Sample(const Sample&)" << endl; }
    // C++에서는 사용되지 않는 인자는 생략할 수 있습니다.
};

// 복사 생성자가 호출되는 시점
/// 2. 함수가 객체를 값으로 반환할 때

#if 0
// 전역 객체
Sample s;
Sample& foo()
{

    return s;
    // 1) s --> 반환용 임시 객체: Sample(const Sample&)
    //     복사 생성
}

int main()
{
    cout << "----------" << endl;
    foo();
    // 2) 반환용 임시 객체 파괴 - ~Sample()
    cout << "----------" << endl;
}
#endif

#if 1
#include <stack>

int main()
{
    stack<int> s;
    s.push(10);

    // 제거하는 연산과 참조하는 연산이 분리되어 있습니다.
    // => 제거와 참조를 동시에 수행할 수 없습니다.
    // 이유: 값으로 반환하는 것이 아니라, 참조로 반환하기 위해서
    //  - STL이 제공하는 모든 컨테이너는 제거와 참조 연산이 분리되어서 제공됩니다.

    cout << s.top() << endl;
    s.pop();
}
#endif
