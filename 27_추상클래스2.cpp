// 27_추상클래스2.cpp
#include <iostream>
using namespace std;

// SRP(Single Reponsibility Principle, 단일 책임 원칙)
// : 클래스는 단 하나의 책임을 가져야 한다.

class Camera {
public:
    void StartRecording() { cout << "Start Recording" << endl; }
    void StopRecording() { cout << "Stop Recording" << endl; }
};

class FHDCamera {
public:
    void StartRecording() { cout << "FHDCamera] Start Recording" << endl; }
    void StopRecording() { cout << "FHDCamera] Stop Recording" << endl; }
};

// 문제점: 새로운 카메라가 추가될 때마다, 자동차의 코드는 수정되어야 합니다.
// => OCP를 만족하지 않습니다.

class Car {
    Camera* camera;

public:
    Car(Camera* p)
        : camera { p }
    {
    }

    void Go()
    {
        camera->StartRecording();

        cout << "Car Go" << endl;

        camera->StopRecording();
    }
};

int main()
{
    Camera camera;
    Car car { &camera };

    car.Go();
}
