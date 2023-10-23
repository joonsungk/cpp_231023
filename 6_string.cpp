// 6_string.cpp
#include <iostream>
using namespace std;

#include <cstring> // string.h

// 문자열
// : '\0' 문자로 종료되는 char 배열

// C의 문자열 문제점
// 1) 문자열의 기본적인 연산을 라이브러리 함수를 통해서 수행해야 합니다.
//   strcmp
//   strcpy
//   strcat ...
// 2) 문자열 연산을 수행할 때, 메모리를 직접 관리해야 합니다.
#if 0
int main()
{
    char str1[32] = "hello";
    const char* str2 = "hello";

    if (strcmp(str1, str2) == 0) {
        std::cout << "같은 문자열" << std::endl;
    }

    char str3[32];
    strcpy(str3, str1);
    std::cout << str3 << std::endl;

    strcat(str3, " world");
    std::cout << str3 << std::endl;
}
#endif

// C++ 문자열
#include <string> // std::string

// 1) 문자열의 기본적인 비교/복사/연결 등의 작업을 연산자를 통해서
//    수행할 수 있습니다.
// 2) 문자열 메모리 관리가 자동적으로 수행됩니다.
//    SSO(Simple String Optimization)
//   : 짧은 문자열은 스택을 통해 관리하고, 긴 문자열은 동적 메모리 할당을 통해 수행됩니다.

int main()
{
    std::string s1 = "hello";
    std::string s2 = { "hello" };
    std::string s3("hello");
    std::string s4 { "hello" };

    if (s1 == s2) {
        std::cout << "같은 문자열" << std::endl;
    }

    // std::string s5 = s1;
    // std::string s5 = { s1 };
    // std::string s5(s1);
    std::string s5 { s1 };
    std::cout << s5 << std::endl;

    // s5 = s5 + " world";
    s5 += " world";
    std::cout << s5 << std::endl;
}
