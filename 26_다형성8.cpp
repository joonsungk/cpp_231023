// 26_다형성8.cpp
#include <iostream>
#include <vector>
using namespace std;

// 1. 각 도형의 클래스를 설계합니다.
// 2. 부모 클래스 도입
//   => 동종을 보관하는 컨테이너

// 3. 자식의 공통의 기능을 부모 클래스의 포인터/참조 타입을 통해 이용하기 위해서는
//    반드시 해당 특징이 부모로부터 비롯되어야 합니다.
//    : LSP(Liskov Substitution Principle, 리스코프 치환 원칙)
//     자식 클래스는 부모 클래스로 대체할 수 있어야 한다.
//     "자식의 공통의 기능이 부모로부터 비롯되어야 한다."

// 4. 자식이 재정의하는 부모의 멤버 함수는 반드시 가상 함수 이어야 한다.
// 5. 부모의 소멸자는 반드시 가상 이어야 합니다.

// 6. OCP(Open Close Principle, 개방 폐쇄 원칙)
//  : 확장에는 열려 있고, 수정에는 닫혀 있어야 한다.
//    "새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다."

// 7. 다형성은 OCP를 만족합니다.
//   => 상속의 목적은 "다형성" 입니다.

class Shape {
public:
    virtual ~Shape() { }

    virtual void Draw() const { cout << "Shape Draw" << endl; }
};

class Rect : public Shape {
public:
    void Draw() const override { cout << "Rect Draw" << endl; }
};

class Circle : public Shape {
public:
    void Draw() const override { cout << "Circle Draw" << endl; }
};

class Triangle : public Shape {
public:
    void Draw() const override { cout << "Triangle Draw" << endl; }
};

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
        } else if (cmd == 3) {
            shapes.push_back(new Triangle);
        }

        else if (cmd == 9) {
            for (Shape* e : shapes) {
                e->Draw();
                //             e가    Rect  -> Rect::Draw
                // Draw ->         Circle  -> Circle::Draw
                //                Triangle -> Triangle::Draw
                // => 다형성(Polymorphism)
            }
        } else if (cmd == 0) {
            break;
        }
    }

    for (auto e : shapes) {
        delete e;
    }
}

// Unix / Linux
// : VFS(Virtual File System)
// "다형성"

// open
// read     ---> 일반 파일     ---> 파일 입출력
// write         소켓 파일     ---> 네트워크 입출력
// close       디바이스 특수 파일 ---> 디바이스 제어
