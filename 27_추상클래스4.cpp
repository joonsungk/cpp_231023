// 27_추상클래스4.cpp
#include <iostream>
using namespace std;

// 인터페이스
// => 교체 가능한 유연한 설계

// 인터페이스 문제점
// => 인터페이스에 새로운 기능을 추가하기 어렵습니다.
//    인터페이스에 새로운 함수(순수 가상 함수)를 추가하면,
//    기존에 인터페이스를 구현하는 모든 구현체에서 해당 기능을 반드시 재정의해야 합니다.

// => ISP(Interface Segregation Principle, 인터페이스 분리 원칙)
//   : 범용 인터페이스보다 세분화된 인터페이스가 좋다.

class MP3 {
public:
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;

    // virtual void PlayOneMinute() = 0;

    virtual void PlayOneMinute()
    {
        // ...
    }

    //  Java 8 - Modern Java
    // => 인터페이스 함수에 기본 구현을 제공하는 기능이 추가되었습니다.
    //  "defender method"
};

class Car {
    MP3* player;

public:
    Car(MP3* p)
        : player { p }
    {
    }

    void PlayMusic()
    {
        player->Play();
        player->Stop();
    }
};

class Model1 : public MP3 {
public:
    void Play() override { }
    void Stop() override { }
};
class Model2 : public MP3 {
public:
    void Play() override { }
    void Stop() override { }
};

int main()
{
    Model1 mp3;
    Car car { &mp3 };

    car.PlayMusic();
}
