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

#if 0
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

// Sample s;

int main()
{
    Sample* p = new Sample;

    // delete p;
    p->Destroy(); // Sample::Destroy(p);
}
#endif

#if 0
int main()
{
    // Sample s; // Sample()
} // ~Sample();
#endif

#include <string>

#if 0
// 아래 클래스의 수명을 참조 계수 기반으로 관리하고 싶습니다.
class Image {
    string url;

    int ref;

    ~Image()
    {
        cout << "Image 객체 파괴" << endl;
    }

public:
    Image(const string& s)
        : url { s }
        , ref(1)
    {
    }

    void AddRef() { ++ref; }
    void Release()
    {
        if (--ref == 0) {
            delete this;
        }
    }

    void Draw() const { cout << "Draw Image: " << url << endl; }
};

int main()
{
    Image* p1 = new Image("https://a.com/a.jpg"); // 1

    Image* p2 = p1; // 규칙: 포인터를 복사하면, 참조 계수 증가
    p2->AddRef(); // 2

    p1->Draw();
    p2->Draw();

    // 규칙: 포인터를 더이상 사용하지 않으면, 참조 계수 감소
    p1->Release(); // 2 -> 1
    p2->Release(); // 1 -> 0
}
#endif

class RefBase {
    int ref;

public:
    virtual ~RefBase() { }

    RefBase()
        : ref { 1 }
    {
    }

    void AddRef() { ++ref; }
    void Release()
    {
        if (--ref == 0) {
            delete this;
        }
    }
};

class Image : public RefBase {
    string url;

    ~Image()
    {
        cout << "Image 객체 파괴" << endl;
    }

public:
    Image(const string& s)
        : url { s }
    {
    }

    void Draw() const { cout << "Draw Image: " << url << endl; }
};

template <typename TYPE>
class Ptr {
    TYPE* obj;

public:
    Ptr(TYPE* p = nullptr)
        : obj { p }
    {
    }

    Ptr(const Ptr& rhs)
        : obj { rhs.obj }
    {
        obj->AddRef(); // 복사할 때 참조 계수 증가
    }

    ~Ptr()
    {
        obj->Release(); // 파괴될 때, 참조 계수 감소
    }

    TYPE& operator*() { return *obj; }
    TYPE* operator->() { return obj; }
};

int main()
{
    Ptr<Image> p1 = new Image("https://a.com/a.jpg");
    Ptr<Image> p2 = p1;

    p1->Draw();
    p2->Draw();
}

#if 0
int main()
{
    Image* p1 = new Image("https://a.com/a.jpg"); // 1

    Image* p2 = p1; // 규칙: 포인터를 복사하면, 참조 계수 증가
    p2->AddRef(); // 2

    p1->Draw();
    p2->Draw();

    // 규칙: 포인터를 더이상 사용하지 않으면, 참조 계수 감소
    p1->Release(); // 2 -> 1
    p2->Release(); // 1 -> 0
}
#endif
