// 19_복사생성자2.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample&) { cout << "Sample(const Sample&)" << endl; }
    // C++에서는 사용되지 않는 인자는 생략할 수 있습니다.
};

// 복사 생성자가 호출되는 경우
// 1) 객체가 함수의 인자로 call by value로 전달될 때
#if 0
void foo(Sample s) // Sample(const Sample&)
{
} // ~Sample()
#endif

#if 0
// * 핵심: 객체를 함수의 인자로 전달할 때, call by value의 의도로 사용한다면,
//        const&를 이용해야 합니다.
//    "불필요한 객체의 복사 생성/소멸 비용을 제거하기 위해서"
void foo(const Sample& s) // 참조를 읽기 전용 목적으로만 사용하겠다.
{
}

// call by value의 의도는 값을 읽기 위해서 사용합니다.

int main()
{
    Sample s;

    cout << "------------" << endl;
    foo(s);
    cout << "------------" << endl;
}
#endif

#if 1
template <typename TYPE>
class Stack {
public:
    // void Push(TYPE n)
    //  : 템플릿에서도 인자로 전달 받을 때, const TYPE&를 사용합니다.
    //    객체 타입으로 코드가 생성될 수 있기 때문입니다.
    void Push(const TYPE& n)
    {
        //...
    }
};

int main()
{
    Stack<int> s;
    // -> void Push(const int& n)

    Stack<Sample> s2;
    // -> void Push(const Sample& n)
}
#endif

#if 0
int main()
{
    Stack<int> s;
    s.Push(10);
    // void Push(int n)

    Stack<Sample> s2;
    // -> void Push(Sample n)
}
#endif
