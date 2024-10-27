#include "Place.h"

using namespace std;

Place::Place()
{
    name = "";
    sitDown = false;
    price = "";
    type = "";
    distance == 0;
    next = nullptr;
}

Place::Place(string n, bool s, string p, string t, int d)
{
    name = n;
    sitDown = s;
    price = p;
    type = t;
    distance = d;
    next = nullptr;
}

Place::Place(const Place& right)
{
    cout << "Copy constructor" << endl;
    this->name = right.name;
    this->sitDown = right.sitDown;
    this->price = right.price;
    this->type = right.type;
    this->distance = right.distance;
    this->next = nullptr;
}

Place& Place::operator=(const Place& right)
{
    this->name = right.name;
    this->sitDown = right.sitDown;
    this->price = right.price;
    this->type = right.type;
    this->distance = right.distance;
    this->next = nullptr;

    return *this;
}

string Place::getName() const
{
    return name;
}
    
void Place::setName(string n)
{
    name = n;
}

bool Place::getSitDown() const
{
    return sitDown;
}

void Place::setSitDown(bool s)
{
    sitDown = s;
}

string Place::getPrice() const
{
    return price;
}

void Place::setPrice(string p)
{
    price = p;
}

string Place::getType() const
{
    return type;
}

void Place::setType(string t)
{
    type = t;
}

int Place::getDistance() const
{
    return distance;
}

void Place::setDistance(int d)
{
    distance = d;
}

Place* Place::getNext()
{
    //if modify to not return a const have to change the print method in foodplaces
    return next;
}

void Place::setNext(Place* n)
{
    next = n;
}

void Place::print() const
{
    cout << "Name: " << name << endl;

    cout << boolalpha;
    cout << "Sitdown: " << sitDown << endl;
    cout << noboolalpha;

    cout << "Price: " << price << endl;

    cout << "Type: " << type << endl;

    cout << "Distance: " << distance << endl;

    cout << endl;
}