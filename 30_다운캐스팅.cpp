// 30_다운캐스팅.cpp
#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual ~Animal() { } // 부모 소멸자는 반드시 가상이어야 합니다.
};

class Dog : public Animal {
    string name = "Bob";

public:
    string GetName() const { return name; }
};

// 1. 자식 클래스의 고유의 속성/함수에 접근하기 위해서는
//   부모의 포인터/참조 타입을 자식의 포인터/참조 타입으로의 명시적인 변환이 필요합니다.

int main()
{
    Dog d;
    cout << d.GetName() << endl;

    // Animal* p = &d;
    // cout << p->GetName() << endl; /* 오류 */

#if 0
    Animal a;
    Animal* p = &a;

    Dog* pDog = static_cast<Dog*>(p);
    cout << pDog->GetName() << endl;
#endif
    // static_cast를 다운 캐스팅에서 사용할 수 있습니다.
    // 주의 사항: 잘못된 다운 캐스팅의 위험성이 있습니다.
    //         실행시간에 타입을 조사해서, 다운 캐스팅을 수행해야 합니다.

    // C++: RTTI(Run Time Type Information)
    // - typeid(객체)   -> type_info 객체
    // - typeid(클래스)  -> type_info 객체
#if 0
    Animal a;
    // Animal* p = &a;
    Animal* p = &d;

    if (typeid(*p) == typeid(Dog)) {
        Dog* pDog = static_cast<Dog*>(p);
        cout << pDog->GetName() << endl;
    } else {
        cout << "Dog가 아닙니다." << endl;
    }
#endif

    // dynamic_cast
    // : 실행 시간에 타입을 조사해서, 잘못된 타입인 경우, 캐스팅 결과로 nullptr을 반환합니다.

    Animal a;
    Animal* p = &a;

    Dog* pDog = dynamic_cast<Dog*>(p);
    if (pDog) {
        cout << pDog->GetName() << endl;
    } else {
        cout << "Dog가 아닙니다." << endl;
    }

    // C++ 다운 캐스팅
    // => static_cast
    //  : 컴파일 시간에 캐스팅을 수행합니다.
    //    실패 가능성이 없는 다운 캐스팅에서 사용합니다.

    //    dynamic_cast
    //  : 실행 시간에 캐스팅을 수행합니다.
    //    잘못된 타입인 경우, nullptr을 반환합니다.
    //  -> type_info: 가상 함수 테이블을 통해 관리됩니다.
}
