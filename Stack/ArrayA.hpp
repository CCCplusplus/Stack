#pragma once
#include <iostream>
#include <cassert>
#include <cstdlib>  
#include <ctime> 

template <class T>
class ArrayA
{
private:
    T* m_array;
    int _maxSize;
    int _numelemts;
    int _growSize;

public:
    ArrayA(int size, int growBy = 1) : m_array(NULL), _maxSize(0), _growSize(0), _numelemts(0)
    {
        if (size)
        {
            _maxSize = size;
            m_array = new T[_maxSize];
            memset(m_array, 0, sizeof(T) * _maxSize);
            _growSize = ((growBy > 0) ? growBy : 0);
        }
        srand(time(NULL));
    }

    ~ArrayA()
    {
        if (m_array != NULL)
        {
            delete[] m_array;
            m_array = NULL;
        }
    }

    virtual void Push(T val)
    {
        assert(m_array != NULL);
        if (_numelemts >= _maxSize)
        {
            Expand();
        }
        m_array[_numelemts] = val;
        _numelemts++;
        for (int i = 0; i < _numelemts; ++i) {
            std::cout << m_array[i] << " ";
        }
        std::cout << std::endl;
    }

    void Pop()
    {
        if (_numelemts > 0)
            _numelemts--;
    }


    void Remove(int index)
    {
        assert(m_array != NULL);
        if (index >= _maxSize)
            return;
        for (int i = index; i < _maxSize - 1; i++)
        {
            m_array[i] = m_array[i + 1];
        }
        _numelemts--;
        if (_numelemts >= _maxSize)
            _numelemts = _maxSize - 1;
    }

    virtual T& operator[] (int index)
    {
        return m_array[index];
    }

    bool Expand()
    {
        if (_growSize <= 0)
        {
            return false;
        }
        T* temp = new T[_maxSize + _growSize];
        memcpy(temp, m_array, sizeof(T) * _maxSize);
        delete[] m_array;
        m_array = temp;
        _maxSize += _growSize;
        return true;
    }

    virtual int search(T searchkey)
    {
        if (!m_array)
            return -1;
        int lowerBound = 0;
        int upperBound = _numelemts - 1;
        int current = 0;

        while (1)
        {
            current = (lowerBound + upperBound) >> 1;
            if (m_array[current] == searchkey)
                return current;
            else if (lowerBound > upperBound)
                return -1;
            else
            {
                if (m_array[current] < searchkey)
                    lowerBound = current + 1;
                else
                    upperBound = current - 1;
            }
        }
        return -1;
    }

    void Clear() { _numelemts = 0; }

    int GetSize() { return _numelemts; }

    int GetMaxSize() { return _maxSize; }

    int GetGrowSize() { return _growSize; }

    void SetGrowSize(int val) { _growSize = val; }
};
