// 31_예외2.pp
#include <iostream>
using namespace std;

// 1. 예외의 종류에 따라서, 예외의 타입을 제공해야 합니다.
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
        foo("");
    } catch (const InvalidFileNameException& e) {
        cout << "잘못된 파일명 입니다." << endl;
    } catch (const OutOfMemoryException& e) {
        cout << "메모리가 부족합니다." << endl;
    }
}
