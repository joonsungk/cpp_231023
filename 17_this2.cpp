// 17_this2.cpp
#include <iostream>
using namespace std;

#if 0
class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }
};

int main()
{
    Sample s; // Sample();
} // ~Sample();
#endif

// private 소멸자
//  의도 - 지역 객체와 전역 객체를 생성할 수 없고, 오직 new를 통해서만 객체를 생성할 수 있습니다.

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }

    // private 소멸자를 사용한 경우, 객체를 파괴하는 방법을 멤버 함수를 통해 제공해야 합니다.
    void Destroy() // void Destroy(Sample* this)
    {
        delete this;
    }

private:
    ~Sample() { cout << "~Sample()" << endl; }
};

Sample s;

int main()
{
    Sample* p = new Sample;

    // delete p;
    p->Destroy(); // Sample::Destroy(p);
}

#if 0
int main()
{
    // Sample s; // Sample()
} // ~Sample();
#endif
