// 13_stack6.cpp
#include <iostream>
using namespace std;

// 8. 클래스도 템플릿으로 만들 수 있습니다.

template <typename TYPE>
class Stack {
    TYPE* buff;
    int top;

public:
    ~Stack()
    {
        delete[] buff; // !!
    }

    Stack(int size)
    {
        top = 0;
        buff = new TYPE[size];
    }

    Stack()
    {
        top = 0;
        buff = new TYPE[10];
    }

    void Push(TYPE n)
    {
        buff[top++] = n;
    }

    TYPE Pop()
    {
        return buff[--top];
    }
};

// 함수 템플릿은 함수의 인자를 통해 타입을 암묵적으로 추론이 가능하지만,
// 클래스 템플릿은 암묵적인 추론이 불가능합니다.
// => 명시적으로 타입을 지정해야 합니다.
#if 0
int main()
{
    Stack<int> s1 { 100 };

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
#endif

#include <string>

int main()
{
    Stack<string> s1 { 100 };

    s1.Push("hello");
    s1.Push("world");
    s1.Push("good");

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
