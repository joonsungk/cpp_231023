// 29_접근변경자.cpp
#include <iostream>
using namespace std;

#include <vector> // 이미 잘 만들어진 컨테이너가 있습니다.

// 스택을 만들고 싶습니다.
// 1) 처음부터 스택을 만듭니다.
// 2) 이미 잘 만들어진 컨테이너를 재활용해서 만듭니다. - *

// Adapter Pattern
// : 기존 클래스를 재활용해서, 새로운 클래스처럼 보이게하는 설계 방법

// private 상속
// : 부모의 기능은 자식 클래스 내부에서만 사용 가능합니다.

#if 0
template <typename TYPE>
class Stack : private vector<TYPE> {
public:
    void Push(const TYPE& s)
    {
        vector<TYPE>::push_back(s); // 부모 기능 재사용
    }

    void Pop()
    {
        vector<TYPE>::pop_back();
    }

    TYPE& Top()
    {
        return vector<TYPE>::back();
    }

    const TYPE& Top() const
    {
        return vector<TYPE>::back();
    }
};

int main()
{
    Stack<int> s;

    s.Push(10);
    s.Push(20);
    s.Push(30);

    // s.push_back(100); // !!!

    cout << s.Top() << endl;
    s.Pop();

    cout << s.Top() << endl;
    s.Pop();

    cout << s.Top() << endl;
    s.Pop();
}
#endif

#include <stack>

#include <deque>
// 재사용을 위해서는 상속이 아니라, "포함"을 사용합니다.
//  : 실제 C++의 stack이 아래와 같은 형태로 구현되어 있습니다.
//    "Stack Adapter"
template <typename TYPE, typename C = deque<TYPE>>
class Stack {
    C v; // 포함!

public:
    void Push(const TYPE& s)
    {
        v.push_back(s);
    }

    void Pop()
    {
        v.pop_back();
    }

    TYPE& Top()
    {
        return v.back();
    }

    const TYPE& Top() const
    {
        return v.back();
    }
};

int main()
{
    Stack<int, vector<int>> s;

    s.Push(10);
    s.Push(20);
    s.Push(30);

    // s.push_back(100); // !!!

    cout << s.Top() << endl;
    s.Pop();

    cout << s.Top() << endl;
    s.Pop();

    cout << s.Top() << endl;
    s.Pop();
}
