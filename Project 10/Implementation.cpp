#include "listN.h"
#include "listA.h"
#include <fstream>

Node::Node(int input, Node* point_to)
{
    data = input;
    next = point_to;
}

ListN::ListN()
{
    head = NULL;
    cursor = NULL;
}

ListN::ListN(const ListN& copy)
{
    Node *temp, *copy_temp;
    temp = head;
    copy_temp = copy.head;

    temp = new Node(copy.head->data, NULL);
    copy_temp = copy_temp->next;
    head = temp;

    while(copy_temp != NULL && temp != NULL)
    {
        temp->next = new Node(copy_temp->data, NULL);
        copy_temp = copy_temp->next;
        temp = temp->next;
    }

    cursor = head;

    temp = NULL;
    copy_temp = NULL;
}

ListN::~ListN()
{
    Node* temp;

    temp = head;

    while(head != NULL)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
    cursor = NULL;
}

bool ListN::goToBeginning()
{
    bool valid = false;

    if(cursor!=head)
    {
        cursor = head;
        valid = true;
    }

    return valid;
}

bool ListN::goToEnd()
{
    bool valid = false;
    Node* temp = cursor;

    while(temp != NULL)
    {
        cursor=temp;
        temp = temp->next;
        valid = true;
    }

    return valid;
}

bool ListN::goToNext()
{
    bool valid = false;

    if(cursor != NULL)
    {
        cursor=cursor->next;
        valid = true;
    }

    return valid;
}

bool ListN::goToPrior()
{
    bool valid = false;
    Node* test;

    test = head;

    while(test != cursor)
    {
        cursor = test;
        test=test->next;
        valid = true;
    }

    return valid;
}

bool ListN::insertBefore(int input)
{
    bool valid = false;
    Node* temp = head;

    if(cursor!=head)
    {
        valid = true;
        while(temp->next != cursor)
        {
            temp = temp->next;
        }
        temp->next = new Node(input, cursor);
    }

    return valid;
}

bool ListN::insertAfter(int input)
{
    if(cursor->next != NULL)
    {
        cursor->next = new Node(input, cursor->next->next);
    }
    else
    {
        cursor->next = new Node(input, NULL);
    }

    return true;
}

bool ListN::remove()
{
    Node* test = head;
    bool valid = false;

    if(head != NULL && cursor != NULL)
    {
        valid = true;
        while(test->next != cursor)
        {
            test=test->next;
        }
        test->next = cursor->next;

        delete cursor;

        cursor = test->next;
    }

    return valid;
}

bool ListN::isEmpty() const
{
    bool empty = false;

    if(head == NULL)
    {
        empty = true;
    }

    return empty;
}

bool ListN::isFull () const
{
    return false; //linked ListNs are never full
}

void ListN::clear()
{
    Node* temp = head;

    while(head != NULL)
    {
        head = head->next;
        delete temp;
        temp = head;
    }

}

ListN& ListN::operator=(const ListN& rhs)
{
    Node *temp, *copy_temp;

    head = rhs.head;

    temp = head;
    copy_temp = rhs.head;

    while(copy_temp!= NULL)
    {
        temp->next = copy_temp->next;
        temp->data = copy_temp->data;

        temp = temp->next;
        copy_temp = copy_temp->next;
    }


    temp = NULL;
    copy_temp = NULL;

    return *this;
}

ostream& operator<<(ostream& cout, const ListN& output)
{
    Node *ptr=output.head;

    while(ptr != NULL)
    {
        if(ptr == output.cursor)
        {
            cout << "[" << ptr->data << "] " ;
        }
        else
        {
            cout << ptr->data << " ";
        }
        ptr= ptr->next;
    }

    return cout;
}

ListA::ListA(int input_size)
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

ListA::ListA(const ListA& copy)
{
    size = copy.size;
    actual = copy.actual;
    cursor = copy.cursor;
    data = new int[size];

    for(int i = 0; i < size; i++)
    {
        data[i] = copy.data[i];
    }
}

ListA::~ListA()
{
    delete [] data;
}

bool ListA::goToBeginning()
{
    bool valid = false;

    if(cursor!= 0)
    {
        cursor = 0;
        valid = true;
    }

    return valid;
}

bool ListA::goToEnd()
{
    bool valid = false;

    if(cursor!= size-1)
    {
        cursor = size-1;
        valid = true;
    }

    return valid;
}

bool ListA::goToNext()
{
    bool valid = false;

    if(cursor < size-1)
    {
        cursor++;
        valid = true;
    }

    return valid;
}

bool ListA::goToPrior()
{
    bool valid = false;

    if(cursor > 0)
    {
        cursor--;
        valid = true;
    }
    return valid;
}

bool ListA::insertBefore(int input)
{
    bool valid = false;

    if(cursor!= 0 && actual < size-1)
    {
        actual++;
        for(int i = actual; i >= cursor; i--)
        {
            data[i+1] = data[i];
        }
        data[cursor] = input;
        cursor++;
        valid = true;
    }
    return valid;
}

bool ListA::insertAfter(int input)
{
    bool valid = false;

    if(actual < size-1)
    {
        for(int i = actual; i >= cursor+1; i--)
        {
            data[i+1] = data[i];
        }
        data[cursor+1] = input;
        valid = true;
    }

    return valid;
}

bool ListA::remove()
{
    bool valid = false;

    if(actual != 0)
    {
        for(int i = cursor; i < actual; i++)
        {
            data[i] = data[i+1];
        }
        actual--;
        valid = true;
    }

    return valid;
}

bool ListA::isEmpty() const
{
    bool empty = false;

    if(actual == 0 )
    {
        empty = true;
    }

    return empty;
}

bool ListA::isFull() const
{
    bool full = false;

    if(actual == size-1)
    {
        full = true;
    }

    return full;
}

void ListA::clear()
{
    actual = 0;
    cursor = 0;
}

ListA& ListA::operator =(const ListA& rhs)
{
    if(data!= NULL)
    {
        delete[] data;
    }

    size = rhs.size;
    actual = rhs.actual;
    cursor = rhs.cursor;
    data = new int[size];

    for(int i = 0; i < actual; i++)
    {
        data[i] = rhs.data[i];
    }

    return *this;
}

ostream& operator<<(ostream& os_object, const ListA& output)
{
    for(int i = 0; i < output.actual; i++)
    {
        if(i == output.cursor)
        {
            os_object << "[" << output.data[i] << "] ";
        }
        else
        {
            os_object << output.data[i] << " ";
        }
    }

    return os_object;
}

void readInData(string file_name, ListA& array)
{
    ifstream fin(file_name.c_str());

    for(int i = 0; i < array.size; i++)
    {
        fin >> array.data[i];
    }
}

void sortData(ListA& array)
{
    int temp_storage;

    // insertion sort
    for( int i = 1; i < array.size ; i++)
	{
		for( int j = i; j > 0; j-- )
		{
			if(array.data[j-1] > array.data[j])
            {
                temp_storage = array.data[j-1];
                array.data[j-1] = array.data[j];
                array.data[j] = temp_storage;
            }
		}
	}
    cout << array;

}

int findNumber(ListA& array, int find_this, int first, int last)
{
    int middle;

    if(first <= last)
    {
        middle = (first + last) / 2;
        if(find_this == array.data[middle])
        {
            array.cursor = middle;
            return middle;
        }
        else if(find_this < array.data[middle])
        {
            return findNumber(array, find_this, first, middle-1);
        }
        else
        {
            return findNumber(array, find_this, middle+1, last);
        }
    }
    else
    {
        return -1;
    }
}
