// stack.h
#ifndef STACK_H
#define STACK_H

#if 0
class Stack {
    int* buff;
    int top;

public:
    ~Stack()
    {
        delete[] buff;
    }

    Stack(int size)
    {
        top = 0;
        buff = new int[size];
    }

    Stack()
    {
        top = 0;
        buff = new int[10];
    }

    void Push(int n)
    {
        buff[top++] = n;
    }

    int Pop()
    {
        return buff[--top];
    }
};
#endif

class Stack {
    int* buff;
    int top;

public:
    ~Stack();

    Stack(int size);
    Stack();

    void Push(int n);
    int Pop();
};

#endif
