// 26_다형성8.cpp
#include <iostream>
#include <vector>
using namespace std;

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
