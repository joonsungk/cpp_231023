// 19_복사생성자4.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample&) { cout << "Sample(const Sample&)" << endl; }

    // C++11, Move Constructor
    // => 복사를 수행하지 않고, 메모리를 재사용합니다.
    // Sample(Sample&&) { cout << "Sample(Sample&&)" << endl; }
};

#if 0
Sample& foo()
{
    Sample s;
    return s; /* 미정의 동작: 사라지는 메모리에 대한 참조를 반환하기 때문에, 미정의 동작입니다. */
}
#endif

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

Sample foo()
{
    Sample s;
    return s;
}

// g++ 19_복사생성자4.cpp -fno-elide-constructors -std=c++98
/*
Sample() // Sample a;

Sample() // foo: Sample s;
Sample(const Sample&) // 반환값으로 전달된 객체가 a로 복사
~Sample() // foo: s 객체 파괴, ~Sample()

~Sample() // 반환용 객체 파괴
~Sample() // main: a객체 파괴
*/

// g++ 19_복사생성자4.cpp -fno-elide-constructors -std=c++11
// : C++11부터 임시 객체(rvalue)를 복사하지 않고, 이동합니다.
// => 반드시 이동 생성자(Sample(Sample&&))가 제공되어야만 처리됩니다.
//  : 복사를 통해 처리할지 이동을 통해 처리할지는 이동 생성자 여부에 의해 결정됩니다.

/*
Sample()
Sample(Sample&&)
~Sample()
Sample(Sample&&)
~Sample()
~Sample()
*/

// g++ 19_복사생성자4.cpp -fno-elide-constructors -std=c++17
// : 복사(이동)을 수행하는 것이 컴파일 최적화에 의해 수행되었다면,
//   C++17부터는 문법이 되었습니다.
// => 생략은 무조건 처리됩니다.
//  : 복사를 통해 처리할지 이동을 통해 처리할지는 이동 생성자 여부에 의해 결정됩니다.

/*
Sample()
Sample(Sample&&)
~Sample()
~Sample()
*/
#if 0
int main()
{
    Sample a = foo();
}
#endif
