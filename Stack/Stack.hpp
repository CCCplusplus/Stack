#pragma once
#include "ArrayA.hpp" 

template<typename T>
class Stack
{
private:
    ArrayA<T> _array;
    int _top;

public:
    Stack(int size, int growBy = 1) : _array(size, growBy), _top(-1)
    {

    }

    ~Stack()
    {
        _top = -1;
    }

    void Push(T val)
    {
        _array.Push(val);
        _top++;
    }

    void Pop()
    {
        if (!IsEmpty())
        {
            _array.Pop();
            _top--;
        }
    }


    const T& Top()
    {
        assert(_top >= 0);
        return _array[_top];
    }

    int IsEmpty() { return (_top == -1); }
    int isFull() { return (_top == _array.GetMaxSize() - 1); }
};

