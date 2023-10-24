// 14_접근지정자.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. struct의 기본 접근 지정자는 public 입니다.
//    class의 기본 접근 지정자는 private 입니다.

// 2. public은 외부에서 접근이 가능하고, private은 외부에서 접근이 불가능합니다.

// 3. friend
//  => friend 선언된 클래스 또는 함수는 private 영역에 접근이 가능합니다.
#if 0
class User {
    string name;
    int age;

public:
    User(string s, int n)
    {
        name = s;
        age = n;
    }

    // 접근자 메소드 - Getter
    // string GetName() { return name; }
    // int GetAge() { return age; }

    friend void PrintUser(User user); // !!!
    // friend: 클래스의 캡슐화의 정책을 깨뜨리는 것이 아니라, 확장할 수 있습니다.
};
#endif
#include "User.h"

int main()
{
    User user("Tom", 42);
    PrintUser(user);

    // cout << user.name << ", " << user.age << endl;
    // cout << user.GetName() << ", " << user.GetAge() << endl;
}
