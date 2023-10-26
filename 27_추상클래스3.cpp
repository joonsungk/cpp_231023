// 27_추상클래스3.cpp
#include <iostream>
using namespace std;

// 1. 원인
//  Car ----------> Camera
//  : Car 클래스가 Camera의 구체적인 타입에 의존합니다.
//  "강한 결합"
//   - 교체가 불가능합니다.

// 2. 해결 방법
// => 약한 결합 / 느슨한 결합
//  : 구체적인 타입에 의존하는 것이 아니라, 인터페이스/추상클래스에 의존하는 것
// "교체 가능한 유연한 설계"
//  - OCP를 만족합니다.
//  DIP(Dependency Inversion Principle, 의존 관계 역전 원칙)
//  - 구체적인 타입에 의존하는 것이 아니라, 추상 클래스나 인터페이스에 의존해야 한다.

//  Car -----------> <<BlackBox>>
//                         |
//                     ----------
//                     |        |
//                 Camera     FHDCamera

// 1) 카메라의 제작자와 자동차의 제작자가 카메라의 사용 방법(함수)을 약속합니다.
//  => 인터페이스 / 프로토콜
//   : C++은 인터페이스를 위한 별도의 키워드를 제공하지 않습니다.
class BlackBox {
public:
    virtual ~BlackBox() { }

    virtual void StartRecording() = 0;
    virtual void StopRecording() = 0;
};

// 2) 자동차의 제작자는 인터페이스를 이용해서 코드를 작성합니다.
class Car {
    BlackBox* camera;

public:
    Car(BlackBox* p)
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

// 3) 모든 카메라의 제작자는 BlackBox의 인터페이스를 구현해서
//    카메라를 제공합니다.
//  => 인터페이스는 "상속 한다" 라고 하지 않고, "인터페이스를 구현 한다" 라고 표현합니다.

// class Camera extends BlackBox    // 상속
// class Camera implements BlackBox // 구현

class Camera : public BlackBox {
public:
    void StartRecording() override
    {
        cout << "Camera Start Recording" << endl;
    }

    void StopRecording() override
    {
        cout << "Camera Stop Recording" << endl;
    }
};

class FHDCamera : public BlackBox {
public:
    void StartRecording() override
    {
        cout << "FHD] Camera Start Recording" << endl;
    }

    void StopRecording() override
    {
        cout << "FHD] Camera Stop Recording" << endl;
    }
};

int main()
{
    FHDCamera camera;
    Car car { &camera };

    car.Go();
}
