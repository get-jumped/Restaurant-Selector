#pragma once
#ifndef FOODPLACES_H
#define FOODPLACES_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Place.h"

using namespace std;

class FoodPlaces{
private:
    Place* head;
    Place* tail;
    FoodPlaces** sitDown;
    FoodPlaces** price;
    FoodPlaces** type;
    FoodPlaces** distance;
    int size;
    int typeSize;
public:
    FoodPlaces();

    int getSize();

    void setUpList();
    bool openFile(ifstream&);
    string trim(string);
    void add(string, bool, string, string, int);
    void add(Place*);
    Place& findNode(int);

    void makeSorted();
    void makeSitDown();
    void makePrice();
    void makeType();
    void makeDistance();

    void print();
    ~FoodPlaces();
};

#endif