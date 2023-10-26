// 29_접근변경자2.cpp
#include <iostream>
using namespace std;

class Base {
private:
    void f1() { }

protected:
    void f2() { }

public:
    void f3() { }
};

// class Derived : public Base {
//                 ------
//                접근 변경자
//---------------------------------
// 부모 클래스의 private은 자식 클래스가 접근할 수 없습니다.

// <부모 클래스>            <자식 클래스>
//           public 상속
// protected     --->      protected
// public                  public
#if 0
class Derived : public Base {
};
#endif

// <부모 클래스>            <자식 클래스>
//           protected 상속
// protected     --->      protected
// public                  protected
#if 0
class Derived : protected Base {
};
#endif

// <부모 클래스>            <자식 클래스>
//           private 상속
// protected     --->      private
// public                  private
#if 0
class Derived : private Base {
};

int main()
{
    Derived d;
    // d.f2();
    // d.f3();
}
#endif

//-----
#include <string>

class User {
    string name;

protected:
    string GetName() const { return name; }

public:
    virtual ~User() { }
};

class SuperUser : public User {
    // 부모가 제공하는 protected를 public으로 변경할 수 있습니다.
public:
    // string GetName() const { return User::GetName(); }

    using User::GetName;
    // 부모의 protected를 public으로 변경합니다.
};

int main()
{
    SuperUser user;
    user.GetName();
}
