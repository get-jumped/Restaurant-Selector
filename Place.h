#pragma once
#ifndef PLACE_H
#define PLACE_H

#include<iostream>
#include<iomanip>

using namespace std;

class Place {
private:
    string name;
    bool sitDown;
    string price;
    string type;
    int distance;
    Place * next;

public:
    Place();
    Place(string, bool, string, string, int);
    Place(const Place&);

    Place& operator=(const Place&);

    string getName() const;
    void setName(string);

    bool getSitDown() const;
    void setSitDown(bool);

    string getPrice() const;
    void setPrice(string);

    string getType() const;
    void setType(string);

    int getDistance() const;
    void setDistance(int);

    Place* getNext();
    void setNext(Place*);

    void print() const;
};

#endif