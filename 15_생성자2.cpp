// 15_생성자2.cpp
#include <iostream>
using namespace std;

#include <cstdlib> // malloc, free

class Object {
public:
    Object() { cout << "Object()" << endl; }
    Object(int a, int b) { cout << "Object(int, int)" << endl; }

    ~Object() { cout << "~Object()" << endl; }
};

// 1. malloc을 통해서 객체의 메모리를 할당한 경우, 생성자가 호출되지 않고,
//    free를 통해서 객체의 메모리를 해지한 경우, 소멸자가 호출되지 않습니다.

// 2. new를 통해서 객체를 생성한 경우, 생성자가 호출됩니다.
//   delete를 통해서 객체를 파괴한 경우, 소멸자가 호출됩니다.

// new 연산
// 1) 동적 메모리 할당
// 2) 객체라면, 생성자 호출

// delete 연산
// 1) 객체라면, 소멸자 호출
// 2) 동적 메모리 해지

#if 0
int main()
{
    // Object* p1 = new Object;
    // delete p1;

    Object* p2 = new Object[3];
    delete[] p2;
}
#endif

#if 0
int main()
{
    Object* p1 = static_cast<Object*>(malloc(sizeof(Object)));

    free(p1);
}
#endif

int main()
{
    // Object* p = new Object(); // 동적 메모리 할당 -> 기본 생성자 호출

    // Object(); -> 임시 객체 생성 문법

    // Object* p = new Object;
    // 동적 메모리 할당 -> 기본 생성자 호출

    // 동적 메모리 할당 -> Object(int, int) 생성자 호출
    Object* p = new Object(10, 20);
    // Object* p = new Object { 10, 20 };
    delete p;

    // Object p2;
    // 스택 메모리 할당 -> 기본 생성자 호출

    Object* p2 = new Object[3] { { 10, 20 }, {}, { 100, 200 } };
    delete[] p2;
}
