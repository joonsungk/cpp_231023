// 27_추상클래스4.cpp
#include <iostream>
using namespace std;

// 인터페이스
// => 교체 가능한 유연한 설계

class MP3 {
public:
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;
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
