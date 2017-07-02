#include "stackA.h"

stackA::stackA(int size)
{
    max = size;
    top = -1;
    data = new int[max];
}

stackA::stackA(const stackA& copy)
{
    max = copy.max;
    top = copy.top;
    data = new int[max];

    for(int i = 0; i <= max; i++)
    {
        data[i] = copy.data[i];
    }
}

stackA::~stackA()
{
    max = 0;
    top = -1;
    if(data != NULL)
    {
        delete [] data;
        data = NULL;
    }
}

stackA& stackA::operator=(const stackA& rhs)
{
    max = rhs.max;
    top = rhs.top;
    if(data !=NULL)
    {
        delete [] data;
        data = NULL;
    }
    data = new int[max];

    for(int i = 0; i <= max; i++)
    {
        data[i] = rhs.data[i];
    }

    return *this;
}

bool stackA::push(int input)
{
    bool valid = false;

    if(top < max-1)
    {
        valid = true;
        top++;
        data[top] = input;
    }

    return valid;
}

bool stackA::pop()
{
    bool valid = false;

    if(top >= 0)
    {
        valid = true;
        top--;
    }

    return valid;
}

int stackA::getTop()
{
    return data[top];
}

bool stackA::empty() const
{
    bool empty = false;

    if(top < 0)
    {
        empty = true;
    }

    return empty;
}

bool stackA::full() const
{
    bool full = false;

    if(top == max-1)
    {
        full = true;
    }

    return full;
}

bool stackA::clear()
{
    bool valid = false;

    if(!empty())
    {
        valid = true;
        delete [] data;
        top = 0;
        max = 0;
    }

    return valid;
}

bool stackA::operator==(const stackA& rhs) const
{

    if(top != rhs.top || max != rhs.max)
    {
        return false;
    }

    for(int i = 0; i <= top; i++)
    {
        if(data[i] != rhs.data[i])
        {
            return false;
        }
    }

    return true;
}

ostream& operator<<(ostream& cout, const stackA& output)
{
    for(int i = output.top; i >= 0; i--)
    {
        cout << output.data[i] << " " ;
    }
    cout << endl;

    return cout;
}
