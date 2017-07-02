#include <iostream>
using namespace std;


class ListA
{
 public:
   ListA(int);
   ListA(const ListA&);
   ~ListA();
   bool goToBeginning();
   bool goToEnd();
   bool goToNext();
   bool goToPrior();
   bool insertBefore(int);
   bool insertAfter(int);
   bool remove();
   bool isEmpty() const;
   bool isFull() const;
   void clear();
   ListA& operator=(const ListA&);
   friend ostream& operator<<(ostream&, const ListA&);
   friend void readInData(string, ListA&);
   friend void sortData(ListA& );
   friend int findNumber(ListA&, int, int, int);
 private:
   int size;
   int actual;
   int cursor;
   int *data;
};
