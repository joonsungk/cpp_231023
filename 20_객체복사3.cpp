// 20_객체복사3.cpp
#include <iostream>
using namespace std;

// => 복사 정책
// 2) 참조 계수
//  : 소유권 공유

class User {
    char* name;
    int age;

    int* ref; // !!
    // 스레드 안전해야 합니다.
    // => 동기화 처리

public:
    User(const User& rhs)
        : name { rhs.name }
        , age { rhs.age }
        , ref { rhs.ref }
    {
        ++(*ref); // !!!
    }

    User& operator=(const User& rhs)
    {
        // 1. 자신과 동일한 객체인지 확인
        if (this == &rhs) {
            return *this;
        }

        // 2. 참조 계수 감소
        if (--(*ref) == 0) {
            delete[] name;
            delete ref;
        }

        // 3. 얕은 복사 + 참조 계수 증가
        name = rhs.name;
        age = rhs.age;
        ref = rhs.ref;

        ++(*ref);

        return *this;
    }

    User(const char* s, int n)
        : age { n }
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);

        ref = new int { 1 }; // !!
    }

    ~User()
    {
        if (--(*ref) == 0) {
            delete[] name;
            delete ref;
        }
    }

    void Print()
    {
        cout << name << ", " << age << endl;
    }
};

int main()
{
    User user { "Tom", 42 };
    user.Print();

    User other = user;
    other.Print();
}
