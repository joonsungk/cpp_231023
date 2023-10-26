
#include <iostream>
using namespace std;

#include "User.h"

void PrintUser(User user)
{
    cout << user.name << ", " << user.age << endl;
    // cout << user.GetName() << ", " << user.GetAge() << endl;
}
