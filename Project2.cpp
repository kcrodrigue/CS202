#include <fstream>
#include <iostream>

const int MAX_STRING_LENGTH = 50;
const int MAX_NUM_CARS = 10;

using namespace std;

struct car
{
	char make[MAX_STRING_LENGTH];
	char model[MAX_STRING_LENGTH];
	int year;
	float price;
	bool available;
	
};


// reads Car Data file provided with assignment
void readFile( char fileName[], car carList[]);



// simply shows menu, and prompts user for selection, and returns int value
int showMenu( );



/*
	prints car list, with a couple conditions
	availability bool will show available cars only if true
	promptUser bool will prompt user which car they want, and calculate cost
	after all of this, it holds for user
*/
void printCarList( car carList[], bool availability, bool promptUser);

// finds most expensive car and prints info for user
void mostExpensiveCar( car carList[] );



int main()
{
	char fileName[MAX_STRING_LENGTH];
	car carList[MAX_NUM_CARS];
	int menuSelection;
	bool continueProgram;
	
	
	cout << "Enter file name: " ;
	cin >> fileName;
	
	readFile( fileName, carList );
	
	
	do
	{
	
		menuSelection = showMenu();
	
		switch(menuSelection)
		{
			case 1:
				printCarList( carList, false , false);
				continueProgram = true;
				break;
			
			case 2:
				printCarList( carList, false, true);
				continueProgram = true;
				break;
			
			case 3:
				mostExpensiveCar( carList );
				continueProgram = true;
				break;
			
			case 4:
				printCarList( carList, true , false);
				continueProgram = true;
				break;
			
			default:
				// stop loop
				continueProgram = false;
	
	
		}
	
	}while(continueProgram);
	
	
	
	
	
	
	
	return 0;
}



void readFile( char fileName[], car carList[])
{
	ifstream fin;
	int index;
	char testChar;
	
	fin.clear();
	fin.open(fileName);
	
	for(index = 0; index < MAX_NUM_CARS; index++)
	{
		fin 
		>> carList[index].year 
		>> carList[index].make 
		>> carList[index].model 
		>> carList[index].price 
		>> carList[index].available;
		
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

void printCarList( car carList[], bool availability, bool promptUser)
{
	int index, carSelection, daySelection;
	float rentalPrice;
	
	if(availability)
	{
		cout << "\n\nAvailable cars:\n";
		
		for( index = 0; index < MAX_NUM_CARS; index++ )
		{
			if(carList[index].available)
			{
			
				// shows car number
				cout << index+1 << ") " ;
			
				cout << carList[index].year << " " 
					 << carList[index].make << " "
					 << carList[index].model << " "
					 << " " << carList[index].price << " per day "
					 << "Available: ";
					 
				if(carList[index].available)
					 cout << "true" ;
					 	
				else if(!carList[index].available)
					 cout << "false" ;
					 
				cout << endl;
			}
		}	
		
		
	}
	else
	{
		cout << "\n\nAll cars:\n";
	
		for( index = 0; index < MAX_NUM_CARS; index++ )
		{
			// shows car number
			cout << index+1 << ") " ;
		
			cout << carList[index].year << " " 
				 << carList[index].make << " "
				 << carList[index].model << " "
				 << " " << carList[index].price << " per day "
				 << "Available: ";
					 
			if(carList[index].available)
					 cout << "true" ;
					 	
			else if(!carList[index].available)
					 cout << "false" ;
					 
			cout << endl;
		}
		
	}
	
	if(promptUser)
	{
		cout << "\n\n\nPlease enter the number for the car you want: " ;
		cin >> carSelection;
		
		cout << "Please enter how many days you would like car #" << carSelection << ": " ;
		cin >> daySelection;
		
		rentalPrice = carList[carSelection-1].price * daySelection;
		
		cout << "Your rental price will be " << rentalPrice << ".\n\n" ;
		
		
	}
	
	cout << "Press enter to go back to menu." ;
	cin.ignore().get();


}

void mostExpensiveCar( car carList[] )
{
	int mostExpensive = 0;
	int index;
	
	for(index = 0; index < MAX_NUM_CARS; index++)
	{
		if( carList[index].price > carList[mostExpensive].price )
		{
			mostExpensive = index;
		}
		
	}
	
	cout << "\nThe most expensive car is the " << carList[mostExpensive].make << " " << carList[mostExpensive].model 
		 << ", pricing at " << carList[mostExpensive].price << " per day.\n" ;
	cout << "It is currently " ;
	
	if(carList[mostExpensive].available)
		cout << "available.\n" ;
		
	else
		cout << "unavailable.\n" ;
		 
	cout << "\nPress enter when you are ready to go back to the menu" ;
	cin.ignore().get();
	
}
