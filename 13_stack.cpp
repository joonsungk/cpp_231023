// 13_stack.cpp
#include <iostream>
using namespace std;

// 스택을 만들어봅시다.
// : 가장 마지막에 삽입된 데이터가 가장 먼저 나옵니다.
//   - Last In First Out(LIFO)

// 1. 전역 변수 / 전역 함수
int buff[10];
int top = 0;

void Push(int n)
{
    buff[top++] = n;
}

int Pop()
{
    return buff[--top];
}

int main()
{
    Push(10);
    Push(20);
    Push(30);

    cout << Pop() << endl;
    cout << Pop() << endl;
    cout << Pop() << endl;
}
