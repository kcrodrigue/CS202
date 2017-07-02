#include <fstream>
#include <iostream>

const int MAX_STRING_LENGTH = 50;
const int MAX_NUM_CARS = 5;
const int MAX_NUM_AGENCIES = 3;

using namespace std;

struct car
{
	char make[MAX_STRING_LENGTH];
	char model[MAX_STRING_LENGTH];
	int year;
	float price;
	bool available;

};

struct agency
{
	char name[MAX_STRING_LENGTH];
	int zipcode;
	car rentalCar[MAX_NUM_CARS];
};


// reads Car Data file provided with assignment
void readFile( char *file, agency *agencies );



// simply shows menu, and prompts user for selection, and returns int value
int showMenu( );



/*
	prints car list, with a couple conditions
	availability bool will show available cars only if true
	promptUser bool will prompt user which car they want, and calculate cost
	after all of this, it holds for user
*/
void printCarList( agency *agencies, bool availability, bool promptUser);

// finds most expensive car and prints info for user
void mostExpensiveCar( agency *agencies );



int main()
{
	char fileName[MAX_STRING_LENGTH];
	agency agencies[MAX_NUM_AGENCIES];
	int menuSelection;
	bool continueProgram;
	agency *agencyPtr;
	char *filePtr;

	agencyPtr = agencies;
	filePtr = fileName;


	cout << "Enter file name: " ;
	cin >> fileName;

	readFile( fileName, agencyPtr );


	do
	{

		menuSelection = showMenu();

		switch(menuSelection)
		{
			case 1:
				printCarList( agencyPtr, false , false);
				continueProgram = true;
				break;

			case 2:
				printCarList( agencyPtr, false, true);
				continueProgram = true;
				break;

			case 3:
				mostExpensiveCar( agencyPtr );
				continueProgram = true;
				break;

			case 4:
				printCarList( agencyPtr, true , false);
				continueProgram = true;
				break;

			default:
				// stop loop
				continueProgram = false;


		}

	}while(continueProgram);







	return 0;
}



void readFile( char *file, agency *agencies )
{
	ifstream fin;
	int index, indexTwo;
	car *carPtr;

	fin.clear();
	fin.open(file);

	for(index = 0; index < MAX_NUM_AGENCIES; index++)
	{
		fin >> (*agencies).name
			>> (*agencies).zipcode;
		
		carPtr = (*agencies).rentalCar;
		
		for(indexTwo = 0; indexTwo < MAX_NUM_CARS; indexTwo++)
		{
			fin >> (*carPtr).year
				>> (*carPtr).make
				>> (*carPtr).model
				>> (*carPtr).price
				>> (*carPtr).available;
				
			carPtr++;
		}

		agencies++;
	}


}

int showMenu( )
{
	int userSelection;

	cout << "\n\nWelcome to KC's Rental Car Service\n" ;
	cout << "----------------------------------\n\n\n" ;

	cout << "1) Print data for all cars" << endl;
	cout << "2) Estimate car rental cost" << endl;
	cout << "3) Find the most expensive car" << endl;
	cout << "4) Print data for available cars" << endl;
	cout << "5) Exit program" << endl << endl;
	cout << "Enter selection: " ;
	cin >> userSelection;

	return userSelection;

}

void printCarList( agency *agencies, bool availability, bool promptUser)
{
	int index, indexTwo, carSelection, daySelection;
	float rentalPrice;
	car *carPtr;

	if(availability)
	{
		cout << "\n\nAvailable cars:\n";
		
		for( index = 0; index < MAX_NUM_AGENCIES; index++ )
		{
		
			cout << (*agencies).name << " " << (*agencies).zipcode << endl;
			
			carPtr = (*agencies).rentalCar;

			for( indexTwo = 0; indexTwo < MAX_NUM_CARS; indexTwo++)
			{
				if((*carPtr).available)
				{

					// shows car number
					cout << indexTwo+1 << ") " ;

					cout << (*carPtr).year << " "
						 << (*carPtr).make << " "
						 << (*carPtr).model << " "
						 << " " << (*carPtr).price << " per day "
						 << "Available: ";

					if((*carPtr).available)
						 cout << "true" ;

					else if(!(*carPtr).available)
						 cout << "false" ;

					cout << endl;
				}
			
				carPtr++;
			}
			
			agencies++;
			
		}

	}
	else
	{
		cout << "\n\nAll cars:\n";

		for( index = 0; index < MAX_NUM_AGENCIES; index++ )
		{
		
			cout << (*agencies).name << " " << (*agencies).zipcode << endl;
			
			carPtr = (*agencies).rentalCar;

			for( indexTwo = 0; indexTwo < MAX_NUM_CARS; indexTwo++ )
			{

				// shows car number
				cout << indexTwo+1 << ") " ;

				cout << (*carPtr).year << " "
					 << (*carPtr).make << " "
					 << (*carPtr).model << " "
					 << " " << (*carPtr).price << " per day "
					 << "Available: ";

				if((*carPtr).available)
					 cout << "true" ;

				else if(!(*carPtr).available)
					 cout << "false" ;

				cout << endl;
			
				carPtr++;
			}
			
			agencies++;
			
		}

	}

	if(promptUser)
	{
		carPtr = (*agencies).rentalCar;
		
		cout << "\n\n\nPlease enter the number for the car you want: " ;
		cin >> carSelection;

		cout << "Please enter how many days you would like car #" << carSelection << ": " ;
		cin >> daySelection;
		
		carPtr += carSelection;
		
		rentalPrice = (*carPtr).price * daySelection;

		cout << "Your rental price will be " << rentalPrice << ".\n\n" ;


	}

	cout << "Press enter to go back to menu." ;
	cin.ignore().get();


}

void mostExpensiveCar( agency *agencies )
{
	int index, indexTwo;
	car *carPtr, *mostExpensive, *testPtr;
	
	mostExpensive = (*agencies).rentalCar;
	
	for( index = 0; index < MAX_NUM_AGENCIES; index++)
	{
		carPtr = (*agencies).rentalCar;
		testPtr = (*agencies).rentalCar;

		for(indexTwo = 0; indexTwo < MAX_NUM_CARS; indexTwo++)
		{
			if( (*carPtr).price > (*mostExpensive).price )
			{
				mostExpensive = carPtr;
			}
			carPtr++;

		}
		
		agencies++;
		
	}

	cout << "\nThe most expensive car is the " << (*mostExpensive).make << " " << (*mostExpensive).model
		 << ", pricing at " << (*mostExpensive).price << " per day.\n" ;
	cout << "It is currently " ;

	if((*mostExpensive).available)
		cout << "available.\n" ;

	else
		cout << "unavailable.\n" ;

	cout << "\nPress enter when you are ready to go back to the menu" ;
	cin.ignore().get();

}
