#include "Polynomial.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    Polynomial poly1, poly2;
    bool continue_program = true;
    bool match;
    int user_input, test_num;
    ifstream fin;
    string file;
    Polynomial temp_poly;

    do
    {

        cout << "Welcome to Polynomial land" << endl
             << "Please do what you wish to these polynomials" << endl;

        cout << "1. Read in a set of polynomials" << endl
             << "2. Set two polynomials equal" << endl
             << "3. Test to see if two polynomials are equal" << endl
             << "4. Test to see if two polynomials differ from each other" << endl
             << "5. Multiply two polynomials" << endl
             << "6. Multiply a polynomial by an integer" << endl
             << "7. Add two polynomials" << endl
             << "8. Output both polynomials in current state" << endl
             << "9. Exit Program" << endl;

        cin >> user_input;

        switch(user_input)
        {
            case 1:
                cout << "Please enter file name: ";
                cin >> file;

                fin.open(file.c_str());

                fin >> poly1 >> poly2;
                break;

            case 2:
                poly1 = poly2;
                cout << "The polynomials are now: " << poly1 << " and " << poly2 << endl;
                break;

            case 3:
                if(poly1 == poly2)
                {
                    match = true;
                }
                else
                {
                    match = false;
                }
                cout << "Polynomials are " ;
                if(!match)
                {
                    cout << "not " ;
                }
                cout << "equal." ;
                break;

            case 4:
                if(poly1 != poly2)
                {
                    match = false;
                }
                else
                {
                    match = true;
                }
                cout << "Polynomials are " ;
                if(!match)
                {
                    cout << "not " ;
                }
                cout << "equal." ;
                break;

            case 5:
                poly1 = poly1 * poly2;
                cout << "The first polynomial (product) is now: " << poly1 << endl;
                break;

            case 6:
                cout << "Enter an integer to multiply by: ";
                cin >> test_num;
                poly1 = poly1 * test_num;
                cout << "The first polynomial (product) is now: " << poly1 << endl;
                break;

            case 7:
                poly1 = poly1 + poly2;
                cout << "The first polynomial (sum) is now: " << poly1 << endl;
                break;

            case 8:
                cout << "Polynomial 1: " << poly1 << endl
                     << "Polynomial 2: " << poly2 << endl;
                break;

            case 9:
                continue_program = false;
                break;
        }
    } while(continue_program);


    return 0;
}
