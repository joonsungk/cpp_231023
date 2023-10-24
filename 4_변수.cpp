// 4_변수.cpp
#include <iostream>
using namespace std;

struct Complex {
    int re;
    int im;
};
// typedef struct Complex COMPLEX;

union Data {
    int a;
    double b;
};

enum State {
    TASK_RUNNING,
    TASK_STOPPED,
};

int main()
{
    // C 에서는
    struct Complex c1;
    union Data d1;
    enum State s1;

    // C++에서는 태그가 타입으로 인식됩니다.
    Complex c2;
    Data d2;
    State s2;
}
