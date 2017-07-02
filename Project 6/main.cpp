#include <iostream>
#include "Agency.h"

using namespace std;

int main()
{
    Agency national;
    char* file = new char[20];
    int user_input, car_selection, day_selection;
    bool continue_program;
    char *input_make;

    cout << "Enter file name: ";
    cin >> file;

    national.readInData(file);

    do
    {
        continue_program = true;

        cout << "What would you like to do?" << endl;
        cout << "1. Print all cars from agency"<< endl;
        cout << "2. Print available cars" << endl;
        cout << "3. Find most expensive car" << endl;
        cout << "4. Estimate cost of a car" << endl;
        cout << "5. Sort cars by make" << endl;
        cout << "6. Sort cars by price" << endl;
        cout << "7. Search cars by make" << endl;
        cout << "8. Read in a separate agency" << endl;
        cout << "9. Exit program" << endl;
        cin >> user_input;

        switch(user_input)
        {
            case 1:
                national.print();
                break;

            case 2:
                national.printAvailableCars();
                break;

            case 3:
                national.findMostExpensive();
                break;

            case 4:
                cout << "Which car would you like, and for how many days?" << endl;
                national.print();

                cout << "Car number: " ;
                cin >> car_selection;

                cout << "Number of days: " ;
                cin >> day_selection;

                national.estimateCost(car_selection, day_selection);
                break;

            case 5:
                national.sortByMake();
                break;

            case 6:
                national.sortByPrice();
                break;

            case 7:
                cout << "Enter search make:" ;
                cin >> input_make;
                national.searchByMake(input_make);
                break;

            case 8:
                cout << "Enter file name: " ;
                cin >> file;
                national.readInData(file);
                break;

            case 9:
                continue_program = false;
                break;
        }

    }while(continue_program);

    return 0;
}
