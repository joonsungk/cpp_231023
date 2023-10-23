// 1_시작2.cpp
#include <stdio.h> // C 표준 입출력 헤더
#include <iostream> // C++ 표준 입출력 헤더
// - C++의 표준 입출력 헤더 파일은 확장자를 사용하지 않습니다.

#if 0
int main()
{
    std::cout << "Hello, C++" << std::endl;
}
#endif

// 1. printf/scanf는 변수의 타입에 따라서 정확한 서식을 지정해야 합니다.
//    std::cout/std::cin는 변수의 타입에 따라서 자동적으로 처리됩니다.

// 2. std::cin을 사용할 때, 주소를 전달하지 않습니다.

// 3. std::endl

#if 0
int main()
{
    long n = 42;

    scanf("%ld", &n);
    printf("%ld\n", n);
}
#endif

int main()
{
    long n = 42;

    std::cin >> n;

    std::cout << n << std::endl;
}
