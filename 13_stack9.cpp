// 13_stack9.cpp
//  : 이미 C++ 표준 라이브러리를 통해 다양한 자료구조가 제공되고,
//    그 중에 스택이 있습니다.
#include <iostream>
using namespace std;

// STL(Standard Template Library)
// : 템플릿 기반으로 제공되는 모든 타입에 일반적으로 동작하는 표준 라이브러리

#include <stack>

#if 0
int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    // 데이터를 제거하는 연산과, 참조하는 연산이 분리되어 있습니다.
    //  - 참조하는 연산: s.top();
    //  - 제거하는 연산: s.pop();

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}
#endif

// 선형 자료구조(컨테이너/컬렉션)
// - vector: 연속된 메모리를 사용하는 동적 배열
// -   list: 연결 리스트
#include <vector>
#include <list>

int main()
{
    int arr[3];
    vector<int> v = { 10, 20, 30, 40 };
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << v[0] << endl;

    for (auto e : v) {
        cout << e << endl;
    }
}
