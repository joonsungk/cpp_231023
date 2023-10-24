// 13_stack3.cpp
#include <iostream>
using namespace std;

// 3. C++에서는 사용자 정의 타입에서 데이터 뿐 아니라
//    데이터를 조작하는 함수도 묶을 수 있습니다.

// 캡슐화: 상태 + 행위
struct Stack {
    // 멤버 데이터: 상태
    int buff[10];
    int top;

    // 멤버 함수: 행위
    void Init()
    {
        top = 0;
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
    Stack s1;
    s1.Init();

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
