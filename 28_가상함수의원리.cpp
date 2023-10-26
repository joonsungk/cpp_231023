// 28_가상함수의원리
#include <iostream>
using namespace std;

// 1. 가상함수를 가지는 모든 객체의 크기는 8바이트(가상함수 테이블 참조 포인터 멤버) 증가 합니다.
// 2. 가상함수의 비용
//  1) 객체 크기의 증가
//  2) 가상 함수 테이블
//    - 클래스 타입 * 가상 함수의 개수 ....

class Shape {
    int x;
    int y;
};

class Rect : public Shape {
    int width;
    int height;
};

int main()
{
    Shape s;
    cout << sizeof(s) << endl; // 8

    Rect r;
    cout << sizeof(r) << endl; // 16
}
