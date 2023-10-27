// 32_연산자오버로딩6.cpp
#include <iostream>
using namespace std;

class Image {
public:
    Image() { cout << "Image()" << endl; }
    ~Image() { cout << "~Image()" << endl; }

    void Draw() const { cout << "Draw Image" << endl; }
};

// Image* 역활을 수행하는 클래스입니다.
// => 스마트 포인터(Smart Pointer)
#if 0
class Ptr {
    Image* obj;

public:
    Ptr(Image* p = nullptr)
        : obj { p }
    {
    }

    ~Ptr() { delete obj; }

    // 포인터의 역활을 수행하는 연산자 오버로딩을 제공합니다.
    Image& operator*() { return *obj; }
    Image* operator->() { return obj; }
};
#endif

template <typename TYPE>
class Ptr {
    TYPE* obj;

public:
    Ptr(TYPE* p = nullptr)
        : obj { p }
    {
    }

    ~Ptr() { delete obj; }

    // 포인터의 역활을 수행하는 연산자 오버로딩을 제공합니다.
    TYPE& operator*() { return *obj; }
    TYPE* operator->() { return obj; }
};

#if 0
int main()
{
    Ptr<Image> p = new Image;

    (*p).Draw();
    // p.operator*().Draw();

    p->Draw();
    // p.operator->()Draw();
    // => p.operator->()->Draw();
}
#endif

#if 0
int main()
{
    Image* p = new Image;

    p->Draw();
    (*p).Draw();

    delete p;
}
#endif

// 표준 라이브러리에 스마트 포인터가 제공됩니다.
#include <memory>

// auto_ptr: 기존에 제공되던 스마트 포인터지만, 이제는 사용되지 않습니다.

// C++11에서 아래 클래스가 제공됩니다.
// 1. shared_ptr: 소유권 공유
// 2. unique_ptr: 소유권 독점
#if 0
int main()
{
    shared_ptr<Image> p1 { new Image };
    shared_ptr<Image> p2 = p1; // 참조 계수 증가

    p1->Draw();
    (*p1).Draw();

    p1 = nullptr; // 참조 계수 감소
    p2 = nullptr; // 참조 계수 감소 -> 0 -> 객체 파괴
}

#endif

int main()
{
    unique_ptr<Image> p1 { new Image };

    // unique_ptr<Image> p2 = p1; /* 에러!, 복사 금지 */
    p1->Draw();
    (*p1).Draw();

    unique_ptr<Image> p2 = std::move(p1); /* 소유권 이전 가능 */
    // p1은 nullptr이 됩니다.

    p2->Draw();
    (*p2).Draw();
}
