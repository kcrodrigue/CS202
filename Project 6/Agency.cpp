#include <iostream>
#include <fstream>
#include "Agency.h"

using namespace std;

void strCopy( char *destination, char *source);

bool compareMake(Car *car_1, Car *car_2);

void swapCar(Car *car_one, Car *car_two);

Car::Car()
{
    make = new char[25];
    model = new char[25];
    year = 0;
    price = 0;
    available = 0;
}

Car::Car(char *input_make, char *input_model, int input_year, float input_price, bool input_available)
{
    make = input_make;
    model = input_model;
    year = input_year;
    price = input_price;
    available = input_available;
}

Car::Car(const Car& source_car)
{
    make = source_car.make;
    model = source_car.model;
    year = source_car.year;
    price = source_car.price;
    available = source_car.available;
}

Car::~Car()
{
    delete [] make;
    delete [] model;
}

void Car::copy(Car source_car)
{
    make = source_car.make;
    model = source_car.model;
    year = source_car.year;
    price = source_car.price;
    available = source_car.available;
}

void Car::print() const
{
    cout << year << " " << make << " " << model
         << ", which costs " << price << " per day"
         << ", and is ";

    if(available)
    {
        cout << "Available";
    }
    else
    {
        cout << "Unavailable";
    }
    cout << endl;

}

char* Car::getMake() const
{
    return make;
}

char* Car::getModel() const
{
    return model;
}

int Car::getYear() const
{
    return year;
}

float Car::getPrice() const
{
    return price;
}

bool Car::getAvailable() const
{
    return available;
}

void Car::setMake(char* source)
{
    delete [] make;
    strCopy(make, source);
}

void Car::setModel(char* source)
{
    delete [] model;
    strCopy(model, source);
}

void Car::setYear(int source)
{
    year = source;
}

void Car::setPrice(float source)
{
    price = source;
}

void Car::setAvailable(bool source)
{
    available = source;
}

//Agency
Agency::Agency()
{
    name = new char[25];
    zipcode = new int[5];
    inventory = new Car[15];
}

Agency::Agency(const Agency& source)
{
    name = source.name;
    zipcode = source.zipcode;
    inventory = source.inventory;
}

Agency::~Agency()
{
    delete [] name;
    delete [] zipcode;
    delete [] inventory;
}

void Agency::readInData(char* fileName)
{
    ifstream fin(fileName);
    Car* car_home = inventory;
    char* temp_word = new char[25];
    char* temp_model = new char[25];
    char temp_char;
    int temp_num;
    bool temp_bool;
    float temp_float;
    int* zip_home = zipcode;

    fin >> name;

    for(int i = 0; i < 5; i++)
    {
        fin >> temp_char;
        *zipcode = temp_char - '0';
        zipcode++;
    }

    zipcode = zip_home;
    zip_home = NULL;

    for(int i = 0; i < 15; i++)
    {
        fin >> temp_num;
        (*inventory).setYear(temp_num);

        fin >> temp_word;
        (*inventory).setMake(temp_word);

        fin >> temp_model;
        (*inventory).setModel(temp_model);

        fin >> temp_float;
        (*inventory).setPrice(temp_float);

        fin >> temp_bool;
        (*inventory).setAvailable(temp_bool);

        inventory++;
    }

    inventory = car_home;
    car_home = NULL;
    temp_word = NULL;
    temp_model = NULL;

}

void Agency::print() const
{
    Car* car_home = inventory;
    int *zip_index = zipcode;

    cout << name << " " ;

    for(int i = 0; i < 5; i++)
    {
        cout << *zip_index;
        zip_index++;
    }

    cout << endl;

    zip_index = NULL;

    for(int i = 0; i < 15; i++)
    {
        (*car_home).print();
        car_home++;
    }

}

void Agency::printAvailableCars() const
{
    Car* car_home = inventory;
    int *zip_index = zipcode;

    cout << name << " " ;

    for(int i = 0; i < 5; i++)
    {
        cout << *zip_index;
        zip_index++;
    }

    cout << endl;
    zip_index = NULL;

    for(int i = 0; i < 15; i++)
    {
        if((*inventory).getAvailable())
        {
            (*inventory).print();
            car_home++;
        }
    }
}

void Agency::findMostExpensive() const
{
    Car* car_index = inventory;
    Car most_expensive = *inventory;

    if((*car_index).getPrice() < most_expensive.getPrice())
    {
        most_expensive = *car_index;
        car_index++;
    }

    cout << "The most expensive car is: " ;
    most_expensive.print();
}

float Agency::estimateCost(int num_days, int car_num) const
{
    Car* test_car = inventory;
    float price_estimate;

    for(int i = 0; i < car_num -1; i++)
    {
        test_car++;
    }

    price_estimate = (*test_car).getPrice();

    price_estimate *= num_days;

    return price_estimate;

}

void Agency::sortByMake()
{
    Car *car_home = inventory;
    char *first_car, *second_car;
    Car temp;
    bool swapped = true;

    while(swapped)
    {
        swapped = false;
        for(int i = 0; i < 15; i++)
        {
            first_car = (*(car_home+i)).getMake();
            second_car = (*(car_home+i+1)).getMake();

            while(first_car == second_car && first_car != '\0')
            {
                first_car++;
                second_car++;
            }

            if(first_car > second_car)
            {
                temp.copy( *(car_home+i) );
                (*(car_home+i)).copy( *(car_home+i+1) );
                (*(car_home+i+1)).copy( *(car_home+i) );
            }
        }
    }

    car_home = NULL;
    first_car = NULL;
    second_car = NULL;
}

void Agency::sortByPrice()
{

}

void Agency::searchByMake(char *input_make) const
{
    Car *inv_ptr = inventory;
    bool matched;
    char *temp_make;

    cout << "Your search found:" << endl;

    for(int i = 0; i < 15; i++)
    {
        temp_make = (*inv_ptr).getMake();
        if(*input_make == *temp_make)
        {
            matched = true;
            (*inv_ptr).print();
            cout << endl;
        }
        inv_ptr++;
    }

    if(!matched)
    {
        cout << "nothing" << endl;
    }

}

bool compareMake(Car *car_1, Car *car_2)
{
    bool in_order = false;
    bool match = true;
    char *make_one = new char[25];
    char *make_two = new char[25];
    make_two = (*car_2).getMake();
    make_one = (*car_1).getMake();


    while(match)
    {
        match = false;

        if(*make_one == '\0' || make_two == '\0')
        {
            in_order = true;
        }
        if(*make_one > *make_two)
        {
            in_order = false;
        }
        else if(*make_one < *make_two)
        {
            in_order = true;
        }
        else if(*make_one == *make_two)
        {
            make_one++;
            make_two++;
            match = true;
        }
    }
    delete [] make_one;
    delete [] make_two;

    return in_order;
}

void swapCar(Car *car_one, Car *car_two)
{
    Car temp;

    temp.copy(*car_one);
    (*car_one).copy(*car_two);
    (*car_two).copy(temp);
}

void strCopy( char *destination, char *source)
{
    char *destination_home, *source_home;

    destination_home = destination;
    source_home = source;

    while( *source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';

    source = source_home;
    destination = destination_home;
}
