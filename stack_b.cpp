#include <iostream>
#include <stdexcept>
#include "stack_b.h"
using namespace std;

Stack_B::Stack_B()
{
    size = 0;
    capacity = 1024;
    try
    {
        stk = new int[capacity];
    }
    catch (bad_alloc &e)
    {
        throw runtime_error("Out of Memory");
    }
}

Stack_B::~Stack_B()
{
    delete[] stk;
}

void Stack_B::push(int data)
{
    if (size >= capacity)
    {   
        capacity*=2;
        int *temp;
        try
        {
            temp = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                temp[i] = stk[i];
            }
            delete[] stk;
            stk = temp;
            size++;
            stk[size-1] = data;
        }
        catch (bad_alloc&e)
        {
            throw runtime_error("Out of Memory");
        }
        // int *temp = new int[2 * capacity];
    }
    else
    {
        stk[size] = data;
        size++;
    }
}

int Stack_B::pop()
{
    if (size <= 0)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        if (size <= capacity / 4 && capacity >=2048)
        {
            int *temp;
            try
            {
                temp = new int[capacity / 2];
                capacity /= 2;
                for (int i = 0; i < size; i++)
                {
                    temp[i] = stk[i];
                }
                delete[] stk;
                stk = temp;
            }
            catch (bad_alloc&e)
            {
                throw runtime_error("Out of Memory");
            }
            // int *temp = new int[capacity / 4];
        }
        size--;
        return stk[size];
    }
}

int Stack_B::get_element_from_top(int idx)
{
    if ((size -idx) < 1||idx<0)
    {
        throw runtime_error("Index out of Storage");
    }
    else
    {
        return stk[size - 1 - idx];
    }
}

int Stack_B::get_element_from_bottom(int idx)
{
    if ((idx) >= size||idx<0)
    {
        throw runtime_error("Index out of Storage");
    }
    else
    {
        return stk[idx];
    }
}

void Stack_B::print_stack(bool top_or_bottom)
{
    if (top_or_bottom!=0)
    {
        for (int i = size - 1; i > -1; i--)
        {
            cout << stk[i] << endl;
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << stk[i] << endl;
        }
    }
}

int Stack_B::add()
{
    if (size <= 1)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        stk[size - 2] += stk[size - 1];
        size--;
        return stk[size - 1];
    }
}

int Stack_B::subtract()
{
    if (size <= 1)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        stk[size - 2] -= stk[size - 1];
        size--;
        return stk[size - 1];
    }
}

int Stack_B::multiply()
{
    if (size <= 1)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        stk[size - 2] *= stk[size - 1];
        size--;
        return stk[size - 1];
    }
}

int Stack_B::divide()
{
    if (size <= 1)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else if (stk[size - 1] == 0)
    {
        size -= 2;
        throw runtime_error("Divide by Zero Error");
    }
    else
    {
        if (stk[size - 2] * stk[size - 1] < 0)
        {
            stk[size - 2] = stk[size - 2] / stk[size - 1];
            stk[size - 2] -= 1;
            size--;
            return stk[size - 1];
        }
        stk[size - 2] = stk[size-2]/stk[size - 1];
        size--;
        return stk[size - 1];
    }
}

int *Stack_B::get_stack()
{
    return stk;
}

int Stack_B::get_size()
{
    return size;
}