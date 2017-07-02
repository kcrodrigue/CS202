#include "listA.h"
#include "listN.h"
#include <fstream>


int main()
{
    string file_name;
    int find_this;
    int result;
    ListA array(10);
    ListN nodes;
    bool continue_program = true;

    cout << "Enter file name to read in integers: ";
    cin >> file_name;

    readInData(file_name, array);
    sortData(array);

    while(continue_program)
    {
        cout << endl;
        cout << "Enter a number you would like to find. (Enter -1 to exit program loop): ";
        cin >> find_this;

        if(find_this == -1)
        {
            continue_program = false;
        }
        else
        {
            continue_program = true;
            result = findNumber(array, find_this, 0, 9);
            if(result == -1)
            {
                cout << "The number was not found in the list." << endl;
            }
            else
            {
                cout << "The number was found in the list: " << endl;
            }
        }
    }
    return 0;
}
