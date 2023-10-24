// 8_제어문.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int x[3] = { 10, 20, 30 };

    constexpr int len = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < len; ++i) {
        cout << x[i] << endl;
    }

    // 모든 요소를 두배로 변경하고 싶습니다.
    for (auto& e : x) {
        e *= 2;
    }

    // C++11, Ranged-for
    for (auto e : x) {
        cout << e << endl;
    }
}
#endif

#if 1
int Process()
{
    // 실패할 경우, -1을 반환합니다.
    return -1;
}

int* Process2()
{
    // 실패할 경우, NULL을 반환합니다.
    return NULL;
}

// C++17, If/Switch Statement with Initializer

enum TaskState {
    TASK_RUNNING,
    TASK_STOPPED
};

TaskState GetTaskState() { return TASK_RUNNING; }

int main()
{
    switch (TaskState state = GetTaskState(); state) {
    case TASK_RUNNING:
        cout << state << endl;
        break;
    case TASK_STOPPED:
        break;
    default:
        break;
    }

    // 실패 가능성이 있는 함수를 사용할 때, 반드시 실패 여부를 검증해야 합니다.
    if (int ret = Process(); ret != 0) {
        // ...
    }

    if (int* ret = Process2(); ret == NULL) {
    }
}
#endif

#if 0
int main()
{
    // 실패 가능성이 있는 함수를 사용할 때, 반드시 실패 여부를 검증해야 합니다.
    int ret = Process();
    if (ret != 0) {
        // ...
    }

    int* ret2 = Process2();
    if (ret2 == NULL) {
        // ...
    }
}
#endif
