#include "queueN.h"

NodeQ::NodeQ(int input, NodeQ* point_to)
{
    data = input;
    next = point_to;
}

queueN::queueN()
{
    front = NULL;
    rear = NULL;
}

queueN::queueN(const queueN& copy)
{
    NodeQ *temp, *copy_temp;
    temp = front;
    copy_temp = copy.front;

    temp = new NodeQ(copy.front->data, NULL);
    copy_temp = copy_temp->next;
    front = temp;

    while(copy_temp != NULL && temp != NULL)
    {
        temp->next = new NodeQ(copy_temp->data, NULL);
        rear = temp;
        copy_temp = copy_temp->next;
        temp = temp->next;
    }

    temp = NULL;
    copy_temp = NULL;
}

queueN::~queueN()
{
    NodeQ* temp;

    temp = front;

    while(front != NULL)
    {
        front = front->next;
        delete temp;
        temp = front;
    }

    rear = NULL;
}

queueN& queueN::operator=(const queueN& rhs)
{
    NodeQ *temp, *copy_temp;

    front = rhs.front;

    temp = front;
    copy_temp = rhs.front;

    while(copy_temp!= NULL)
    {
        temp->next = copy_temp->next;
        temp->data = copy_temp->data;


        temp = temp->next;
        copy_temp = copy_temp->next;
    }

    rear = temp;

    temp = NULL;
    copy_temp = NULL;

    return *this;
}

bool queueN::enqueue(int input)
{
    if(empty())
    {
        rear = new NodeQ(input, NULL);
        front = rear;
    }
    else
    {
        rear->next = new NodeQ(input, NULL);
        rear = rear->next;
    }

    return true; //never fail
}

bool queueN::dequeue()
{
    bool valid = false;
    NodeQ* temp = front;

    if(!empty())
    {
        valid = true;
        front = front->next;
        temp->next = NULL;
        delete temp;
    }

    temp = NULL;

    return valid;
}

int queueN::getFront()
{
    int front_data = 0;

    if(front != NULL)
    {
        front_data = front->data;
    }

    return front_data;
}

bool queueN::empty() const
{
    bool empty = false;

    if(front == NULL)
    {
        empty = true;
    }

    return empty;
}

bool queueN::full() const
{
    return false; // never full
}

bool queueN::clear()
{
    bool valid = false;
    NodeQ* temp = front;

    if(front !=NULL)
    {
        while(front != NULL)
        {
            front = front->next;
            delete temp;
            temp = front;
        }
        valid = true;
    }

    temp = NULL;

    return valid;
}

bool queueN::operator==(const queueN& rhs) const
{
    bool match = true;
    NodeQ *temp, *rhs_temp;

    temp = front;
    rhs_temp = rhs.front;

    while(temp != NULL && rhs_temp != NULL)
    {
        if(temp->data != rhs_temp->data)
        {
            match = false;
            break;
        }
        temp = temp->next;
        rhs_temp = rhs_temp->next;
    }

    if((temp == NULL && rhs_temp !=NULL) || (temp != NULL && rhs_temp == NULL))
    {
        match = false;
    }

    return match;
}

ostream& operator<<(ostream& cout, const queueN& output)
{
    NodeQ* temp;

    temp = output.front;

    while(temp != NULL)
    {
        cout << temp->data << " " ;
        temp = temp->next;
    }
    cout << endl;

    return cout;
}
