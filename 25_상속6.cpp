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

#if 1
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
#endif

// 생성자 오버로딩 한계
// 1) 동일한 인자 정보를 가지는 경우, 오버로딩이 불가능합니다.
// 2) 생성자의 사용 형태는 항상 동일하기 때문에,
//    객체 생성이 어떤 정책으로 수행되는지 확인하기 어렵습니다.
// => 정적 팩토리 메소드
//  Factory: 객체 생성 역활

#if 0
class User {
    string id; // email, socialId
public:
    User(const std::string email) { }
    // User(const std::string socialId) { }

    User(int socialId) { }
};

int main()
{
    User user1 { "a@gmail.com" };
    User user2 { 1213123123 };
}
#endif

#if 0
class User {
    string id; // email, socialId

    User(const string& i)
        : id { i }
    {
    }

public:
    static User CreateUserWithEmail(const std::string& email)
    {
        return User(email);
    }

    static User CreateUserWithSocialId(int socialId)
    {
        return User(to_string(socialId));
    }
};

int main()
{
    User user1 = User::CreateUserWithEmail("a@gmail.com");
    User user2 = User::CreateUserWithSocialId(12312321);
}
#endif
