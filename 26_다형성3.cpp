// 26_다형성3.cpp
#include <iostream>
using namespace std;

#include <vector>

#if 0
class Dog { };
class Cat { };

int main()
{
    vector<Dog*> dogs;
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);
    // dogs.push_back(new Cat); /* Error */

    vector<Cat*> cats;
    cats.push_back(new Cat);
    cats.push_back(new Cat);
    cats.push_back(new Cat);
}
#endif

// 활용 2 - 동종을 보관하는 컨테이너를 사용할 수 있습니다.
#if 1
class Animal { };
class Dog : public Animal { };
class Cat : public Animal { };

int main()
{
    vector<Animal*> animals;

    animals.push_back(new Dog);
    animals.push_back(new Cat);
    animals.push_back(new Dog);
    animals.push_back(new Cat);
}
#endif

#if 0
int main()
{
    int x[3] = { 10, 20, 30 }; // 고정 배열

    vector<int> v = { 10, 20, 30 }; // 동적 배열
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);

    cout << v[1] << endl;
    cout << v[2] << endl;
    v[0] = 1000;

    for (auto e : v) {
        cout << e << endl;
    }
}
#endif
