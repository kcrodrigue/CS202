#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Pieces
{
    char *word;
    int jump;
};

int strLen( char *array );

void strConcat( char *destination, char *addition);

void strCopy( char *destination, char *source);

void decipher( Pieces *piecesPtr , int numKeys, int numWords, int *keyPtr);

int main()
{
	ifstream fin;
	char *fileName = new char[20];
    char *input = new char[20];
	int numKeys, numWords, wordLen;
    int *keyPtr;
	Pieces *piecesPtr ;

	cout << "Enter file name: " ;
	cin >> fileName;

	fin.open(fileName);

	fin >> numWords
		>> numKeys;

    keyPtr = new int[numKeys];

	piecesPtr = new Pieces[numWords];

    for (int i = 0; i < numWords; i++)
    {
        fin >> input;
        fin >> (*piecesPtr).jump;

        wordLen = strLen( input );

        (*piecesPtr).word = new char[wordLen];
        strcpy((*piecesPtr).word, input);

        piecesPtr++;

    }

    piecesPtr -= numWords;

    for (int i = 0; i < numKeys; i++)
    {
        fin >> (*keyPtr);
        keyPtr++;
    }

    keyPtr -= numKeys;

    fin.close();

    decipher( piecesPtr, numKeys, numWords, keyPtr );

    for( int i = 0; i < numWords; i++)
    {
        delete [] (*piecesPtr).word;
        piecesPtr++;
    }

    cout << endl << "deleted word ptrs" ;

    delete [] fileName;
    delete [] input;
    delete [] piecesPtr;
    delete [] keyPtr;

    cout << "finished";

    return 0;
}

int strLen( char *array )
{
    int index;

    for(index = 0; index < 20; index++)
    {
        if(array[index] == '\0')
        {
            break;
        }
    }

    return index;
}

void strConcat( char *destination, char *addition)
{
    for(int i = 0; i < 100; i++)
    {

        if((*destination) == '\0')
        {
            while((*addition) != '\0')
            {
                (*destination) = (*addition);
                destination++;
                addition++;
            }
            (*destination) = '\0';
            break;
        }
        else
        {
            destination++;
        }

    }

}

void strCopy( char *destination, char *source)
{
    while( (*source) != '\0')
    {
        (*destination) = (*source);
        destination++;
        source++;
    }
}

void decipher( Pieces *piecesPtr, int numKeys, int numWords, int *keyPtr )
{
    Pieces *tempPtr ;
    char **holderPtr = new char*[numKeys];
    int strLength = 0;
    char *message;
    int wrap = 1;
    char *space = new char[1];
    ofstream fout;
    *space = ' ';

    fout.open("decoded_message.txt");


    for(int i = 0; i < numKeys; i++)
    {
        tempPtr = piecesPtr;

        piecesPtr += *keyPtr;
        wrap = *keyPtr;

        while((*piecesPtr).jump !=0)
        {
            wrap += (*piecesPtr).jump;


            if(wrap >= numWords)
            {
                wrap %= numWords;
                piecesPtr-=*keyPtr;
                piecesPtr+=wrap;
            }
            else
            {
                piecesPtr+=(*piecesPtr).jump;
            }

        }

        (*holderPtr) = (*piecesPtr).word;

        piecesPtr = tempPtr;

        holderPtr++;
        keyPtr++;

    }

    holderPtr -= numKeys;

    for(int i = 0; i < numKeys; i++)
    {

        strLength += strLen( (*holderPtr) );
        holderPtr++;

        // space
        strLength++;
    }

    holderPtr-= numKeys;

    message = new char[strLength];
    cin.ignore().get();

    for(int i = 0; i < numKeys; i++)
    {
        strConcat( message, (*holderPtr) );
        strConcat( message, space);
        holderPtr++;
    }
    holderPtr-=numKeys;
    fout << message;
    cin.ignore().get();

    delete [] holderPtr;
    delete [] space;

}
