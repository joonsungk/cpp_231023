// 13_stack10.cpp
#include <iostream>
using namespace std;

// 1. 전역 변수 / 전역 함수
#if 0
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
#endif

// 2. 데이터 캡슐화 => 사용자 정의 타입 설계
#if 0
struct Stack {
    int buff[10];
    int top;
};

void Init(Stack* s)
{
    s->top = 0;
}

void Push(Stack* s, int n)
{
    s->buff[(s->top)++] = n;
}

int Pop(Stack* s)
{
    return s->buff[--(s->top)];
}

int main()
{
    Stack s1, s2;
    Init(&s1);
    Init(&s2);

    Push(&s1, 10);
    Push(&s1, 20);
    Push(&s1, 30);

    cout << Pop(&s1) << endl;
    cout << Pop(&s1) << endl;
    cout << Pop(&s1) << endl;
}
#endif

// 3. 캡슐화
//  => 데이터(상태) + 함수(행위)

// * 객체의 상태는 객체가 제공하는 함수를 통해서만 접근할 수 있어야 합니다.
//  => 정보 은닉(Information Hiding)
//   : 접근 지정자
//   -  public: 외부에서 접근이 가능합니다.
//   - private: 외부에서 접근이 불가능하고, 오직 멤버 함수를 통해서만 접근이 가능합니다.

// struct의 기본 접근 지정자는 public 이지만, class의 기본 접근 지정자는 private 입니다.
#if 0
class Stack {
    // 멤버 데이터 => 상태(Property)
    int buff[10];
    int top;

public:
    // 멤버 함수 => 행위(Method)
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
    Stack s1, s2;
    // 변수가 상태와 행위를 가지는 경우,
    // 객체(Object)라고 합니다.

    s1.Init();
    s2.Init();

    // s2.top = 100;

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
#endif

// 4. 객체는 생성후에 바로 사용할수 있는 상태가 되어야 합니다.
//  => 객체가 메모리에 생성된 후에 바로 수행되는 약속된 멤버 함수가 존재합니다.
//    : 생성자(Constructor) 함수
#if 0
class Stack {
    int buff[10];
    int top;

public:
    Stack()
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

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
#endif

// 5. 사용자가 원하는 크기의 스택을 생성하고 싶습니다.
//    객체를 생성할 때, 사용자로부터 정보를 전달 받을 수 있습니다.
//  => 생성자 인자
//  => 생성자는 오버로딩이 가능합니다.
//    "객체를 생성하는 다양한 방법을 제공할 수 있습니다."

//  Stack s;      --> Stack()
//  Stack s{10};  --> Stack(int)
#if 0
class Stack {
    int* buff;
    int top;

public:
    // 파라미터 기본값은 불필요한 오버로딩을 제거할 수 있습니다.
    Stack(int size = 10)
    {
        buff = new int[size];
        top = 0;
    }

#if 0
    Stack()
    {
        buff = new int[10];
        top = 0;
    }
#endif

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
    Stack s1 { 100 };

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
#endif

// 6. 객체 내부에서 자원(메모리, 파일, ...)을 할당한 경우,
//    객체가 파괴되기 전에 자원을 해지해야 합니다.
//  => 객체가 메모리에서 파괴되기 전에 호출되는 약속된 멤버 함수가 있습니다.
//       : 소멸자(Destructor) 함수
//      - 인자 없는 형태, 오직 1개만 제공할 수 있습니다.
#if 0
class Stack {
    int* buff;
    int top;

public:
    ~Stack()
    {
        delete[] buff; // !!!
    }

    // 파라미터 기본값은 불필요한 오버로딩을 제거할 수 있습니다.
    Stack(int size = 10)
    {
        buff = new int[size];
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
    Stack s1 { 100 };

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
#endif

// 7. 템플릿 도입
#if 0
template <typename TYPE>
class Stack {
    TYPE* buff;
    int top;

public:
    ~Stack()
    {
        delete[] buff; // !!!
    }

    // 파라미터 기본값은 불필요한 오버로딩을 제거할 수 있습니다.
    Stack(int size = 10)
    {
        buff = new TYPE[size];
        top = 0;
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

int main()
{
    // 클래스 템플릿은 명시적으로 타입을 지정해야 합니다.
    Stack<int> s1 { 100 };

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
#endif

#include <stack>

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    // 데이터를 참조하는 연산과 제거하는 연산이 분리되어 있습니다.
    // - 참조하는 연산: s.top();
    // - 제거하는 연산: s.pop();

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}
