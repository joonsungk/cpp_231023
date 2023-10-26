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
