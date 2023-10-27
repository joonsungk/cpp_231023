// 33_STL3.cpp
#include <iostream>
#include <vector>
#include <list>
using namespace std;

#if 0
void Print(int* first, int* last)
{
    int* p = first;
    while (p != last) {
        cout << *p << endl;
        ++p;
    }
}

void Print(vector<int>::iterator first, vector<int>::iterator last)
{
    vector<int>::iterator p = first;
    while (p != last) {
        cout << *p << endl;
        ++p;
    }
}
#endif

#if 0
template <typename Iterator>
void Print(Iterator first, Iterator last)
{
    Iterator p = first;
    while (p != last) {
        cout << *p << endl;
        ++p;
    }
}

int main()
{
    list<int> l = { 10, 20, 30, 40, 50 };
    Print(begin(l), end(l));

    int x[5] = { 10, 20, 30, 40, 50 };
    Print(begin(x), end(x));

    vector<int> v = { 1, 2, 3, 4, 5 };
    Print(begin(v), end(v));
}
#endif

// 3. 알고리즘(Algorithm)
// : 자료구조의 알고리즘은 타입만 다르고, 알고리즘은 동일합니다.

// <컨테이너>                   <알고리즘>
// vector
// list     ---> <반복자>  --->  템플릿 기반 일반함수
// array
// deque
//  ...
