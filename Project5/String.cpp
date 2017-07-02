#include <iostream>
#include "String.h"

using namespace std;


void String::initialize(char *word)
{
    int length = 0;
    char* wordHomePtr = word;
    char* bufferHomePtr = buffer;

    while(*word != '\0')
    {
        length++;
        word++;
    }

    word = wordHomePtr;

    wordLength = length;

    buffer = new char[wordLength+1];
    bufferHomePtr = buffer;

    while(*word != '\0')
    {
        *buffer = *word;
        buffer++;
        word++;
    }
    *buffer = *word;
    buffer = bufferHomePtr;
}

void String::deallocate()
{
    delete [] buffer;
}

void String::copy(const String& word)
{
    char* wordHome = word.buffer;
    char* bufferHome = buffer;
    int sourceLength = word.wordLength;

    wordLength = sourceLength;


    for(int i = 0; i < sourceLength; i++)
    {
        *buffer = *wordHome;
        wordHome++;
        buffer++;
    }

    buffer = bufferHome;
}

int String::length() const
{
    return wordLength;
}

void String::concat(const String& source)
{
    int sourceLength = source.length();

    char* temp = new char[ wordLength + sourceLength + 1];
    char *homePtr1, *homePtr2;
    char* tempHome = temp;

    tempHome = temp;

    homePtr1 = buffer;

    for(int i = 0; i < wordLength; i++)
    {
        *temp = *buffer;
        temp++;
        buffer++;
    }

    buffer = homePtr1;

    homePtr2 = source.buffer;

    for(int i = 0; i < sourceLength; i++)
    {
        *temp = *homePtr2;
        temp++;
        homePtr2++;
    }

    temp = tempHome;

    delete [] buffer;

    wordLength = sourceLength + wordLength;

    buffer = temp;

    delete [] temp;

}

int String::compare(const String& source)
{
    int compareLength;
    char *sourceTest, *bufferTest;

    sourceTest = source.buffer;
    bufferTest = buffer;
    do
    {
        compareLength = *sourceTest - *bufferTest;
        sourceTest++;
        bufferTest++;

    }while(!compareLength);

    return compareLength;

}

void String::print()
{
    cout << "Buffer: " << buffer << endl;
    cout << "Word length: " << wordLength << endl;
}
