// 20_객체복사5.cpp
#include <iostream>
using namespace std;

#if 0
class Color {
public:
    Color() { cout << "Color()" << endl; }
    Color(int a, int b) { cout << "Color(int, int)" << endl; }
    ~Color() { cout << "~Color()" << endl; }
};

void SetBackgroundColor(const Color& c)
{
    // ..
}

// 임시 객체의 수명은 참조의 수명으로 연장할 수 있습니다.

int main()
{
    Color bg { 10, 20 };
    SetBackgroundColor(bg);

    SetBackgroundColor(Color { 10, 20 });

    // C++에는 임시 객체라는 문법이 존재합니다.
    cout << "------" << endl;
    // Color(10, 20);
    // const Color& r = Color(10, 20);
    cout << "------" << endl;
}
#endif

// 20_객체복사.cpp
#include <iostream>
using namespace std;

// => 복사 정책
//  - 깊은 복사: 복사 생성자
//  - 참조 계수: 복사 생성자
//  - 복사 금지: 복사 생성자 금지

//  - 소유권 이전: 이동 생성자

class User {
    char* name;
    int age;

public:
    // 이동 생성자
    User(User&& rhs)
        : name { rhs.name }
        , age { rhs.age }
    {
        rhs.name = nullptr; // !!!
    }

    User(const User& rhs)
        : age { rhs.age }
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

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

// Move => Rvalue Reference

int main()
{
    User user { "Tom", 42 };

    User other = std::move(user); // lvalue -> rvalue
    other.Print();

    // User other = User { "Tom", 42 }; // 임시 객체를 통해서 객체를 초기화합니다.
    // other.Print();
}
