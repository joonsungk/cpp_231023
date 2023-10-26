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
#if 1
class Derived : private Base {
};
#endif

int main()
{
    Derived d;
    // d.f2();
    // d.f3();
}
