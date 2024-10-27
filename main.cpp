#include <iostream>
#include <ctime>
#include "FoodPlaces.h"
#include "MasterList.h"

using namespace std;

void promptUser();
void chooseRandom();
void chooseSitDown();
void choosePrice();
void chooseType();
void chooseDistance();

MasterList list;

//Decide whether to create a master class that holds all the lists in foodPlaces
//or just shove it all in main

int main()
{
    list.createMaster();

    srand(time(0));
    promptUser();

    return 0;
}

void promptUser()
{
    char input;
    char cont;
    do
    {
        cout << "If you would like to choose a random food place input r, s for sitdown," << endl;
        cout << "p for price, t for type, or d for distance." << endl;
        cin >> input;

        if(input == 'r')
        {
            chooseRandom();
        }
        else if(input == 's')
        {
            chooseSitDown();
        }
        else if(input == 'p')
        {
            choosePrice();
        }
        else if(input == 't')
        {
            chooseType();
        }
        else if(input == 'd')
        {
            chooseDistance();
        }
        else
        {
            cout << endl << "You entered an invalid input so no Food Place will be generated" << endl;
        }

        cout << endl << "Would you like to roll another food place: ";
        cin >> cont;
        cout << endl;
    } while (cont == 'Y' || cont == 'y');
    
}

void chooseRandom()
{
    /*
    int nodeIndex = rand() % list.getSize();

    const Place destination = list.findNode(nodeIndex);

    cout << endl << "The random place generated for you to go eat is" << endl;
    destination.print();*/
}

void chooseSitDown()
{
    char choice;
    int index;
    cout << "If you would like to choose a sit down food place enter Y" << endl;
    cout << "otherwise enter N" << endl;
    cin >> choice;

    if(choice == 'Y')
    {
        
    }
}

void choosePrice()
{

}

void chooseType()
{

}

void chooseDistance()
{

}