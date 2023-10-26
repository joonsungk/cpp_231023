// 25_상속6.cpp
#include <iostream>
using namespace std;

// protected 생성자
// 의도: 부모 클래스의 객체는 생성하지 않고, 자식 클래스의 객체만 생성하도록 하고 싶다.
//  => 부모 클래스를 추상(abstract) 개념으로 사용하고 싶다.
#if 0
class Animal {
protected:
    Animal() { }
};

class Dog : public Animal {
public:
    Dog()
        : Animal {}
    {
    }
};

int main()
{
    // Animal a;
    Dog d;
}
#endif

// private 생성자
// : 객체 생성의 정책을 제어하고 싶다.

// - Singleton
// => 마이어스의 싱글톤
class Cursor {
private:
    Cursor() { cout << "Cursor()" << endl; }

    // 복사와 이동을 금지해야 합니다.
    Cursor(const Cursor&) = delete;
    Cursor(Cursor&&) = delete;

public:
    // Static Factory Method
    static Cursor& GetInstance()
    {
        static Cursor c;
        // GetInstance()가 처음 호출되는 시점에 객체가 생성되고, 이후에는 참조합니다.

        return c;
    }
};

int main()
{
    cout << "----" << endl;
    Cursor& c1 = Cursor::GetInstance();
    cout << "----" << endl;
    Cursor& c2 = Cursor::GetInstance();
    cout << "----" << endl;

    cout << &c1 << endl;
    cout << &c2 << endl;
}
