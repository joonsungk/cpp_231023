// 20_객체복사.cpp
#include <iostream>
using namespace std;

// => 복사 정책
// 1) 깊은 복사

class User {
    char* name;
    int age;

public:
    //-----
    User(const User& rhs)
        : age { rhs.age }
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

    // a = a;
    User& operator=(const User& rhs)
    {
        // 1. 자신과 동일한 객체인지 확인
        if (this == &rhs) {
            return *this;
        }

        // 2. 소유한 자원을 해지해야 합니다.
        delete[] name;

        // 3. 깊은 복사
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);

        age = rhs.age;

        return *this;
    }

    //-----

    User(const char* s, int n)
        : age { n }
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~User()
    {
        delete[] name;
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
