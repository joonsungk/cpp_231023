// 27_추상클래스.cpp
#include <iostream>
using namespace std;

// Shape 클래스는 순수 가상 함수를 가지고 있기 때문에,
// 객체를 인스턴스화 할 수 없습니다.
//  => 추상 클래스(Abstract class)
//   정의: 순수 가상 함수를 1개 이상 가지는 클래스
class Shape {
public:
    virtual ~Shape() { }

    // 부모의 입장에서는 구현을 제공할 필요가 없습니다.
    // 자식 클래스는 반드시 아래의 구현을 오버라이딩을 통해 제공해야 합니다.
    //  => 순수 가상 함수(Pure Virtual Function)

    virtual void Draw() const = 0;
    virtual Shape* Clone() const = 0;
};

// 자식 클래스가 부모 클래스가 제공하는 순수 가상함수를 재정의하지 않으면,
// 자식 클래스도 추상 클래스가 되어서, 객체를 생성할 수 없습니다.
class Rect : public Shape {
public:
    void Draw() const override { cout << "Rect Draw" << endl; }

    Shape* Clone() const override
    {
        return new Rect(*this);
    }
};

int main()
{
    // Shape s;

    Rect r;
}
