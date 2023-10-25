// 11_동적메모리할당.cpp
#include <iostream>
using namespace std;

#include <cstdlib> // stdlib.h
// malloc, free
//  void* malloc(size_t size);
//  void free(void* p);
// => 표준 라이브러리 함수를 통해 동적으로 메모리를 할당하고 해지할 수 있습니다.

// 1. C++은 동적 메모리할당을 연산자를 통해서 제공합니다.
//   new / delete

// 2. malloc은 메모리의 크기를 인자로 전달받지만,
//    new는 타입을 전달받습니다.

// 3. malloc은 void*를 반환하지만,
//    new는 전달받은 타입의 주소 타입을 반환합니다.
//    => 명시적인 캐스팅이 필요하지 않습니다.

// 4. 연속된 메모리를 할당할 때는 new T[count] 형태로, 해지는 delete[] p; 를 사용해야 합니다.

#if 0
int main()
{
    int* p = static_cast<int*>(malloc(sizeof(int)));
    // C++에서는 명시적인 캐스팅이 필요합니다.
    *p = 42;

    free(p);
    p = NULL;

    free(p); // 전달받은 메모리가 NULL일 경우, 아무일도 수행하지 않습니다.
}
#endif

#if 0
int main()
{
    int* p = new int;

    delete p;
    p = NULL;

    delete p; // NULL이 전달될 경우, 아무일도 수행하지 않습니다.
}
#endif

#if 0
int main()
{
    int* p = static_cast<int*>(malloc(sizeof(int) * 100)); // 400 byte
    free(p);

    int* p2 = new int[100]; // 연속된 메모리를 할당할 수 있습니다.

    // 연속된 메모리를 해지할 때, 반드시 delete[] 를 통해 해지해야 합니다.
    delete[] p2; // 주의!
}
#endif

int main()
{
    int* p = static_cast<int*>(malloc(sizeof(int)));
    // 할당된 메모리는 쓰레기값을 가집니다.
    // => calloc을 이용해서, 할당후 0으로 초기화할 수 있습니다.
    free(p);

    // new는 초기화를 수행할 수 있습니다.
    // int* p2 = new int(42);
    int* p2 = new int { 42 };
    cout << *p2 << endl;

    delete p2;

    int* p3 = new int[3] { 10, 20, 30 };
    for (int i = 0; i < 3; ++i) {
        cout << p3[i] << endl;
    }

    delete[] p3;
}
