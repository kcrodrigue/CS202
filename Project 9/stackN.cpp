#include "stackN.h"

NodeS::NodeS(int input, NodeS* point_to)
{
    data = input;
    next = point_to;
}

stackN::stackN()
{
    top = NULL;
}

stackN::stackN(const stackN& copy)
{
    NodeS *temp, *copy_temp;
    temp = top;
    copy_temp = copy.top;

    temp = new NodeS(copy.top->data, NULL);
    copy_temp = copy_temp->next;
    top = temp;

    while(copy_temp != NULL && temp != NULL)
    {
        temp->next = new NodeS(copy_temp->data, NULL);
        copy_temp = copy_temp->next;
        temp = temp->next;
    }

    temp = NULL;
    copy_temp = NULL;
}

stackN::~stackN()
{
    clear();
}

stackN& stackN::operator=(const stackN& rhs)
{
    NodeS *temp, *rhs_temp;
    temp = top;
    rhs_temp = rhs.top;

    temp = new NodeS(rhs_temp->data, NULL);
    rhs_temp = rhs_temp->next;
    top = temp;

    while(rhs_temp != NULL && temp != NULL)
    {
        temp->next = new NodeS(rhs_temp->data, NULL);
        rhs_temp = rhs_temp->next;
        temp = temp->next;
    }

    temp = NULL;
    rhs_temp = NULL;

    return *this;
}

bool stackN::push(int input)
{
    NodeS *temp = new NodeS(input, top);

    top = temp;

    temp = NULL;

    return true;
}

bool stackN::pop()
{
    bool valid = false;
    NodeS* temp = top;

    if(!empty())
    {
        valid = true;
        top = top->next;
        delete temp;
    }

    temp = NULL;

    return valid;
}

int stackN::getTop()
{
    int top_num = 0;

    if(!empty())
    {
        top_num = top->data;
    }

    return top_num;
}

bool stackN::empty() const
{
    bool empty = false;

    if(top == NULL)
    {
        empty = true;
    }

    return empty;
}

bool stackN::full() const
{
    return false; // never empty
}

bool stackN::clear()
{
    NodeS* temp = top;
    bool valid = false;

    if(!empty())
    {
        valid = true;
        while(top != NULL)
        {
            top = top->next;
            delete temp;
            temp = top;
        }
    }

    return valid;
}

bool stackN::operator==(const stackN& rhs) const
{
    NodeS *temp, *rhs_temp;
    bool match = true;

    temp = top;
    rhs_temp = rhs.top;

    while(temp != NULL && rhs_temp != NULL)
    {
        if(temp->data != rhs_temp->data)
        {
            match = false;
        }
        temp=temp->next;
        rhs_temp = rhs_temp->next;
    }

    if(temp != rhs_temp)
    {
        match = false;
    }

    temp = NULL;
    rhs_temp = NULL;

    return match;
}

ostream& operator<<(ostream& cout, const stackN& output)
{
    NodeS* temp;

    temp = output.top;

    cout << "top-> " ;
    while(temp != NULL)
    {
        cout << temp->data << " " ;
        temp = temp->next;
    }
    cout << endl;

    return cout;
}
