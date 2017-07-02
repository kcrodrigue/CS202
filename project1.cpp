#include <iostream>
#include <fstream>

const int MAX_NUMBER_NAMES = 10;
const int MAX_STRING_LENGTH = 10;

using namespace std;

void readFile( char array[][MAX_STRING_LENGTH], char fileName[]);

void printArray (char array[][MAX_STRING_LENGTH] , int arraySize, bool file, char fileName[]);

void sortNames (char array[][MAX_STRING_LENGTH] , int arraySize);

void swapNames (char array[][MAX_STRING_LENGTH] , int firstPos , int secondPos);

bool compareNames( char array[][MAX_STRING_LENGTH], int firstPos, int secondPos);

int main()
{
	//variables
	char names[MAX_NUMBER_NAMES][MAX_STRING_LENGTH];
	char inputFile[MAX_STRING_LENGTH] ;
	char outputFile[MAX_STRING_LENGTH] ;
	ifstream fin;
	ofstream fout;
	
	fin.clear();
	
	//prompt for file names
	cout << "Enter input file name: " ;
	cin >> inputFile ;
	cout << "Enter output file name: " ;
	cin >> outputFile ;
	cout << endl;
	
	readFile( names , inputFile );
	
	// print unsorted and sorted names
	cout << "Unsorted Names" << endl 
		 << "===============" << endl ;
		
	printArray( names , MAX_NUMBER_NAMES, false, outputFile );
	
	cout << endl << endl << endl ;
	
	sortNames(names , MAX_NUMBER_NAMES );
	
	cout << "Sorted Names" << endl 
		 << "=============" << endl ;
		
	printArray( names , MAX_NUMBER_NAMES, false, outputFile );
	
	
	fout << "Sorted Names" << endl
		 << "=============" << endl ;
	printArray( names , MAX_NUMBER_NAMES, true, outputFile );
	
	

}

// reads a file of names into an array
void readFile( char array[][MAX_STRING_LENGTH], char fileName[])
{
	int iterator;
	ifstream fin;
	fin.open(fileName);
	
	// get each line
	for (iterator = 0; iterator < MAX_NUMBER_NAMES; iterator++)
	{
		fin.getline(array[iterator], MAX_STRING_LENGTH);
	
	} 


}

// prints an array to screen is file boolean or false, or to a file if true
void printArray (char array[][MAX_STRING_LENGTH] , int arraySize, bool file, char fileName[])
{
	int iterator;
	
	ofstream fout;
	
	fout.open(fileName);
	
	// print to either console, or file
	if( file == false)
	{
		for( iterator = 0; iterator < arraySize; iterator++)
		{
			cout << array[iterator] ;
			cout << endl;
		}	
	}
	else if( file )
	{
		for( iterator = 0; iterator < arraySize; iterator++)
		{
			fout << array[iterator] ;
			fout << endl;
		}
	}

}

// sortNames will use a sorting method to sort through the array
// sorting it alphabetically
void sortNames (char array[][MAX_STRING_LENGTH] , int arraySize)
{
	int index, currentName, nameIndex = 0;
	
	// insertion sort	
	for( index = 1; index < arraySize ; index++)
	{	
		
		for( currentName = index; currentName > 0; currentName-- )
		{
			if( compareNames( array, currentName, currentName-1) )
			{
				swapNames( array, currentName, currentName-1);
			}
			
		}
	}
	
	

}

// swapNames will take an array, with two positions, and swap the names at the two positions
void swapNames (char array[][MAX_STRING_LENGTH] , int firstPos , int secondPos)
{
	int iterator ;
	char temp;
	
	// swap names
	for ( iterator = 0; iterator < MAX_STRING_LENGTH; iterator++)
	{
		temp = array[firstPos][iterator];
		array[firstPos][iterator] = array[secondPos][iterator];
		array[secondPos][iterator] = temp;
	}
	
}

// this will compare two names, and returns whether or not they are in order 
bool compareNames( char array[][MAX_STRING_LENGTH], int firstPos, int secondPos)
{
	int index =0;
	bool namesMatch;
	bool inOrder = false;
	
	// check if names are in order
	do
	{
		namesMatch = false;
		
		if( array[firstPos][index] < array[secondPos][index] )
		{
			inOrder = true;
		}
		else if(array[firstPos][index] == array[secondPos][index])
		{
			namesMatch = true;
		}
		
		index++;
		
	}while(namesMatch);
	
	return inOrder;
	
	
}
