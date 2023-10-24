// 13_stack6.cpp
#include <iostream>
using namespace std;

// 6. 객체 내부에서 new를 통해 메모리가 할당되었다면,
//    반드시 객체가 메모리에 파괴되기 직전에, 해당 메모리를 해지해야 합니다.
//   : 객체가 메모리에서 파괴되기 직전에 호출되는 약속된 멤버 함수가 있습니다.
//     - 소멸자(Destructor)
// 1) 소멸자 함수의 이름은 ~클래스이름 입니다.
// 2) 소멸자는 인자가 없습니다. 반환값도 없고, 반환 타입도 명시하지 않습니다.
// 3) 소멸자는 인자 없는 오직 1개만 제공할 수 있습니다.

class Stack {
    // int buff[10];
    int* buff;
    int top;

public:
    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff; // !!
    }

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

#if 1
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
#endif

#if 0
class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }
};

Sample s;

int main()
{
    cout << "main start" << endl;
    {
        // Sample s; // 지역 객체
    }

    cout << "main end" << endl;
}
#endif
