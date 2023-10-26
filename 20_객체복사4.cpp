// 20_객체복사4.cpp
#include <iostream>
using namespace std;

// => 복사 정책
// 3) 복사 금지
//   : 소유권을 독점

// 1. 복사를 금지하기 위해, 복사 생성자를 private 영역에 선언만 합니다.
// 2. C++11, Delete Function
//   복사 생성자를 삭제합니다.

class User {
    char* name;
    int age;

    User(const User& rhs) = delete; // 복사 금지
    User(User&& rhs) = delete; // 이동 금지

public:
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

    // User other = user;
    // other.Print();
}
