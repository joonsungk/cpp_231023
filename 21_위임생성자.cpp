// 21_위임생성자.cpp
#include <iostream>
using namespace std;

class Color {
    int red;
    int green;
    int blue;

    // 외부에서 호출할 필요가 없고, 클래스 내부에서만 수행되는 멤버 함수는
    // private 영역으로 제공하는 것이 좋습니다.
    void Init1() { cout << "초기화1" << endl; }
    void Init2() { cout << "초기화2" << endl; }

public:
    Color(int r, int g, int b)
        : red { r }
        , green { g }
        , blue { b }
    {
        Init1();
        Init2();
    }

    // C++11, 위임 생성자
    //  정의: 자신의 다른 생성자를 통해 객체를 초기화할 수 있습니다.
    //  "생성자에서 다른 생성자를 호출할 수 있습니다."
    // => 생성자 오버로딩에서 발생하는 코드 중복을 제거할 수 있습니다.
    Color()
        : Color { 0, 0, 0 } // 위임 생성자
    {
    }

#if 0
    Color()
        : red { 0 }
        , green { 0 }
        , blue { 0 }
    {
        Init1();
        Init2();
    }
#endif
};

int main()
{
    Color c { 10, 20, 215 };

    Color x;
}
