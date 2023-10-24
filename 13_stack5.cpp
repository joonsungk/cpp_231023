// 13_stack5.cpp
#include <iostream>
using namespace std;

// 5. 사용자가 원하는 크기의 스택을 생성하고 싶습니다.
//    객체를 생성할 때, 사용자로부터의 정보를 전달 받을 수 있습니다.
//    => 생성자 인자

//   Stack s;
//   Stack s(); ---> Stack();
//   Stack s{};

//   Stack s(10); ---> Stack(int)
//   Stack s{10};

// => 생성자도 오버로딩이 가능합니다.
//  "객체를 생성하는 다양한 방법을 제공할 수 있습니다."

class Stack {
    // int buff[10];
    int* buff;
    int top;

public:
    Stack(int size)
    {
        cout << "Stack(int)" << endl;
        top = 0;
        buff = new int[size];
    }

    Stack()
    {
        cout << "Stack()" << endl;
        top = 0;
        buff = new int[10];
    }

    void Push(int n)
    {
        buff[top++] = n;
    }

    int Pop()
    {
        return buff[--top];
    }
};

int main()
{
    // Stack s1(100);
    Stack s1 { 100 };
    // 구조체 변수: 상태와 행위 => 객체(object)

    // s1.Init();

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
