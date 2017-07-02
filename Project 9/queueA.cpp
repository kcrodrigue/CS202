#include "queueA.h"

queueA::queueA(int input)
{
    max = input;
    front = 0;
    rear = -1;
    data = new int[input];
}

queueA::queueA(const queueA& copy)
{
    max = copy.max;
    front = copy.front;
    rear = copy.rear;
    data = new int[max];

    for(int i = 0; i <= max; i++)
    {
        data[i] = copy.data[i];
    }
}

queueA::~queueA()
{
    if(data != NULL)
    {
        delete data;
        data = NULL;
    }
}

queueA& queueA::operator=(const queueA& rhs)
{
    max = rhs.max;
    front = rhs.front;
    rear = rhs.rear;
    data = new int[max];

    for(int i = 0; i <= max; i++)
    {
        data[i] = rhs.data[i];
    }

    return *this;
}

bool queueA::enqueue(int input)
{
    bool valid = false;

    if(rear < max-1)
    {
        rear++;
        data[rear] = input;
        valid = true;
    }

    return valid;
}

bool queueA::dequeue()
{
    bool valid = false;

    if(rear > 0)
    {
        valid = true;
        for(int i = 0; i < rear; i++)
        {
            data[i] = data[i+1];
        }
        rear--;
    }

    return valid;
}

int queueA::getFront()
{
    int return_num = 0;

    if(data != NULL)
    {
        return_num = data[front];
    }

    return return_num;
}

bool queueA::empty() const
{
    bool empty = false;

    if(rear < 0)
    {
        empty = true;
    }

    return empty;
}

bool queueA::full() const
{
    bool full = false;

    if(rear == max-1)
    {
        full = true;
    }

    return full;
}

bool queueA::clear()
{
    bool valid = false;

    if(rear >= 0)
    {
        valid = true;
        rear = -1;
    }

    return valid;
}

bool queueA::operator==(const queueA& rhs) const
{
    bool match = true;

    if(front == rhs.front && rear == rhs.rear && max == rhs.max)
    {
        for(int i = 0; i < max; i++)
        {
            if(data[i] != rhs.data[i])
            {
                match = false;
            }
        }
    }
    else
    {
        match = false;
    }

    return match;
}

ostream& operator<<(ostream& cout, const queueA& output)
{
    for(int i = 0; i <= output.rear; i++)
    {
        cout << output.data[i] << " " ;
    }

    cout << endl;

    return cout;
}
