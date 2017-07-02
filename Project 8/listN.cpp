#include "listN.h"

Node::Node(int input, Node* point_to)
{
    data = input;
    next = point_to;
}

List::List(int input)
{
    head = new Node(0, head);
    cursor = head;
    for(int i = 1; i < input; i++)
    {
        cursor->next = new Node(0, cursor->next);
        cursor=cursor->next;
    }
    cursor = head;
}

List::List(const List& copy)
{

}

List::~List()
{
    head = NULL;
    cursor = NULL;
}

bool List::goToBeginning()
{
    bool valid = false;

    if(cursor!=head)
    {
        cursor = head;
        valid = true;
    }

    return valid;
}

bool List::goToEnd()
{
    bool valid = false;

    while(cursor->next != NULL && cursor->next != head)
    {
        cursor=cursor->next;
        valid = true;
    }

    return valid;
}

bool List::goToNext()
{
    bool valid = false;

    if(cursor->next != NULL && cursor->next != head)
    {
        cursor=cursor->next;
        valid = true;
    }

    return valid;
}

bool List::goToPrior()
{
    bool valid = false;
    Node* test;

    test = head;

    while(test->next != NULL && test->next != cursor)
    {
        test=test->next;
        valid = true;
    }

    cursor = test;

    return valid;
}

bool List::insertBefore(int input)
{
    bool valid = false;
    Node* test;
    Node insert_node(input, cursor);

    test = cursor;

    if(cursor!=head)
    {
        while(test->next->next != cursor)
        {
            test=test->next;
        }
        *(test->next) = insert_node;
        valid = true;
    }

    return valid;
}

bool List::insertAfter(int input)
{
    Node insert_node(input, cursor->next);

    return true;
}

bool List::remove()
{
    Node* test;
    while(test->next != cursor)
    {
        test=test->next;
    }
    test->next = cursor->next;

    cursor = test->next;
}

bool List::isEmpty() const
{
    bool empty = false;
    if(head->next = head)
    {
        empty = true;
    }
    return empty;
}

bool List::isFull () const
{
    return false; //linked lists are never full
}

void List::clear()
{
    if(head!= NULL)
    {
        head = NULL;
    }
    
    if(cursor!= NULL)
    {
        cursor = NULL;
    }
}

List& List::operator=(const List& rhs)
{
    return *this;
}

ostream& operator<<(ostream&, const List& output)
{
    Node *ptr=output.head;

    while(ptr->next != output.head)
    {
        if(ptr = output.cursor)
        {
            cout << "[" << ptr->data << "] " ;
        }
        else
        {
            cout << ptr->data << " ";
        }
    }

    return cout;
}
