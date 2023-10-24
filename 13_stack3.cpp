// 13_stack3.cpp
#include <iostream>
using namespace std;

// 3. C++에서는 사용자 정의 타입에서 데이터 뿐 아니라
//    데이터를 조작하는 함수도 묶을 수 있습니다.

// * 객체의 상태는 객체가 제공하는 멤버 함수를 통해서만
//   접근 가능해야 합니다.
// => 정보 은닉(Information Hiding)
//   : 접근 지정자
//     1) public: 외부에서 접근할 수 있습니다.
//     2) private: 외부에서 접근할 수 없고, 오직 멤버 함수를 통해서만 접근이 가능합니다.
//      struct는 기본 접근 지정자가 public 이지만, class는 기본 접근 지정자가 private 입니다.
//    => 객체의 상태를 외부에서 함부로 변경할 수 없도록, class 이용합니다.

// 캡슐화: 상태 + 행위
class Stack {
    // private:
    // 멤버 데이터: 상태
    int buff[10];
    int top;

public:
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
    // 구조체 변수: 상태와 행위 => 객체(object)

    s1.Init();

    // s1.top = 10; /* 잘못된 접근 */

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
