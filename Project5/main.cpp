#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

int main()
{
    ifstream fin;
    String* strings = new String[10];
    String word1, word2;
    String* stringHomePtr = strings;
    char* temp = new char[15];
    int userSelection, sourceString, destinationString, wordSelection, compareNum;
    bool continueProgram;
    String *sourceStringPtr, *destinationStringPtr;

    fin.open("strings");


    fin >> temp;
    word1.initialize(temp);

    fin >> temp;
    word2.initialize(temp);

    for(int i =0; i < 10; i++)
    {
        fin >> temp;
        (*strings).initialize(temp);
        strings++;
    }

    strings = stringHomePtr;

    fin.close();

    sourceStringPtr = strings;
    destinationStringPtr = strings;

    do
    {

        continueProgram = true;

        cout << "Would you like to compare the first two words, or the array of words?" << endl
             << "1. First two words" << endl
             << "2. Array of words"  << endl;
        cin >> userSelection;
        cout << endl << endl;

        cout << "What would you like to do with these strings?" << endl
             << "1. Copy strings" << endl
             << "2. Concatenate strings" << endl
             << "3. Compare strings" << endl
             << "4. Length of string" << endl
             << "5. Print all strings" << endl
             << "6. End program" << endl;
        cin >> wordSelection;
        cout << endl << endl;

        if(userSelection == 2)
        {

            if(wordSelection < 4 && wordSelection > 0)
            {
                cout << "Which two strings would you like to use?" << endl;
                cout << "Source: " ;
                cin >> sourceString;
                cout << "Destination: ";
                cin >> destinationString;
                cout << endl << endl;

                sourceStringPtr += sourceString;
                destinationStringPtr += destinationString;
            }
            if(wordSelection == 4)
            {
                cout << "Which string would you like the length of?: " ;
                cin >> sourceString;
                sourceStringPtr += sourceString;
            }

            switch(wordSelection)
            {
                case 1:
                    strings = destinationStringPtr;
                    (*strings).copy(*sourceStringPtr);
                    strings = stringHomePtr;
                    break;

                case 2:
                    strings = destinationStringPtr;
                    (*strings).concat(*sourceStringPtr);
                    strings = stringHomePtr;
                    break;

                case 3:
                    strings = destinationStringPtr;
                    compareNum = (*strings).compare(*sourceStringPtr);
                    strings = stringHomePtr;
                    cout << "Compare number is: " << compareNum << endl << endl;
                    break;

                case 4:
                    strings = sourceStringPtr;
                    cout << "The length of this word is: " << (*strings).length() << endl << endl;
                    strings = stringHomePtr;
                    break;

                case 5:
                    for(int i = 0; i < 10; i++)
                    {
                        (*strings).print();
                        strings++;
                    }
                    break;

                case 6:
                    continueProgram = false;

            }

        }

        else if(userSelection == 1)
        {

            switch(wordSelection)
            {
                case 1:
                    word1.copy(word2);
                    break;

                case 2:
                    word1.concat(word2);
                    break;

                case 3:
                    compareNum = word1.compare(word2);
                    cout << "Compare number is: " << compareNum << endl << endl;
                    break;

                case 4:
                    cout << "The length of this word is: " << word1.length() << endl << endl;
                    break;


                case 5:
                    word1.print();
                    word2.print();
                    break;

                case 6:
                    continueProgram = false;

            }

        }

        strings = stringHomePtr;
        sourceStringPtr = stringHomePtr;
        destinationStringPtr = stringHomePtr;

    } while(continueProgram);

    delete [] temp;
    delete [] strings;
    sourceStringPtr = NULL;
    destinationStringPtr = NULL;

    return 0;

}
