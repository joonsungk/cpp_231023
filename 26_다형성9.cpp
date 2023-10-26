// 26_다형성8.cpp
#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    int type;
    virtual ~Shape() { }

    virtual void Draw() const { cout << "Shape Draw" << endl; }
    virtual Shape* Clone() const
    {
        return new Shape(*this); // 복사 생성자 호출
    }
};

class Rect : public Shape {
public:
    Rect() { type = 0; }

    void Draw() const override { cout << "Rect Draw" << endl; }

    virtual Shape* Clone() const override
    {
        return new Rect(*this);
    }
};

class Circle : public Shape {
public:
    Circle() { type = 1; }

    void Draw() const override { cout << "Circle Draw" << endl; }

    virtual Shape* Clone() const override
    {
        return new Circle(*this);
    }
};

// 리팩토링(Refactoring, 마틴 파울러)
// : 기존 코드의 동작을 변경하지 않고, 구조를 개선하는 작업
// - Replace type code with Polymorphism

int main()
{
    vector<Shape*> shapes;

    while (true) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            shapes.push_back(new Rect);
        } else if (cmd == 2) {
            shapes.push_back(new Circle);
        }

        else if (cmd == 0) {
            // 복제
            cout << "몇번째 도형을 복사? ";
            int index;
            cin >> index;

            Shape* copy = shapes[index]->Clone();
            shapes.push_back(copy);

// 문제점: 새로운 도형이 추가되면, 아래 코드는 수정되어야 합니다.
//       타입을 조사해서 처리하는 코드는 OCP를 만족하지 않습니다.
#if 0
            // shapes[index]; // Rect? Circle?
            Shape* p = shapes[index];
            if (p->type == 0) {
                // Rect
                shapes.push_back(new Rect(*static_cast<Rect*>(p)));
            } else if (p->type == 1) {
                // Circle
                shapes.push_back(new Circle(*static_cast<Circle*>(p)));
            }
#endif

        }

        else if (cmd == 9) {
            for (Shape* e : shapes) {
                e->Draw();
            }
        }
    }
}

// Unix / Linux
// : VFS(Virtual File System)
// "다형성"

// open
// read     ---> 일반 파일     ---> 파일 입출력
// write         소켓 파일     ---> 네트워크 입출력
// close       디바이스 특수 파일 ---> 디바이스 제어
