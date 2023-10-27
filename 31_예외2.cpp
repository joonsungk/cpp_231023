// 31_예외2.pp
#include <iostream>
using namespace std;

// 1. 예외의 종류에 따라서, 예외의 타입을 제공해야 합니다.
#if 0
class InvalidFileNameException { };
class OutOfMemoryException { };

int foo(const string& filename)
{
    if (filename == "") {
        throw InvalidFileNameException();
        // 임시 객체를 던지면 됩니다.
    }

    // ..
    throw OutOfMemoryException();

    // 성공
    return 0;
}

int main()
{
    try {
        foo("123");
        cout << "foo 성공" << endl;

    } catch (const InvalidFileNameException& e) {
        cout << "잘못된 파일명 입니다." << endl;
    } catch (const OutOfMemoryException& e) {
        cout << "메모리가 부족합니다." << endl;
    }
}
#endif

#if 1
// 2. std::exception 기반으로 what을 통해 오류 메세지를 정의할 수 있습니다.
class InvalidFileNameException : public std::exception {
public:
    // noexcept: C++11, 해당 함수가 예외를 발생시키지 않는다는 사실을 컴파일러에게 알려줍니다.
    const char* what() const noexcept override
    {
        return "잘못된 파일명입니다.";
    }
};
class OutOfMemoryException : public std::exception {
public:
    const char* what() const noexcept override
    {
        return "메모리가 부족합니다.";
    }
};

int foo(const string& filename)
{
    if (filename == "") {
        throw InvalidFileNameException();
        // 임시 객체를 던지면 됩니다.
    }

    // ..
    // throw OutOfMemoryException();

    // 성공
    return 0;
}

int main()
{
    try {
        foo("");
        cout << "foo 성공" << endl;

    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    try {
        foo("123");
        cout << "foo 성공" << endl;

    } catch (const InvalidFileNameException& e) {
        cout << "잘못된 파일명 입니다." << endl;
    } catch (const OutOfMemoryException& e) {
        cout << "메모리가 부족합니다." << endl;
    }
}
#endif

#if 0
// 컴파일러는 예외 처리를 위해서, 스택을 복원하는 기계어 코드를 추가적으로 생성해야 합니다.
void foo()
{
    throw 1;
}

// 컴파일러는 예외 처리를 위한 기계어 코드를 제공하지 않습니다.
// > noexcept로 한정된 함수에서 예외가 발생하면, 예외를 처리할 수 없습니다.
// => 무조건 프로그램이 종료됩니다.

// : 소멸자 / 이동 연산 - noexcept

void goo() noexcept
{
    foo();
}

int main()
{
    try {
        goo();
    } catch (...) {
        cout << "예외 발생" << endl;
    }
}
#endif

#if 0
#include <vector>

class Sample {
public:
    Sample() = default;

    Sample(const Sample& rhs)
    {
        cout << "복사" << endl;
    }

    Sample(Sample&& rhs) noexcept
    {
        cout << "이동" << endl;
    }
};

// STL은 예외를 강력 보장합니다.
// => 예외가 발생해도, 컨테이너의 상태는 망가지지 않습니다.

int main()
{
    vector<Sample> v;
    cout << v.size() << ", " << v.capacity() << endl;

    Sample s;
    v.push_back(s);
    cout << v.size() << ", " << v.capacity() << endl;

    v.push_back(s);
    cout << v.size() << ", " << v.capacity() << endl;

    v.push_back(s);
    cout << v.size() << ", " << v.capacity() << endl;

    v.push_back(s);
    cout << v.size() << ", " << v.capacity() << endl;

    v.push_back(s);
    cout << v.size() << ", " << v.capacity() << endl;
}
#endif
