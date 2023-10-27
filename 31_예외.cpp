// 31_예외.cpp
#include <iostream>
using namespace std;

// 함수의 실패 여부를 반환값을 통해서 처리하는 경우가 많습니다.
//  : atoi
//  => 실패와 성공을 구분하기 모호합니다.
// 원인: 성공과 실패를 모두 return을 통해 전달합니다.
#if 0
int main()
{
    int n = atoi("42");
    cout << n << endl;

    n = atoi("0");
    cout << n << endl;

    n = atoi("aklsjdlkjasdklalsdkj");
    cout << n << endl;
}
#endif

// 실패 가능성이 있는 함수는 반드시 오류 체크를 통해 더 이상 실행될지 말지를 판단해야 합니다.
//  문제점: 오류 체크가 강제되지 않습니다.
#if 0
int Process()
{
    // 실패할 경우, -1을 반환합니다.
    return -1;
}

int main()
{
    Process();
}
#endif

// C++은 예외(Exception)라는 오류 처리 방법을 제공하고 있습니다.
// 1) 성공은 return 하고, 실패는 throw 합니다.
// 2) 예외가 발생하였을 때, 예외를 처리하지 않으면 프로그램이 비정상 종료(abort)됩니다.

// 3) 예외 발생 가능성이 존재하는 함수를 사용할 때,
//    try{} catch{}를 통해서 오류를 처리할 수 있습니다.

int foo(const string& filename)
{
    if (filename == "") {
        // return -1; // 실패
        // throw -1;
        // throw 3.14;
        throw 'A';
    }

    // 성공
    return 0;
}

int main()
{
    // foo("xxx");
    try {
        foo("");
    } catch (const int& e) {
        cout << e << endl;
    } catch (const double& e) {
        cout << e << endl;
    } catch (...) { // 처리되지 않은 모든 예외 타입을 처리합니다.
        cout << "알수 없는 오류" << endl;
    }

    cout << "성공" << endl;
}
