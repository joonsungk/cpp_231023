#include <string>

class User {
    std::string name;
    int age;

public:
    User(std::string s, int n)
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
