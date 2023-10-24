// stack.cpp
#include "stack.h"

Stack::~Stack()
{
    delete[] buff;
}

Stack::Stack(int size)
{
    top = 0;
    buff = new int[size];
}

Stack::Stack()
{
    top = 0;
    buff = new int[10];
}

void Stack::Push(int n)
{
    buff[top++] = n;
}

int Stack::Pop()
{
    return buff[--top];
}
