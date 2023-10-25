// 19_복사생성자4.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample&) { cout << "Sample(const Sample&)" << endl; }
};

#if 0
Sample& foo()
{
    Sample s;
    return s;
}
#endif

// 사라지는 메모리에 대한 참조를 반환하기 때문에, 미정의 동작입니다.
Sample foo()
{
    Sample s;
    return s;

    // return Sample();
}

// C++ 컴파일러는 함수가 지역 객체를 값으로 반환할 때,
// 반환용 임시 객체의 복사 생성/제거 비용을 최적화합니다.
// => RVO(Return Value Optimization, 반환값 최적화)
// 1) 반환할 때, 임시 객체를 생성해서 반환해야 합니다.
// 2) 최신 컴파일러는 임시 객체가 아닌, 일반적인 지역 객체도 복사/제거 비용을 최적화합니다.
//   : NRVO(Named RVO)

int main()
{
    cout << "----------" << endl;
    foo();
    cout << "----------" << endl;
}
