#include "listA.h"

List::List(int input_size)
{
    size = input_size;
    actual = 0;
    cursor = 0;
    data = new int[size];

    for(int i = 0; i < size; i++)
    {
        data[i] = 0;
    }
}

List::List(const List& copy)
{
    size = copy.size;
    actual = copy.actual;
    cursor = copy.cursor;

    if(data != NULL)
    {
        delete [] data;
    }

    data = new int[size];

    for(int i = 0; i < size; i++)
    {
        data[i] = copy.data[i];
    }
}

List::~List()
{
    delete [] data;
}

bool List::goToBeginning()
{
    bool valid;

    if(cursor!= 0)
    {
        cursor = 0;
        valid = true;
    }

    else
    {
        valid = false;
    }

    return valid;
}

bool List::goToEnd()
{
    bool valid;

    if(cursor!= size-1)
    {
        cursor = size-1;
        valid = true;
    }

    else
    {
        valid = false;
    }

    return valid;
}

bool List::goToNext()
{
    bool valid;

    if(cursor < size-1)
    {
        cursor++;
        valid = true;
    }

    else
    {
        valid = false;
    }

    return valid;
}

bool List::goToPrior()
{
    bool valid;

    if(cursor > 0)
    {
        cursor--;
        valid = true;
    }

    else
    {
        valid = false;
    }

    return valid;
}

bool List::insertBefore(int input)
{
    bool valid;

    if(cursor!= 0 && actual < size-1)
    {
        for(int i = actual; i >= cursor-1; i--)
        {
            data[i+1] = data[i];
        }
        data[cursor-1] = input;
        valid = true;
    }

    else
    {
        valid = false;
    }

    return valid;
}

bool List::insertAfter(int input)
{
    bool valid;

    if(actual < size-1)
    {
        for(int i = actual; i >= cursor+1; i--)
        {
            data[i+1] = data[i];
        }
        data[cursor+1] = input;
        valid = true;
    }

    else
    {
        valid = false;
    }

    return valid;
}

bool List::remove()
{
    bool valid;

    if(cursor < actual)
    {
        for(int i = cursor; i < actual; i++)
        {
            data[i] = data[i+1];
        }
        valid = true;
    }
    else
    {
        valid = false;
    }

    return valid;
}

bool List::isEmpty() const
{
    bool empty = true;

    if(actual > 0 )
    {
        empty = false;
    }

    return empty;
}

bool List::isFull() const
{
    bool full = true;

    if(actual < size )
    {
        full = false;
    }

    return full;
}

void List::clear()
{
    if(actual != 0)
    {
        for(int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
        actual  = 0;
        cursor = 0;
    }

}

List& List::operator =(const List& rhs)
{
    delete[] data;
    size = rhs.size;
    actual = rhs.size;
    cursor = rhs.cursor;
    data = new int[size];
    for(int i = 0; i < actual; i++)
    {
        data[i] = rhs.data[i];
    }

    return *this;
}

ostream& operator<<(ostream & cout, const List& output)
{
    for(int i = 0; i < output.actual; i++)
    {
        if(i = output.cursor)
        {
            cout << "[" << output.data[output.cursor] << "] ";
        }
        else
        {
            cout << output.data[i] << " ";
        }
    }

    return cout;
}
